#include "filefunctions_cw1.h"
#include "filefunctions_cw2.h"
#include "filefunctions_cw3.h"
#include "filefunctions_cw4.h"
#include "input.h"
#include "cw_info.h"
#include "cw1_functions.h"
#include "tests_cw1.h"
#include "cw2_functions.h"
#include "tests_cw2.h"
#include "cw3_functions.h"
#include "tests_cw3.h"
#include "text.h"
#include "tests_cw4.h"


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

void startCW2(void) {
    int user_choice{};
    do {
        std::vector<Worker*> employees{};
        int workerType{}, employees_amount{};
        std::string file_path{};
        UnitTestCW2 tests{};

        infoCW2();
        chooseWorkerType(workerType);

        if (workerType != QUIT) {
            showMainMenuCW2();
            switch (user_choice = getKey(FILE_INPUT, MODUL_TESTS)) {
            case FILE_INPUT:
                file_path = checkFileCW2(workerType);
                employees_amount = (countStringsCW2(file_path) / 5);
                std::cout << "Загружено служащих: " << employees_amount << std::endl;
                getEmployeesFromFile(employees, employees_amount, file_path, workerType);
                break;

            case MANUAL_INPUT:
                std::cout << "Введите число служащих: ";
                employees_amount = getPosInt();
                if (workerType == HOURLY_EMPLOYEE) {
                    fillHourly(employees, employees_amount);
                }
                if (workerType == STATE_EMPLOYEE) {
                    fillState(employees, employees_amount);
                }
                break;

            case MODUL_TESTS:
                tests.runAllTests();
                break;

            case QUIT:
                break;
            }

            while (user_choice != QUIT) {
                showMenuCW2();
                switch (user_choice = getKey(SHOW, SAVECW2)) {
                case SHOW:
                    if (workerType == HOURLY_EMPLOYEE) {
                        showHourly(employees);
                    }
                    if (workerType == STATE_EMPLOYEE) {
                        showState(employees);
                    }
                    break;

                case SAVECW2:
                    saveToFile(employees, workerType);
                    break;

                case QUIT:
                    break;
                }
            }
        }
        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = getKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    } 
    while (user_choice != NO);
}

void startCW3(void) {
    int user_choice{};
    do {
        std::vector<ISort*> sorts{};
        std::vector<Matrix*> matrices{};

        BubbleSort* bubble_sort = new BubbleSort;
        sorts.push_back(bubble_sort);

        SelectionSort* selection_sort = new SelectionSort;
        sorts.push_back(selection_sort);

        InsertionSort* insertion_sort = new InsertionSort;
        sorts.push_back(insertion_sort);

        ShellSort* shell_sort = new ShellSort;
        sorts.push_back(shell_sort);

        QuickSort* quick_sort = new QuickSort;
        sorts.push_back(quick_sort);

        std::vector<std::vector<int>> matrix{}, rows_to_save{}, columns_to_save{};
        int rows{}, columns{};
        std::string file_path{};
        UnitTestCW3 tests{};

        infoCW3();
        showMainMenuCW3();

        switch (user_choice = getKey(FILE_INPUT, RANDOM_INPUT)) {
            case FILE_INPUT:
                file_path = checkFileCW3();
                getMatrixFromFile(matrix, rows, columns, file_path);
                break;

            case MANUAL_INPUT:
                std::cout << "Введите количество строк: ";
                rows = getPosInt();
                std::cout << "Введите количество столбцов: ";
                columns = getPosInt();

                fillMatrix(matrix, rows, columns);
                break;

            case MODUL_TESTS:
                tests.runAllTests();
                break;

            case RANDOM_INPUT:
                std::cout << "Введите количество строк: ";
                rows = getPosInt();
                std::cout << "Введите количество столбцов: ";
                columns = getPosInt();

                fillMatrixRandomly(matrix, rows, columns);
                break;

            case QUIT:
                break;
        }

        goSort(matrix, rows, columns, sorts, matrices);

        while (user_choice != QUIT && user_choice != MODUL_TESTS) {
            showMenuCW3();

            switch (user_choice = getKey(SHOW, SAVECW3)) {
                case SHOW:
                    showResults(matrix, rows, columns, sorts, matrices);
                    break;

                case SAVECW3:
                    saveToFile(sorts, matrices, matrix, rows, columns);
                    break;

                case QUIT:
                    break;
            }
        }

        for (std::vector<Matrix*>::iterator it = matrices.begin(); it != matrices.end(); it++) {
            delete* it;
        }
        delete bubble_sort;
        delete selection_sort;
        delete insertion_sort;
        delete shell_sort;
        delete quick_sort;

        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = getKey(YES, NO);
        if (user_choice == QUIT) {
            exit(EXIT_SUCCESS);
        }
    } 
    while (user_choice != NO);
}

void startCW4(void) {
    int user_choice{};
    do {
        std::string file_path{};
        bool isLoopMenu = false;
        UnitTestCW4 tests{};
        Text my_text;

        infoCW4();
        showMainMenuCW4();

        switch (user_choice = getKey(FILE_INPUT, MODUL_TESTS)) {
            case FILE_INPUT:
                isLoopMenu = true;
                std::cout << "Введите имя файла для загрузки: ";
                std::cin.seekg(std::cin.end);
                getLine(std::cin, file_path, WITH_DIGITS, MANUAL_INPUT);
                my_text.load(file_path);
                break;

            case MANUAL_INPUT:
                isLoopMenu = true;
                my_text.input();
                break;

            case MODUL_TESTS:
                tests.runAllTests();
                break;

            case QUIT:
                break;
        }

        std::vector<std::string> originalText = my_text.get_data();

        while (isLoopMenu) {
            showMenuCW4();
            switch (user_choice = getKey(SHOW_ORIGINAL, SAVE_ORIGINAL)) {
                case SHOW_ORIGINAL:
                    std::cout << "Оригинальный текст:" << std::endl;
                    my_text.print();
                    break;

                case SHOW_CONTEXTS:
                    std::cout << "Возможные перестановки:" << std::endl << std::endl;
                    my_text.analyze();
                    break;

                case SAVE_ORIGINAL:
                    saveToFile(originalText);
                    break;

                case QUIT:
                    isLoopMenu = false;
                    break;
            }
        }

        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = getKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    }
    while (user_choice != NO);
}
