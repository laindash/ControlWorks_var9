#ifndef FILEFUNCTIONS_CW1_H
#define FILEFUNCTIONS_CW1_H
#include "bus.h"

bool isDataCorrectCW1(std::ifstream& file);
std::string checkFile(void);
void getListFromFile(Bus *List, int amount, std::string path);
void saveToFile(Bus *List, int amount);
int countStrings(std::string path);


#endif
