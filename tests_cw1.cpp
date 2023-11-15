#include "tests_cw1.h"
#include "bus.h"
#include "cw1_functions.h"
#include "filefunctions_cw1.h"
#include "input.h"
#include <fstream>
#include <filesystem>
#include <iostream>

bool UnitTestCW1::testCaseOne() { // test search by route number
	const int amount(3); // amount of buses in file
	std::string routeNumber{};
	const std::string ansRouteNumber = "68A";
	const int test_amount(2); // amount of buses with the required route number
	Bus* buses = nullptr;
	Bus* ansBuses = nullptr;
	std::string test_file_path = "test1cw1.txt";

	if (!std::ifstream(test_file_path)) {
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������: ���� ������!" << std::endl
			<< "��������: ���� �� ������!" << std::endl;
		return false;
	}

	if (!allocateArray(buses, amount)) {
		std::cout << "���� 1 ��������. ������ ��������� ������!" << std::endl;
		return false;
	}
	else
		buses = new Bus[amount];

	ansBuses = new Bus[test_amount];
	getListFromFile(buses, amount, test_file_path);
	searchByRouteNumber(buses, ansBuses, amount, MODUL_TESTS);

	routeNumber = ansBuses[0].getRouteNumber();
	if (routeNumber != ansRouteNumber) {
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������: " << "�������: " << ansRouteNumber << std::endl
			<< "��������: " << routeNumber << std::endl;

		if (buses != nullptr) {
			delete[] buses;
			buses = nullptr;
		}

		if (ansBuses != nullptr) {
			delete[] ansBuses;
			ansBuses = nullptr;
		}

		return false;
	}

	routeNumber = ansBuses[1].getRouteNumber();
	if (routeNumber != ansRouteNumber) {
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������: " << "�������: " << ansRouteNumber << std::endl
			<< "��������: " << routeNumber << std::endl;

		if (buses != nullptr) {
			delete[] buses;
			buses = nullptr;
		}

		if (ansBuses != nullptr) {
			delete[] ansBuses;
			ansBuses = nullptr;
		}

		return false;
	}

	if (buses != nullptr) {
		delete[] buses;
		buses = nullptr;
	}

	if (ansBuses != nullptr) {
		delete[] ansBuses;
		ansBuses = nullptr;
	}
	return true;
}

bool UnitTestCW1::testCaseTwo() { // test search by start year > 10
	const int CURRENT_YEAR = 2023;
	const int amount(3);
	const int test_amount(2);
	Bus* ansBuses = nullptr;
	Bus* buses = nullptr;
	std::string test_file_path = "test2cw1.txt";

	if (!std::ifstream(test_file_path)) {
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: ���� ������!" << std::endl
			<< "��������: ���� �� ������!" << std::endl;
		return false;
	}

	if (!allocateArray(buses, amount)) {
		std::cout << "���� 2 ��������. ������ ��������� ������!" << std::endl;
		return false;
	}
	else
		buses = new Bus[amount];

	ansBuses = new Bus[test_amount];
	getListFromFile(buses, amount, test_file_path);
	searchByStartYear(buses, ansBuses, amount, MODUL_TESTS);

	int counter(0);
	for (int i = 0; i < amount; i++)
		if (CURRENT_YEAR - ansBuses[i].getStartYear() > 10)
			counter++;
	if (counter > test_amount) {
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << "���������� ���������: " << test_amount << std::endl
			<< "��������: " << counter << std::endl;

		if (buses != nullptr) {
			delete[] buses;
			buses = nullptr;
		}

		if (ansBuses != nullptr) {
			delete[] ansBuses;
			ansBuses = nullptr;
		}

		return false;
	}

	return true;
}

bool UnitTestCW1::testCaseThree() { // test search by mileage > 10000
	const int MILEAGE = 10000;
	const int amount(3);
	const int test_amount(2);
	Bus* ansBuses = nullptr;
	Bus* buses = nullptr;
	std::string test_file_path = "test3cw1.txt";

	if (!std::ifstream(test_file_path)) {
		std::cout
			<< "���� 3 ��������." << std::endl
			<< "���������: ���� ������!" << std::endl
			<< "��������: ���� �� ������!" << std::endl;
		return false;
	}

	if (!allocateArray(buses, amount)) {
		std::cout << "���� 3 ��������. ������ ��������� ������!" << std::endl;
		return false;
	}
	else
		buses = new Bus[amount];

	ansBuses = new Bus[test_amount];
	getListFromFile(buses, amount, test_file_path);
	searchByMileage(buses, ansBuses, amount, MODUL_TESTS);

	int counter(0);
	for (int i = 0; i < amount; i++)
		if (ansBuses[i].getMileage() > MILEAGE)
			counter++;
	if (counter > test_amount) {
		std::cout
			<< "���� 3 ��������." << std::endl
			<< "���������: " << "���������� ���������: " << test_amount << std::endl
			<< "��������: " << counter << std::endl;

		if (buses != nullptr) {
			delete[] buses;
			buses = nullptr;
		}

		if (ansBuses != nullptr) {
			delete[] ansBuses;
			ansBuses = nullptr;
		}

		return false;
	}

	return true;
}

bool UnitTestCW1::testCaseFour() { // test check bus valid file
	std::string test_file_path = "test4cw1.txt";

	if (!std::ifstream(test_file_path)) {
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: ���� ������!" << std::endl
			<< "��������: ���� �� ������!" << std::endl;
		return false;
	}

	std::ifstream file(test_file_path);
	if (!isDataCorrectCW1(file)) {
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: ������ ��������� " << std::endl
			<< "��������: ������ �����������" << std::endl;
		return false;
	}
	file.close();
	return true;
}

 
bool UnitTestCW1::testCaseFive() { // zero buses
	const int buses_amount(0);
	Bus* buses = nullptr;
	if (allocateArray(buses, buses_amount)) {
		std::cout << "���� 5 ��������. ������ ��������� ������!" << std::endl;
		return false;
	}
	
	return true;
}

void UnitTestCW1::runAllTests() {
	UnitTestCW1 test{};

	if (test.testCaseOne() && test.testCaseTwo() && test.testCaseThree() && test.testCaseFour() && test.testCaseFive()) {
		system("cls");
		std::cout << "��� ��������� ����� ��������!" << std::endl;
	}
	else
		std::cout << "��������� ����� �� ��������." << std::endl;
}
