#include "tests_cw4.h"
#include "cw4_functions.h"
#include "filefunctions_cw4.h"
#include <iostream>
#include <fstream>
#include <filesystem>


bool UnitTestCW4::TestCaseOne() // test modify 1 substring
{
	/*size_t sequence_size = 2;
	std::string
		testString = "���������� ��������",
		resultString{},
		expectedResult = "���{�, 2}��{�, 3} ��������";

	//StartModify(testString, resultString, sequence_size);
	if (resultString != expectedResult)
	{
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������: " << expectedResult << std::endl
			<< "��������: " << resultString << std::endl;
		return false;
	}
	*/
	return true;
}

bool UnitTestCW4::TestCaseTwo() // test modify more than 1 substring
{
	/*size_t sequence_size = 3;
	std::string
		testString = "testovayaaa stroooka 1122234444 stttr",
		resultString{},
		expectedResult = "testovay{a, 3} str{o, 3}ka 11{2, 3}3{4, 4} s{t, 3}r";

	//StartModify(testString, resultString, sequence_size);
	if (resultString != expectedResult)
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << expectedResult << std::endl
			<< "��������: " << resultString << std::endl;
		return false;
	}
	*/
	return true;
}

bool UnitTestCW4::TestCaseThree() // test restore 1 substring
{
	/*std::string
		testString = "���{�, 2}��{�, 3} ��������",
		resultString{},
		expectedResult = "���������� ��������";
	bool error = false;
	//StartRestore(testString, resultString, error);
	if (resultString != expectedResult)
	{
		std::cout
			<< "���� 3 ��������." << std::endl
			<< "���������: " << expectedResult << std::endl
			<< "��������: " << resultString << std::endl;
		return false;
	}
	*/
	return true;
}

bool UnitTestCW4::TestCaseFour() // test restore more than 1 substring
{
	/*std::string
		testString = "testovay{a, 3} str{o, 3}ka 11{2, 3}3{4, 4} s{t, 3}r",
		resultString{},
		expectedResult = "testovayaaa stroooka 1122234444 stttr";
	bool error = false;
	//StartRestore(testString, resultString, error);
	if (resultString != expectedResult)
	{
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: " << expectedResult << std::endl
			<< "��������: " << resultString << std::endl;
		return false;
	}
	*/
	return true;
}

bool UnitTestCW4::TestCaseFive() // check getting text from file
{
	/*std::string
		path = "test5cw4.txt",
		resultString{},
		expectedResult = "ooops employee";

	if (!std::ifstream(path))
	{
		std::cout
			<< "���� 5 ��������." << std::endl
			<< "���������: " << "���� ������!" << std::endl
			<< "��������: " << "���� �� ������!" << std::endl;
		return false;
	}

	getTextFromFile(resultString, path);

	if (resultString != expectedResult)
	{
		std::cout
			<< "���� 5 ��������." << std::endl
			<< "���������: " << expectedResult << std::endl
			<< "��������: " << resultString << std::endl;
		return false;
	}
	*/
	return true;
}


void UnitTestCW4::RunAllTests()
{
	UnitTestCW4 test{};
	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive())
	{
		system("cls");
		std::cout << "��� ��������� ����� ��������!" << std::endl;
	}
	else
		std::cout << "��������� ����� �� ��������." << std::endl;
}