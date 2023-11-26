#include <filesystem>
#include <fstream>
#include "employees.h"
#include "input.h"


bool isDataCorrectCW2(std::ifstream& file, int workerType) { //The function checks if the data loaded from the file is valid
    std::string test_string{};
    int test_int{};
    double test_double{};

    while (!file.eof()) {
        getLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); // name
        if (test_string.empty()) {
            std::cout << "������ ���������� ���!" << std::endl;
            return false;
        }

        file >> test_int; // age
        if (test_int > INT_MAX) {
            std::cout << "������ ���������� ��������, ��������� ������������ ��������!" << std::endl;
            return false;
        }
        if (test_int <= 0) {
            std::cout << "������ ���������� ��������, �������� �� ����� ���� ������������� ��� ������ 0!" << std::endl;
            return false;
        }
        if (file.fail()) {
            std::cout << "������ ���������� ��������!" << std::endl;
            return false;
        };
        file.get();

        getLine(file, test_string, WITH_DIGITS, FILE_INPUT); // position
        if (test_string.empty()) {
            std::cout << test_string << std::endl;
            std::cout << "������ ���������� ���������!" << std::endl;
            return false;
        }

        if (workerType == HOURLY_EMPLOYEE) {
            file >> test_int; // workTime
            if (test_int > INT_MAX) {
                std::cout << "������ ���������� ���������� ������������ �����, ��������� ������������ ��������!" << std::endl;
                return false;
            }
            if (test_int <= 0) {
                std::cout << "������ ���������� ���������� ������������ �����, �������� �� ����� ���� ������������� ��� ������ 0!" << std::endl;
                return false;
            }
            if (file.fail()) {
                std::cout << "������ ���������� ���������� ������������ �����!" << std::endl;
                return false;
            };
            file.get();
        }
        if (workerType == STATE_EMPLOYEE) {
            file >> test_int; // workExperience
            if (test_int > INT_MAX) {
                std::cout << "������ ���������� ����� ������, ��������� ������������ ��������!" << std::endl;
                return false;
            }
            if (test_int <= 0) {
                std::cout << "������ ���������� ����� ������, �������� �� ����� ���� ������������� ��� ������ 0!" << std::endl;
                return false;
            }
            if (file.fail()) {
                std::cout << "������ ���������� ����� ������!" << std::endl;
                return false;
            };
            file.get();
        }

        file >> test_double; //salary
        if (test_double > DBL_WRONG) {
            std::cout << "������ ���������� ��������, ��������� ������������ ��������!" << std::endl;
            return false;
        }
        if (test_double <= 0) {
            std::cout << "������ ���������� ��������, ��� �� ����� ���� ����� 0 ��� ���� �������������!" << std::endl;
            return false;
        }
        if (file.fail()) {
            std::cout << "������ ���������� ��������!" << std::endl;
            return false;
        };
        file.get();
    }

    file.seekg(0, std::ios::beg);  //If everything went well, then return the pointer to the beginning of the file

    return true;
}

std::string checkFileCW2(int workerType) {
    std::error_code error{};

    std::string path{};
    bool isLoaded = false;

    std::ifstream file;

    do {
        std::cout << "������� ���� � �����: ";
        getLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);

        if (!std::ifstream(path)) {
            std::cout << "��������� ���� �� ������!" << std::endl;
            continue;
        }

        if (!std::filesystem::is_regular_file(path, error)) {
            std::cout << "������, ������������ ����� �����!" << std::endl;
            continue;
        }

        file.open(path);

        if (!file) {
            std::cout << "������ �������� �����!" << std::endl;
            file.close();
        }
        else if (!isDataCorrectCW2(file, workerType)) {
            std::cout << "������ �����������!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } 
    while (!isLoaded);

    std::cout << "���� ������!" << std::endl;
    file.close();

    return path;
}

void getEmployeesFromFile(std::vector<Worker*>& employees, int amount, std::string path, int workerType) {
    std::ifstream file(path);

    if (workerType == HOURLY_EMPLOYEE) {
        for (int i = 0; i < amount && !file.eof(); i++) {
            HourlyEmployee* new_employee = new HourlyEmployee;
            new_employee->setName(file);
            new_employee->setAge(file);
            new_employee->setPosition(file);
            new_employee->setWorkTime(file);
            new_employee->setSalary(file);

            employees.push_back(new_employee);
        }
    }
    if (workerType == STATE_EMPLOYEE) {
        for (int i = 0; i < amount && !file.eof(); i++) {
            StateEmployee* new_employee = new StateEmployee;
            new_employee->setName(file);
            new_employee->setAge(file);
            new_employee->setPosition(file);
            new_employee->setWorkExperience(file);
            new_employee->setSalary(file);

            employees.push_back(new_employee);
        }
    }

    std::cout << "������ ��������!" << std::endl;

    file.close();
}

void saveToFile(std::vector<Worker*>& employees, int workerType) {
    std::ofstream file;
    std::string path{};
    bool isOpened = false;

    std::error_code error{};

    do {
        std::cout
            << "������� ���� � ����� ��� ����������. "
            << "���� ������� ������ ��� � ���������� �����, ����������� ���� ����� �������� ���� � ��������� ���� ���������." << std::endl;
        std::getline(std::cin, path);

        if (std::ifstream(path)) {
            if (!std::filesystem::is_regular_file(path, error)) {
                std::cout << "������, ������������ ����� �����!" << std::endl;
                continue;
            }

            std::cout
                << "������ ���� ��� ����������!." << std::endl
                << "1 - ������������." << std::endl
                << "2 - ������� ������." << std::endl;

            if (getKey(YES, NO) == NO)
                continue;
        }

        file.open(path, std::ios::trunc);

        if (!file)
            std::cout << "������ �������� �����!" << std::endl;
        else
            isOpened = true;
    } 
    while (!isOpened);

    std::string outputName{}, outputPosition{};
    int outputAge{}, outputWorkTime{}, outputWorkExperience{};
    double outputSalary{};
    
    for (std::vector<Worker*>::iterator it = employees.begin(); it != employees.end(); it++) {
        outputName = (*it)->getName();
        outputAge = (*it)->getAge();
        outputPosition = (*it)->getPosition();
        if (workerType == HOURLY_EMPLOYEE) {
            outputWorkTime = dynamic_cast<HourlyEmployee*>(*it)->getWorkTime();
        }
        if (workerType == STATE_EMPLOYEE) {
            outputWorkExperience = dynamic_cast<StateEmployee*>(*it)->getWorkExperience();
        }
        outputSalary = (*it)->getSalary();


        if (it != employees.begin())
            file << std::endl;
        file << outputName << std::endl;
        file << outputAge << std::endl;
        file << outputPosition << std::endl;
        if (workerType == HOURLY_EMPLOYEE) {
            file << outputWorkTime << std::endl;
        }
        if (workerType == STATE_EMPLOYEE) {
            file << outputWorkExperience << std::endl;
        }
        file << outputSalary;

    }
    std::cout << "������� ��������� � " << path << std::endl;
}

int countStringsCW2(std::string path) {
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