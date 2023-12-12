#include <filesystem>
#include <fstream>
#include "input.h"
#include <iostream>
//#include "cw4_functions.h"


bool isDataCorrectCW4(std::ifstream& file) { //The function checks if the data loaded from the file is valid
    std::string test_string{};
    if (file.eof()) {
        std::cout << "Файл пуст!";
        return false;
    }

    return true;
}

std::string checkFileCW4() {
    std::error_code error{};

    std::string path{};
    bool isLoaded = false;

    std::ifstream file;

    do {
        std::cout << "Введите путь к файлу: ";
        getLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);

        if (!std::ifstream(path)) {
            std::cout << "Указанный файл не найден!" << std::endl;
            continue;
        }

        if (!std::filesystem::is_regular_file(path, error)) {
            std::cout << "Ошибка, недопустимый адрес файла!" << std::endl;
            continue;
        }

        file.open(path);

        if (!file) {
            std::cout << "Ошибка открытия файла!" << std::endl;
            file.close();
        }
        else if (!isDataCorrectCW4(file)) {
            std::cout << "Данные некорректны!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } 
    while (!isLoaded);

    std::cout << "Файл открыт!" << std::endl;
    file.close();

    return path;
}

void getTextFromFile(std::string& text, std::string& path) {
    std::ifstream file(path);
    std::string input{};

    while (!file.eof()) {
        getLine(file, input, CW4_INPUT, FILE_INPUT);
        text += (input);
        if (!file.eof())
            text += '\n';
    }

    std::cout << "Текст загружен!" << std::endl;
    file.close();
}

void saveToFile(const std::vector<std::string>& text) {
    std::ofstream file;
    std::string path{};
    bool isOpened = false;
    std::error_code error{};
    do {
        std::cout
            << "Введите путь к файлу для сохранения. "
            << "Если указать только имя и расширение файла, стандартным путём будет являться путь к исходному коду программы." << std::endl;
        getLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);
        if (std::ifstream(path)) {
            if (!std::filesystem::is_regular_file(path, error)) {
                std::cout << "Ошибка, недопустимый адрес файла!" << std::endl;
                continue;
            }

            std::cout
                << "Данный файл уже существует!." << std::endl
                << "1 - Перезаписать." << std::endl
                << "2 - Выбрать другой." << std::endl;

            if (getKey(YES, NO) == NO)
                continue;
        }

        file.open(path, std::ios::trunc);

        if (!file)
            std::cout << "Ошибка открытия файла!" << std::endl;
        else
            isOpened = true;
    } 
    while (!isOpened);

    for (size_t i = 0; i < text.size(); i++)
        file << text[i] << " ";
    file << std::endl;


    std::cout << "Успешно сохранено в " << path << std::endl;
}