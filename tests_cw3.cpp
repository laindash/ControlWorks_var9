#include "tests_cw3.h"
#include "cw3_functions.h"
#include "filefunctions_cw3.h"
#include "matrix.h"

void UnitTestCW3::printArray(std::vector<int> array) {
	for (size_t i = 0; i < array.size(); i++) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
}

bool UnitTestCW3::testCaseOne() { // test bubble sort
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Matrix matrix{};
	BubbleSort bubble_sort{};
	bubble_sort.sort(array);
	if (!matrix.isSorted(array)) {
		std::cout
			<< "Тест 1 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		printArray(answer);
		std::cout << "Получено: " << std::endl;
		printArray(array);
		return false;
	}

	return true;
}

bool UnitTestCW3::testCaseTwo() { // test selection sort
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Matrix matrix{};
	SelectionSort selection_sort{};
	selection_sort.sort(array);
	if (!matrix.isSorted(array)) {
		std::cout
			<< "Тест 2 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		printArray(answer);
		std::cout << "Получено: " << std::endl;
		printArray(array);
		return false;
	}
	return true;
}

bool UnitTestCW3::testCaseThree() { // test insertion sort
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Matrix matrix{};
	InsertionSort insertion_sort{};
	insertion_sort.sort(array);
	if (!matrix.isSorted(array)) {
		std::cout
			<< "Тест 3 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		printArray(answer);
		std::cout << "Получено: " << std::endl;
		printArray(array);
		return false;
	}
	return true;
}

bool UnitTestCW3::testCaseFour() { // test shell sort
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Matrix matrix{};
	ShellSort shell_sort{};
	shell_sort.sort(array);
	if (!matrix.isSorted(array)) {
		std::cout
			<< "Тест 4 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		printArray(answer);
		std::cout << "Получено: " << std::endl;
		printArray(array);
		return false;
	}
	return true;
}

bool UnitTestCW3::testCaseFive() { // test quick sort
	std::vector<int> array{ 9, 5, 3, 2, 7, 4, 0, 1, 6, 8 };
	std::vector<int> answer{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Matrix matrix{};
	QuickSort quick_sort{};
	quick_sort.sort(array);
	if (!matrix.isSorted(array)) {
		std::cout
			<< "Тест 5 провален." << std::endl
			<< "Ожидалось: " << "отсортированные элементы: " << std::endl;
		printArray(answer);
		std::cout << "Получено: " << std::endl;
		printArray(array);
		return false;
	}
	return true;
}



void UnitTestCW3::runAllTests() {
	UnitTestCW3 test{};
	if (test.testCaseOne() && test.testCaseTwo() && test.testCaseThree() && test.testCaseFour() && test.testCaseFive()) {
		system("cls");
		std::cout << "Все модульные тесты пройдены!" << std::endl;
	}
	else {
		std::cout << "Модульные тесты не пройдены." << std::endl;
	}
}