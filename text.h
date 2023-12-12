#ifndef TEXT_H
#define TEXT_H
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <filesystem>



class Text {
private:
	std::vector <std::string> data;
public:
	Text() = default;
	Text(Text* target);
	~Text();
	void input();
	void load(std::string filename);
	void print();
	void analyze();
	bool empty();
	std::vector <std::string> get_data();
	void replace(std::vector <size_t> values, std::vector <int> indicies);
};

std::vector <int> get_in_other(int index, int n);

#endif