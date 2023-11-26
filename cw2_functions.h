#ifndef CW2_FUNCTIONS_H
#define CW2_FUNCTIONS_H
#include "employees.h"

void fillHourly(std::vector<Worker*>& employees, int amount);
void showHourly(std::vector<Worker*>& employees);

void fillState(std::vector<Worker*>& employees, int amount);
void showState(std::vector<Worker*>& employees);

void chooseWorkerType(int& workerType);

#endif