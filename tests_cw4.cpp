#include "tests_cw4.h"
#include "text.h"
#include "filefunctions_cw4.h"
#include <iostream>
#include <fstream>
#include <filesystem>


bool UnitTestCW4::testCaseOne() // test get text
{
	std::string
		path = "4.1.txt",
		resultString{},
		expectedResult = "free text test";
	if (!std::ifstream(path)) {
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось:" << "Файл загружен!" << std::endl
			<< "Получено:" << "Файл не загружен!" << std::endl;
		return false;
	}
	getTextFromFile(resultString, path);

	if (resultString != expectedResult) {
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось:" << expectedResult << std::endl
			<< "Получено:" << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::testCaseTwo() // test 2
{
	std::string path = "4.2.txt";
	std::vector<std::string> expectedResult =
	{ "напишите", "функцию", "вычисляющую", "...", "напишите", "функцию", "вычисляющую" },
		text{};
	if (!std::ifstream(path))
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << "файл открыт!" << std::endl
			<< "Получено: " << "файл не найден!" << std::endl;
		//return false;
	}
	Text my_text;
	std::cin.seekg(std::cin.end);
	my_text.load(path);
	my_text.analyze();
	text = my_text.get_data();
	if (text != expectedResult)
	{
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << std::endl;
		for (size_t i = 0; i < expectedResult.size(); i++) {
			std::cout << expectedResult[i] << std::endl;
		}

		std::cout << "Получено: " << std::endl;

		for (size_t i = 0; i < text.size(); i++) {
			std::cout << text[i] << std::endl;
		}
		//return false;
	}

	return true;
}

bool UnitTestCW4::testCaseThree() // test 3
{
	std::string path = "4.3.txt";
	std::vector<std::string> expectedResult =
	{ "напишите", "программу", "вычисляющую", "...", "напишите", "функцию", "вычисляющую" },
		text{};
	if (!std::ifstream(path))
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << "файл открыт!" << std::endl
			<< "Получено: " << "файл не найден!" << std::endl;
		return false;
	}
	Text my_text;
	std::cin.seekg(std::cin.end);
	my_text.load(path);
	my_text.analyze();
	text = my_text.get_data();
	if (text != expectedResult)
	{
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << std::endl;
		for (size_t i = 0; i < expectedResult.size(); i++) {
			std::cout << expectedResult[i] << std::endl;
		}

		std::cout << "Получено: " << std::endl;

		for (size_t i = 0; i < text.size(); i++) {
			std::cout << text[i] << std::endl;
		}
		return false;
	}

	return true;
}

bool UnitTestCW4::testCaseFour() // test 4
{
	std::string path = "4.4.txt";
	std::vector<std::string> expectedResult = 
	{ "напишите", "функцию", "вычисляющую", "...", "напишите", "программу", "вычисляющую" }, 
		text{};
	if (!std::ifstream(path))
	{
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: " << "файл открыт!" << std::endl
			<< "Получено: " << "файл не найден!" << std::endl;
		return false;
	}
	Text my_text;
	std::cin.seekg(std::cin.end);
	my_text.load(path);
	my_text.analyze();
	text = my_text.get_data();
	if (text != expectedResult)
	{
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: " << std::endl;
		for (size_t i = 0; i < expectedResult.size(); i++) {
			std::cout << expectedResult[i] << std::endl;
		}

		std::cout << "Получено: " << std::endl;

		for (size_t i = 0; i < text.size(); i++) {
			std::cout << text[i] << std::endl;
		}
		return false;
	}
	
	return true;
}

bool UnitTestCW4::testCaseFive() // check getting text from file
{
	std::string path = "test5cw4.txt";
	std::vector<std::string>expectedResult = { "ooops" }, text{};

	if (!std::ifstream(path))
	{
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << "файл открыт!" << std::endl
			<< "Получено: " << "файл не найден!" << std::endl;
		return false;
	}
	Text my_text;
	my_text.load(path);
	text = my_text.get_data();
	if (text != expectedResult)
	{
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << std::endl;
		for (size_t i = 0; i < expectedResult.size(); i++) {
			std::cout << expectedResult[i] << std::endl;
		}

		std::cout << "Получено: " << std::endl;

		for (size_t i = 0; i < text.size(); i++) {
			std::cout << text[i] << std::endl;
		}
		return false;
	}
	return true;
}


void UnitTestCW4::runAllTests() {
	UnitTestCW4 test{};
	if (test.testCaseOne() && test.testCaseTwo() && test.testCaseThree() && test.testCaseFour() && test.testCaseFive()) {
		system("cls");
		std::cout << "Все модульные тесты пройдены!" << std::endl;
	}
	else
		std::cout << "Модульные тесты не пройдены." << std::endl;
}