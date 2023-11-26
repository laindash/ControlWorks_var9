#ifndef FILEFUNCTIONS_CW2_H
#define FILEFUNCTIONS_CW2_H
#include "employees.h"
#include "input.h"

bool isDataCorrectCW2(std::ifstream& file, int workerType);

std::string checkFileCW2(int workerType);

void getEmployeesFromFile(std::vector<Worker*>& employees, int amount, std::string path, int workerType);

void saveToFile(std::vector<Worker*>& employees, int workerType);

int countStringsCW2(std::string path);

#endif
