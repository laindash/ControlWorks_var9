#include "tests_cw2.h"
#include "employees.h"
#include "cw2_functions.h"
#include "filefunctions_cw2.h"
#include <filesystem>
#include <fstream>


bool UnitTestCW2::testCaseOne() { // boot from valid file
	std::string test_file_path = "test1cw2.txt";
	int workerType = HOURLY_EMPLOYEE;

	if (!std::ifstream(test_file_path)) {
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}

	std::ifstream file(test_file_path);
	if (!isDataCorrectCW2(file, workerType)) {
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: данные корректны " << std::endl
			<< "Получено: данные некорректны" << std::endl;
		return false;
	}
	file.close();
	return true;
}

bool UnitTestCW2::testCaseTwo() { // check file where salary = 0
	std::string test_file_path = "test2cw2.txt";
	int workerType = STATE_EMPLOYEE;

	if (!std::ifstream(test_file_path)) {
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}

	std::ifstream file(test_file_path);
	if (isDataCorrectCW2(file, workerType)) {
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << "данные некорректны " << std::endl
			<< "Получено: " << "данные корректны" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}

bool UnitTestCW2::testCaseThree() { // check file where name is digit
	std::string test_file_path = "test3cw2.txt";
	int workerType = STATE_EMPLOYEE;

	if (!std::ifstream(test_file_path)) {
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}
	std::ifstream file(test_file_path);
	if (isDataCorrectCW2(file, workerType)) {
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << "данные некорректны " << std::endl
			<< "Получено: " << "данные корректны" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}

bool UnitTestCW2::testCaseFour() { // check file where age is not a digit
	std::string test_file_path = "test4cw2.txt";
	int workerType = STATE_EMPLOYEE; 

	if (!std::ifstream(test_file_path)) {
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}

	std::ifstream file(test_file_path);
	if (isDataCorrectCW2(file, workerType)) {
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: " << "данные некорректны " << std::endl
			<< "Получено: " << "данные корректны" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}

bool UnitTestCW2::testCaseFive() { // check valid file
	std::string test_file_path = "test5cw2.txt";
	int workerType = HOURLY_EMPLOYEE;

	if (!std::ifstream(test_file_path)) {
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: файл открыт!" << std::endl
			<< "Получено: файл не найден!" << std::endl;
		return false;
	}

	std::ifstream file(test_file_path);
	if (!isDataCorrectCW2(file, workerType)) {
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << "данные корректны " << std::endl
			<< "Получено: " << "данные некорректны" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}

void UnitTestCW2::runAllTests() {
	UnitTestCW2 test{};
	if (test.testCaseOne() && test.testCaseTwo() && test.testCaseThree() && test.testCaseFour() && test.testCaseFive())
		std::cout << "Все модульные тесты пройдены!" << std::endl;
	else
		std::cout << "Модульные тесты не пройдены." << std::endl;
}
