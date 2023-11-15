#include "filefunctions_cw1.h"
/*#include "filefunctions_cw2.h"
#include "filefunctions_cw3.h"
#include "filefunctions_cw4.h"
*/
#include "input.h"
#include "cw_info.h"
#include "cw1_functions.h"
#include "tests_cw1.h"

/*
#include "cw2_functions.h"
#include "tests_cw2.h"
#include "cw3_functions.h"
#include "tests_cw3.h"
#include "cw4_functions.h"
#include "tests_cw4.h"
*/


void startCW1(void) {
    int user_choice{};
    do {
        int buses_amount{};
        std::string file_path{};
        Bus* buses = nullptr;
        Bus* ansBuses = nullptr;
        UnitTestCW1 tests{};

        infoCW1();
        showMainMenuCW1();
        switch (user_choice = getKey(FILE_INPUT, MODUL_TESTS)) {
            case FILE_INPUT:
            {
                do {
                    file_path = checkFile();
                    buses_amount = (countStrings(file_path) / 6); //6 - fields of class Bus

                    std::cout << "Загружено автобусов: " << buses_amount << std::endl;
                    if (allocateArray(buses, buses_amount))
                        buses = new Bus[buses_amount];
                    else
                        std::cout << "Произошла ошибка. попробуйте ещё раз!" << std::endl;
                }
                while (!allocateArray(buses, buses_amount));

                getListFromFile(buses, buses_amount, file_path);
                break;
            }

            case MANUAL_INPUT:
            {
                do {
                    std::cout << "Введите число автобусов: ";
                    buses_amount = getPosInt();
                    if (allocateArray(buses, buses_amount))
                        buses = new Bus[buses_amount];
                    else
                        std::cout << "Произошла ошибка. попробуйте ещё раз!" << std::endl;
                }
                while (!allocateArray(buses, buses_amount));

                fillBuses(buses, buses_amount);
                break;
            }

            case MODUL_TESTS:
                tests.runAllTests();
                break;

            case QUIT: 
                break;
        }

        while (user_choice != QUIT) {
            showMenuCW1();
            switch (user_choice = getKey(SEARCH_BY_ROUTE_NUMBER, SAVECW1))
            {
            case SEARCH_BY_ROUTE_NUMBER:
                searchByRouteNumber(buses, ansBuses, buses_amount, MANUAL_INPUT);
                break;

            case SEARCH_BY_START_YEAR:
                searchByStartYear(buses, ansBuses, buses_amount, MANUAL_INPUT);
                break;

            case SEARCH_BY_MILEAGE:
                searchByMileage(buses, ansBuses, buses_amount, MANUAL_INPUT);
                break;
            
            case SHOW_ALL:
                showBuses(buses, buses_amount);
                break;

            case SAVECW1:
                if (!isListEmpty(buses, buses_amount))
                    saveToFile(buses, buses_amount);
                else
                    std::cout << "Список пуст!" << std::endl;
                break;

            case QUIT:
                break;
            }
        }
        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = getKey(YES, NO);
        if (user_choice == QUIT) {
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
        if (buses != nullptr) {
            delete[] buses;
            buses = nullptr;
        }
        if (ansBuses != nullptr) {
            delete[] ansBuses;
            ansBuses = nullptr;
        }
    }
    while (user_choice != NO);
}

void startCW2(void)
{
    int user_choice{};
    do
    {
        
    } 
    while (user_choice != NO);
}

void startCW3(void)
{
    int user_choice{};
    do
    {
       
    } while (user_choice != NO);
}

void startCW4(void)
{
    int user_choice{};
    do
    {
        
    }
    while (user_choice != NO);
}
