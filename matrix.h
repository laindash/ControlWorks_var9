#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "ISort.h"

class Matrix {
	std::vector<int> _unsortedDiagonals{};
	std::vector<std::vector<int>> _sortedDiagonals{};
public:

	void startSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>::iterator& it);
	void showSortedMatrix(const int rows, std::vector<ISort*>::iterator& it);
	bool isSorted(std::vector<int>& arr);
	std::vector<std::vector<int>> getSortedDiagonals() { return _sortedDiagonals; };

};

#endif