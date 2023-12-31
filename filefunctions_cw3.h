#ifndef FILEFUNCTIONS_CW3_H
#define FILEFUNCTIONS_CW3_H

#include <vector>
#include <fstream>
#include "ISort.h"
#include "matrix.h"


bool isDataCorrectCW3(std::ifstream& file);
std::string checkFileCW3();
void getMatrixFromFile(std::vector<std::vector<int>>& matrix, int& rows, int& columns, std::string& path);
void saveToFile(std::vector<ISort*>& sorts, std::vector<Matrix*>& matrices, std::vector<std::vector<int>>& arr, int rows, int columns);

#endif