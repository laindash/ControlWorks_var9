#ifndef FILEFUNCTIONS_CW4_H
#define FILEFUNCTIONS_CW4_H
#include <fstream>
#include <vector>


bool isDataCorrectCW4(std::ifstream& file);
std::string checkFileCW4();
void saveToFile(const std::vector<std::string>& text);
void getTextFromFile(std::string& text, std::string& path);

#endif