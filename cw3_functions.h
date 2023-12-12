#ifndef CW3_FUNCTIONS_H
#define CW3_FUNCTIONS_H

#include <vector>
#include "ISort.h"
#include "matrix.h"


void showUnsortedMatrix(std::vector<std::vector<int>>& arr, int rows, int columns);
void showComparisonTable(std::vector<ISort*>& sorts);
void fillMatrix(std::vector<std::vector<int>>& matrix, int rows, int columns);
void fillMatrixRandomly(std::vector<std::vector<int>>& matrix, int rows, int columns);
void goSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>& sorts, std::vector<Matrix*>& matrices);
void showResults(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>& sorts, std::vector<Matrix*>& matrices);


#endif