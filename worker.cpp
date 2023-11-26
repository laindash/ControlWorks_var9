#include "worker.h"
#include "input.h"
#include <vector>

void Worker::setName() {
	std::cout << "Введите ФИО работника: ";
	getLine(std::cin, _name, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Worker::setName(std::istream& input) {
	std::getline(input, _name);
}

void Worker::setPosition() {
	std::cout << "Введите должность: ";
	getLine(std::cin, _position, WITH_DIGITS, MANUAL_INPUT);
}

void Worker::setPosition(std::istream& input) {
	std::getline(input, _position);
}

void Worker::setAge() {
	std::cout << "Введите возраст: ";
	_age = getPosInt();
}

void Worker::setAge(std::istream& input) {
	input >> _age; input.get();
}

