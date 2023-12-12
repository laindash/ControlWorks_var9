#ifndef TESTS_CW3_H
#define TESTS_CW3_H

#include <vector>


class UnitTestCW3
{
public:
	void printArray(std::vector<int> array);

	bool testCaseOne();
	bool testCaseTwo();
	bool testCaseThree();
	bool testCaseFour();
	bool testCaseFive();

	void runAllTests();
};

#endif