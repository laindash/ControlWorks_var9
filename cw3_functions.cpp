#include "input.h"
#include "matrix.h"
#include "ISort.h"
#include <iostream>

void ShowUnsortedMatrix(std::vector<std::vector<int>>& arr, int rows, int columns)
{
    std::cout << "����������� ������: " << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void ShowComparisonTable(std::vector<ISort*>& sorts)
{
    for (std::vector<ISort*>::iterator it = sorts.begin(); it != sorts.end(); it++)
    {
        std::cout
            << std::endl << (*it)->GetSortName() << std::endl
            << "(���������: " << (*it)->GetComparisons()
            << ", ������������: " << (*it)->GetSwaps() << ")" << std::endl;
    }
}

void FillMatrix(std::vector<std::vector<int>>& matrix, int rows, int columns)
{
    matrix.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i].resize(columns);
        for (int j = 0; j < columns; j++)
        {
            std::cout << "������� ������ " << i + 1 << " ������ " << j + 1 << " ������� " << std::endl;
            matrix[i][j] = getInt();
        }
    }
}

void FillMatrixRandomly(std::vector<std::vector<int>>& matrix, int rows, int columns)
{
    const int lowBound = -100, upBound = 100;
    matrix.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i].resize(columns);
        for (int j = 0; j < columns; j++)
            matrix[i][j] = getRandInt(lowBound, upBound);
    }
}

void GoSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>& sorts, std::vector<Matrix*>& matrices)
{
    for (std::vector<ISort*>::iterator it = sorts.begin(); it != sorts.end(); it++)
    {
        Matrix* matrix = new Matrix;
        matrix->StartSort(arr, rows, columns, it);
        matrices.push_back(matrix);
    }
}

void ShowResults(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>& sorts, std::vector<Matrix*>& matrices)
{
    ShowUnsortedMatrix(arr, rows, columns);
    std::vector<Matrix*>::iterator m_it = matrices.begin();
    std::vector<ISort*>::iterator it = sorts.begin();
    for (; (it != sorts.end()) && (m_it != matrices.end()); it++, m_it++)
    {
        (*m_it)->ShowSortedMatrix(rows, columns, it, arr);
    }
    ShowComparisonTable(sorts);
}