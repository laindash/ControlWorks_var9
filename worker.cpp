#include "worker.h"
#include "input.h"
#include <vector>

void Mammal::SetHabitat()
{
	std::cout << "¬ведите среду обитани€: ";
	getLine(std::cin, _habitat, WITH_DIGITS, MANUAL_INPUT);
}

void Mammal::SetHabitatFromFile(std::istream& input)
{
	std::getline(input, _habitat);
}

void Mammal::SetWayOfEating()
{
	std::cout << "¬ведите способ питани€: ";
	getLine(std::cin, _wayOfEating, WITH_DIGITS, MANUAL_INPUT);
}

void Mammal::SetWayOfEatingFromFile(std::istream& input)
{
	std::getline(input, _wayOfEating);
}

void Mammal::SetWeight()
{
	std::cout << "¬ведите вес: ";
	_weight = getPosDouble();
}

void Mammal::SetWeightFromFile(std::istream& input)
{
	input >> _weight; input.get();
}

