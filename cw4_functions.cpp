#include "input.h"
#include <iostream>

void InputText(std::string& text)
{
	std::cout << "¬ведите текст. ¬ведите q чтобы завершить ввод." << std::endl;
	std::string input{};
	while (input != "q")
	{
		getLine(std::cin, input, CW4_INPUT, MANUAL_INPUT);
		if (input != "q")
			text += (input + '\n');
	}
}
