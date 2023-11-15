#include <iostream>
#include <limits>
#include <cctype>
#include "input.h"
#include "wchar.h"
#include <iomanip>
#include <vector>

template<typename T>
T getT(void) {
    T input{};

    std::cin >> input;
    do {
        if (std::cin.fail()) {
            std::cout << "Неверный ввод, повторите попытку!" << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cin >> input;
        }
    } 
    while (std::cin.fail());
    std::cin.ignore(INT_MAX, '\n');

    return input;
}



int getKey(int key_min, int key_max) {
    int key = 0;

    do {
        key = _getch();
        if (key == KEY_ESC)
            return key;
    } 
    while ((key < key_min) || (key > key_max));

    return key;
}

template<typename T>
T getPosT(void) {
    T num = 0;
    do {
        num = getT<T>();
        if (num < 0) {
            std::cout << "Взято значение по модулю!" << std::endl;
            num = abs(num);
        }
        if (num > DBL_WRONG) {
            std::cout << "Вводимое значение должно быть не больше чем " << std::fixed << DBL_WRONG << std::endl;
            continue;
        }
        else if (num == 0)
            std::cout << "Вводимое значение не должно быть равно 0. Повторите попытку!" << std::endl;
    } 
    while (num <= 0 || num > DBL_WRONG);
    return num;
}

int getPosInt(void) {
    return getPosT<int>();
}

int getInt(void) {
    return getT<int>();
}

double getDouble(void) {
    return getT<double>();
}

double getPosDouble(void) {
    return getPosT<double>();
}

bool getBool(void) {
    return getT<bool>();
}

int getRandInt(int lowBound, int upBound) {
    return (rand() % (upBound - lowBound) + lowBound);
}



std::string getLine(std::istream& _Input, std::string& line, int num_exists, int isInput) {
    bool validInput = true;
    do {
        std::getline(_Input, line);
        do {
            if (std::cin.fail()) {
                _Input.clear();
                _Input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Некорректный ввод, повторите попытку!" << std::endl;
                std::getline(_Input, line);
                if (isInput == FILE_INPUT)
                    validInput = false;
            }
        } 
        while (std::cin.fail() && isInput != FILE_INPUT);

        if (isInput == FILE_INPUT && !validInput)
            break;

        if (num_exists != CW4_INPUT) {
            if (line.empty() && isInput != FILE_INPUT) {
                std::cout << "Вводимое значение не должно быть пустым!" << std::endl;
                validInput = false;
                continue;
            }

            int space_position(0);
            int character_position(0);
            for (const unsigned char c : line) { //checking that a string does not start with spaces  
                if (!iswprint(c)) {
                    validInput = false;
                    std::cout << "Вводимое значение не должно содержать непечатные символы!" << std::endl;
                    break;
                }
                if (c == ' ')
                    space_position++;
                if (c != ' ')
                    character_position++;
                if (space_position > character_position) {
                    validInput = false;
                    std::cout << "Вводимое значение не должно начинаться с пробела!" << std::endl;
                    break;
                }
                else
                    validInput = true;
            }
        }

        if (num_exists == WITHOUT_DIGITS) {
            for (const unsigned char c : line) {
                if (isdigit(c)) {
                    validInput = false;
                    std::cout << "Вводимое значение не должно содержать цифр!" << std::endl;
                    break;
                }
            }
        }  

        if (num_exists == ONLY_DIGITS) {
            for (const unsigned char c : line) {
                if (!isdigit(c)) {
                    validInput = false;
                    std::cout << "Вводимое значение может содержать только цифры!" << std::endl;
                    break;
                }
            }
        }

        if (num_exists == ALMOST_ALL_DIGITS) {
            for (const unsigned char c : line) {
                if (!isdigit(c) && !((c == '/') || (c == ' ') || (c == '+') || (c == '-'))) {
                    validInput = false;
                    std::cout << "Вводимое значение может содержать только цифры и символы '+ - /' !" << std::endl;
                    break;
                }
            }
        }
    } 
    while (!validInput && isInput == MANUAL_INPUT);

    if (!validInput && isInput == FILE_INPUT) {
        line = "";
        return line;
    }

    return line;
}
