#ifndef FILEFUNCTIONS_CW2_H
#define FILEFUNCTIONS_CW2_H
#include "employees.h"
#include "input.h"

bool IsDataCorrectCW2(std::ifstream& file);

std::string CheckFileCW2();

void GetHerbivoressFromFile(std::vector<Mammal*>& employees, int amount, std::string path = CheckFileCW2());

void saveToFile(std::vector<Mammal*>& employees);

int countStringsCW2(std::string path);

#endif
