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
			<< "���� 1 ��������." << std::endl
			<< "���������:" << "���� ��������!" << std::endl
			<< "��������:" << "���� �� ��������!" << std::endl;
		return false;
	}
	getTextFromFile(resultString, path);

	if (resultString != expectedResult) {
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������:" << expectedResult << std::endl
			<< "��������:" << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::testCaseTwo() // test 2
{
	std::string path = "4.2.txt";
	std::vector<std::string> expectedResult =
	{ "��������", "�������", "�����������", "...", "��������", "�������", "�����������" },
		text{};
	if (!std::ifstream(path))
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << "���� ������!" << std::endl
			<< "��������: " << "���� �� ������!" << std::endl;
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
			<< "���� 2 ��������." << std::endl
			<< "���������: " << std::endl;
		for (size_t i = 0; i < expectedResult.size(); i++) {
			std::cout << expectedResult[i] << std::endl;
		}

		std::cout << "��������: " << std::endl;

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
	{ "��������", "���������", "�����������", "...", "��������", "�������", "�����������" },
		text{};
	if (!std::ifstream(path))
	{
		std::cout
			<< "���� 3 ��������." << std::endl
			<< "���������: " << "���� ������!" << std::endl
			<< "��������: " << "���� �� ������!" << std::endl;
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
			<< "���� 3 ��������." << std::endl
			<< "���������: " << std::endl;
		for (size_t i = 0; i < expectedResult.size(); i++) {
			std::cout << expectedResult[i] << std::endl;
		}

		std::cout << "��������: " << std::endl;

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
	{ "��������", "�������", "�����������", "...", "��������", "���������", "�����������" }, 
		text{};
	if (!std::ifstream(path))
	{
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: " << "���� ������!" << std::endl
			<< "��������: " << "���� �� ������!" << std::endl;
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
			<< "���� 4 ��������." << std::endl
			<< "���������: " << std::endl;
		for (size_t i = 0; i < expectedResult.size(); i++) {
			std::cout << expectedResult[i] << std::endl;
		}

		std::cout << "��������: " << std::endl;

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
			<< "���� 5 ��������." << std::endl
			<< "���������: " << "���� ������!" << std::endl
			<< "��������: " << "���� �� ������!" << std::endl;
		return false;
	}
	Text my_text;
	my_text.load(path);
	text = my_text.get_data();
	if (text != expectedResult)
	{
		std::cout
			<< "���� 5 ��������." << std::endl
			<< "���������: " << std::endl;
		for (size_t i = 0; i < expectedResult.size(); i++) {
			std::cout << expectedResult[i] << std::endl;
		}

		std::cout << "��������: " << std::endl;

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
		std::cout << "��� ��������� ����� ��������!" << std::endl;
	}
	else
		std::cout << "��������� ����� �� ��������." << std::endl;
}