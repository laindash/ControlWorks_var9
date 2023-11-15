#ifndef FILEFUNCTIONS_CW4_H
#define FILEFUNCTIONS_CW4_H

bool IsDataCorrectCW4(std::ifstream& file);
std::string CheckFileCW4();
void getTextFromFile(std::string& text, std::string& path);
void saveToFile(const std::string& restoredText, const std::string& modifiedText, const std::string& text, int save_choice);

#endif