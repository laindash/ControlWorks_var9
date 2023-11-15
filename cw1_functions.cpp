#include "input.h"
#include "filefunctions_cw1.h"

bool allocateArray(Bus* buses , int amount) { // checking the possibility of adding a bus 
    if (amount == 0) {
        std::cout << "������ ��������� ������: ������ �������� ������ ��� 0 ���������" << std::endl; 
        return false;
    }

    try {
        buses = new Bus[amount];
    }
    catch (const std::bad_alloc& error) {
        std::cout
            << "������ ��������� ������: " << error.what() << std::endl
            << "���������� �������� ���������� ���������" << std::endl;
        if (buses != nullptr)
            delete[] buses;
        return false;
    }
    if (buses != nullptr)
        delete[] buses;
    return true;
}

void showBuses(Bus* buses, int amount) {
    int id = 1;
    for (int i = 0; i < amount; i++, id++) {
        std::cout << "������� # " << id << std::endl;
        buses[i].showBus();
    }
}

void fillBuses(Bus* buses, int amount) {
    std::cout << std::endl;
    int buses_id = 1;
    for (int i = 0; i < amount; i++, buses_id++) {
        if (!buses[i].isEmpty())
            continue;
        std::cout << "��������� ���������� �� �������� # " << buses_id << "." << std::endl;
        buses[i].setDriverInfo();
        buses[i].setBusNumber();
        buses[i].setRouteNumber();
        buses[i].setBrand();
        buses[i].setStartYear();
        buses[i].setMileage();
        std::cout << std::endl;
    }
}

void searchByRouteNumber(Bus* buses, Bus* ansBuses, int amount, int isTest) {
    bool isThereAtLeastOne = false;
    std::string test_value = "68A";
    std::string routeNumber{};
    int counter(0);
    if (isTest == MANUAL_INPUT) {
        std::cout << "������� �������, �� �������� ���������� ���������� �����." << std::endl;
        getLine(std::cin, routeNumber, WITH_DIGITS, MANUAL_INPUT);
    }
    for (int i = 0; i < amount; i++) {
        if (buses[i].getRouteNumber() == routeNumber) {
            isThereAtLeastOne = true;
            buses[i].showBus();
            counter++;
        }
    }
    if (!isThereAtLeastOne)
        std::cout << "��������� � �������� ��������� ���!" << std::endl;
    if (isThereAtLeastOne && isTest == MANUAL_INPUT) {
        std::cout << "�������� ��������� � ����?" << std::endl;
        std::cout << "1 - ��, 2 - ���. ESC - ����� �� ���������." << std::endl;
        int user_choice = getKey(YES, NO);
        if (user_choice == YES) {
            Bus* listToSave = new Bus[counter];

            for (int i = 0, j = 0; i < amount && j < counter; i++)
                if (buses[i].getRouteNumber() == routeNumber)
                    listToSave[j++] = buses[i];

            saveToFile(listToSave, counter);
            if (listToSave != nullptr) {
                delete[] listToSave;
                listToSave = nullptr;
            }
        }
        else if (user_choice == QUIT) {
            if (buses != nullptr) {
                delete[] buses;
                buses = nullptr;
            }
            if (ansBuses != nullptr) {
                delete[] ansBuses;
                ansBuses = nullptr;
            }
            exit(EXIT_SUCCESS);
        }
    }
    if (isTest == MODUL_TESTS)
    {
        for (int i = 0, j = 0; i < amount && j < counter; i++)
            if (buses[i].getRouteNumber() == test_value)
                ansBuses[j++] = buses[i];
    }
}

void searchByStartYear(Bus* buses, Bus* ansBuses, int amount, int isTest) {
    const int CURRENT_YEAR = 2023;
    int counter(0);

    bool isThereAtLeastOne = false;
    std::cout << "��������, ������� ��������������� ������ 10 ���: " << std::endl;
    for (int i = 0; i < amount; i++) {
        if (CURRENT_YEAR - buses[i].getStartYear() > 10) {
            isThereAtLeastOne = true;
            buses[i].showBus();
            counter++;
        }
    }
    if (!isThereAtLeastOne)
        std::cout << "���������, ������� ��������������� ������ 10 ��� ���!" << std::endl;
    if (isThereAtLeastOne && isTest == MANUAL_INPUT) {
        std::cout << "�������� ��������� � ����?" << std::endl;
        std::cout << "1 - ��, 2 - ���. ESC - ����� �� ���������." << std::endl;
        int user_choice = getKey(YES, NO);
        if (user_choice == YES) {
            Bus* listToSave = new Bus[counter];

            for (int i = 0, j = 0; i < amount && j < counter; i++)
                if (CURRENT_YEAR - buses[i].getStartYear() > 10)
                    listToSave[j++] = buses[i];

            saveToFile(listToSave, counter);
            if (listToSave != nullptr) {
                delete[] listToSave;
                listToSave = nullptr;
            }
        }
        else if (user_choice == QUIT) {
            if (buses != nullptr) {
                delete[] buses;
                buses = nullptr;
            }
            if (ansBuses != nullptr) {
                delete[] ansBuses;
                ansBuses = nullptr;
            }
            exit(EXIT_SUCCESS);
        }
    }
    if (isTest == MODUL_TESTS) {
        for (int i = 0, j = 0; i < amount && j < counter; i++)
            if (CURRENT_YEAR - buses[i].getStartYear() > 10)
                ansBuses[j++] = buses[i];
    }
}

void searchByMileage(Bus* buses, Bus* ansBuses, int amount, int isTest) {
    const int MILEAGE = 10000;
    int counter(0);
    bool isThereAtLeastOne = false;

    std::cout << "��������, ������ � ������� ������ 10 000 ��: " << std::endl;
    for (int i = 0; i < amount; i++) {
        if (buses[i].getMileage() > MILEAGE) {
            isThereAtLeastOne = true;
            buses[i].showBus();
            counter++;
        }
    }
    if (!isThereAtLeastOne)
        std::cout << "���������, ������ � ������� ������ 10 000 �� ���!" << std::endl;
    if (isThereAtLeastOne && isTest == MANUAL_INPUT) {
        std::cout << "�������� ��������� � ����?" << std::endl;
        std::cout << "1 - ��, 2 - ���. ESC - ����� �� ���������." << std::endl;
        int user_choice = getKey(YES, NO);
        if (user_choice == YES) {
            Bus* listToSave = new Bus[counter];

            for (int i = 0, j = 0; i < amount && j < counter; i++)
                if (buses[i].getMileage() > MILEAGE)
                    listToSave[j++] = buses[i];

            saveToFile(listToSave, counter);
            if (listToSave != nullptr) {
                delete[] listToSave;
                listToSave = nullptr;
            }
        }
        else if (user_choice == QUIT) {
            if (buses != nullptr) {
                delete[] buses;
                buses = nullptr;
            }
            if (ansBuses != nullptr) {
                delete[] ansBuses;
                ansBuses = nullptr;
            }
            exit(EXIT_SUCCESS);
        }
    }
    if (isTest == MODUL_TESTS) {
        for (int i = 0, j = 0; i < amount && j < counter; i++)
            if (buses[i].getMileage() > MILEAGE)
                ansBuses[j++] = buses[i];
    }
}

bool isListEmpty(Bus* buses, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        if (!buses[i].isEmpty())
            return false;
    }
    return true;
}

