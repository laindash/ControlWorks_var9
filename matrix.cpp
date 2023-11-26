#include "matrix.h"
#include "ISort.h"
#include "input.h"
#include <iomanip>


bool Matrix::IsSorted(std::vector<int>& arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

void Matrix::StartSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>::iterator& it)
{
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (arr[i][i] % 2 == 0)
                _unsortedColumns.push_back(arr[j][i]);
        }
        if (!_unsortedColumns.empty())
        {
            (*it)->Sort(_unsortedColumns);
            _sortedColumns.push_back(_unsortedColumns);
            _unsortedColumns.clear();
        }
        else
            _sortedColumns.push_back(_unsortedColumns);
    }
}

void Matrix::ShowSortedMatrix(const int rows, const int columns, std::vector<ISort*>::iterator& it, std::vector<std::vector<int>>& arr)
{
    std::cout << std::endl << (*it)->GetSortName() << std::endl;
    std::vector<int> indexes(columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] % 2 == 0)
            {
                std::cout << _sortedColumns[j][indexes[j]++] << ' ';
            }
            else
                std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}