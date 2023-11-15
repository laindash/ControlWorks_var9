#include <filesystem>
#include <fstream>
#include "bus.h"
#include "input.h"

bool isDataCorrectCW1(std::ifstream& file) { //The function checks if the data loaded from the file is valid
    std::string test_string{};
    int test_int{};

    if (!file.eof()) {
        getLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //driverInfo
        if (test_string.empty()) {
            std::cout << "Ошибка считывания данных водителя!" << std::endl;
            return false;
        }

        getLine(file, test_string, WITH_DIGITS, FILE_INPUT); //busNumber
        if (test_string.empty()) {
            std::cout << "Ошибка считывания номера автобуса!" << std::endl;
            return false;
        }

        getLine(file, test_string, WITH_DIGITS, FILE_INPUT); //routeNumber
        if (test_string.empty()) {
            std::cout << "Ошибка считывания номера маршрута!" << std::endl;
            return false;
        }

        getLine(file, test_string, WITH_DIGITS, FILE_INPUT); //brand
        if (test_string.empty())  {
            std::cout << "Ошибка считывания марки автобуса!" << std::endl;
            return false;
        }

        file >> test_int; //startYear
        if (test_int > INT_MAX || test_int > 2023) {
            std::cout << "Ошибка считывания года начала эксплуатации, превышено максимальное значение!" << std::endl;
            return false;
        }
        if (file.fail()) {
            std::cout << "Ошибка считывания года начала эксплуатации!" << std::endl;
            return false;
        };
        
        file >> test_int; //mileage
        if (test_int > INT_MAX) {
            std::cout << "Ошибка считывания пробега, превышено максимальное значение!" << std::endl;
            return false;
        }
        if (file.fail()) {
            std::cout << "Ошибка считывания пробега!" << std::endl;
            return false;
        };

        while (file.get() != EOF); //to clean up possible residual information
    }
    else
        std::cout << "Файл пуст!" << std::endl;

    file.seekg(0, std::ios::beg);  //If everything went well, then return the pointer to the beginning of the file
    return true;
}

std::string checkFile() {
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
        else if (!isDataCorrectCW1(file)) {
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

void getListFromFile(Bus* List, int amount, std::string path = checkFile()) {
    std::ifstream file(path);

    for (int i = 0; i < amount && !file.eof(); i++) {
        if (List[i].isEmpty()) {
            List[i].setDriverInfo(file);
            List[i].setBusNumber(file);
            List[i].setRouteNumber(file);
            List[i].setBrand(file);
            List[i].setStartYear(file);
            List[i].setMileage(file);
        }
    }

    std::cout << "Список загружен!" << std::endl;

    file.close();
}

void saveToFile(Bus* List, int amount) {
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

    std::string
        outputDriverInfo{},
        outputBusNumber{}, // example: A056EB
        outputRouteNumber{}, // example: 68A
        outputBrand{};
    int
        outputStartYear{},
        outputMileage{};

    for (int i = 0; i < amount && !List[i].isEmpty(); i++) {
        outputDriverInfo = List[i].getDriverInfo();
        outputBusNumber = List[i].getBusNumber();
        outputRouteNumber = List[i].getRouteNumber();
        outputBrand = List[i].getBrand();
        outputStartYear = List[i].getStartYear();
        outputMileage = List[i].getStartYear();

        if (i != 0) //separator between different buses
            file << std::endl;

        file
            << outputDriverInfo << std::endl
            << outputBusNumber << std::endl
            << outputRouteNumber << std::endl
            << outputBrand << std::endl
            << outputStartYear << std::endl
            << outputMileage;
    }
    std::cout << "Успешно сохранено в " << path << std::endl;
}

int countStrings(std::string path) {
    int stringsAmount{};

    std::ifstream file;
    file.open(path);
    std::string tmp{};

    while (!file.eof()) {
        std::getline(file, tmp);
        stringsAmount++;
    }
    return stringsAmount;
}