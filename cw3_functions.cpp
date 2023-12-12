#include "input.h"
#include "matrix.h"
#include "ISort.h"
#include <iostream>
#include <iomanip>

void showUnsortedMatrix(std::vector<std::vector<int>>& arr, int rows, int columns) {
    std::cout << "»значальный массив: " << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << std::setw(4) << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void showComparisonTable(std::vector<ISort*>& sorts) {
    for (std::vector<ISort*>::iterator it = sorts.begin(); it != sorts.end(); it++) {
        std::cout
            << std::endl << (*it)->getSortName() << std::endl
            << "(—равнений: " << (*it)->getComparisons()
            << ", ѕерестановок: " << (*it)->getSwaps() << ")" << std::endl;
    }
}

void fillMatrix(std::vector<std::vector<int>>& matrix, int rows, int columns) {
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(columns);
        for (int j = 0; j < columns; j++) {
            std::cout << "¬ведите €чейку " << i + 1 << " строки " << j + 1 << " столбца " << std::endl;
            matrix[i][j] = getInt();
        }
    }
}

void fillMatrixRandomly(std::vector<std::vector<int>>& matrix, int rows, int columns) {
    const int lowBound = -100, upBound = 100;
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(columns);
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = getRandInt(lowBound, upBound);
        }
    }
}

void goSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>& sorts, std::vector<Matrix*>& matrices) {
    for (std::vector<ISort*>::iterator it = sorts.begin(); it != sorts.end(); it++) {
        Matrix* matrix = new Matrix;
        matrix->startSort(arr, rows, columns, it);
        matrices.push_back(matrix);
    }
}

void showResults(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>& sorts, std::vector<Matrix*>& matrices) {
    showUnsortedMatrix(arr, rows, columns);
    std::vector<Matrix*>::iterator m_it = matrices.begin();
    std::vector<ISort*>::iterator it = sorts.begin();
    for (; (it != sorts.end()) && (m_it != matrices.end()); it++, m_it++) {
        (*m_it)->showSortedMatrix(rows, it);
    }
    showComparisonTable(sorts);
}