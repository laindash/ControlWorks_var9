#include "matrix.h"
#include "ISort.h"
#include "input.h"
#include <iomanip>


bool Matrix::isSorted(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void Matrix::startSort(std::vector<std::vector<int>>& arr, int rows, int columns, std::vector<ISort*>::iterator& it) {
    for (int k = -(rows - 1); k < columns; ++k) {
        for (int i = 0; i < rows; ++i) {
            int j = i + k;
            if (j >= 0 && j < columns) {
                _unsortedDiagonals.push_back(arr[i][j]);
            }
        }

        (*it)->sort(_unsortedDiagonals);
        _sortedDiagonals.push_back(_unsortedDiagonals);
        _unsortedDiagonals.clear();

    }
}

void Matrix::showSortedMatrix(const int rows, std::vector<ISort*>::iterator& it) {
    std::cout << std::endl << (*it)->getSortName() << std::endl;
    std::vector<std::vector<int>> diagonalsForPrint = _sortedDiagonals;

    int size = static_cast<int>(diagonalsForPrint.size());
    int row_count(0);
    int ELEM_EXIST = 888888261; // (плохой метод) случайное число которого нет в массиве, необходимо для того, чтобы заменить на него элемент который уже выводился
    bool ELEM_EXIST_in_array = true;

    while (ELEM_EXIST_in_array) {
        for (const auto& diagonal : diagonalsForPrint) {
            for (const auto& element : diagonal) {
                if (element != ELEM_EXIST) {
                    ELEM_EXIST_in_array = false;
                }
                else {
                    ELEM_EXIST_in_array = true;
                    ELEM_EXIST++; // изменяем значение для элемента использующегося для замены, если он существует (чтобы ничего не сломалось)
                    break;
                }
            }

            if (ELEM_EXIST_in_array) {
                break;
            }
        }
    }

    while (row_count != rows) {
        for (int i = rows - 1 - row_count; i < size - row_count; i++) {
            int j = 0;
            while (diagonalsForPrint[i][j] == ELEM_EXIST) {
                j++;
            }

            std::cout << std::setw(4) << diagonalsForPrint[i][j] << ' ';
            diagonalsForPrint[i][j] = ELEM_EXIST;
        }

        std::cout << std::endl;
        row_count++;
    }
}