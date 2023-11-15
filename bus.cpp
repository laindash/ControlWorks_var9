#include "bus.h"
#include "input.h"

void Bus::setDriverInfo() {
    std::cout << "Введите данные о водителе автобуса (фамилия и инициалы): ";
    getLine(std::cin, _driverInfo, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Bus::setDriverInfo(std::istream& input) {
    std::getline(input, _driverInfo);
}


void Bus::setBusNumber() {
    std::cout << "Введите номер автобуса: ";
    getLine(std::cin, _busNumber, WITH_DIGITS, MANUAL_INPUT);
}

void Bus::setBusNumber(std::istream& input) {
    std::getline(input, _busNumber);
}


void Bus::setRouteNumber() {
    std::cout << "Введите номер маршрута: ";
    getLine(std::cin, _routeNumber, WITH_DIGITS, MANUAL_INPUT);
}

void Bus::setRouteNumber(std::istream& input) {
    std::getline(input, _routeNumber);
}


void Bus::setBrand() {
    std::cout << "Введите марку автобуса: ";
    getLine(std::cin, _brand, WITH_DIGITS, MANUAL_INPUT);
}

void Bus::setBrand(std::istream& input) {
    std::getline(input, _brand);
}


void Bus::setStartYear() {
    std::cout << "Введите год начала эксплуатации автобуса: ";
    _startYear = getPosInt();
    while (_startYear > 2023) {
        std::cout << "Введенное значение превышает текущий год, введите другое! ";
        _startYear = getPosInt();
    }
}

void Bus::setStartYear(std::istream& input) {
    input >> _startYear;  input.get();
}


void Bus::setMileage() {
    std::cout << "Введите пробег: ";
    _mileage = getPosInt();
}

void Bus::setMileage(std::istream& input) {
    input >> _mileage;  input.get();
}


void Bus::showBus()
{
    std::cout
        << std::endl
        << "************************************************" << std::endl
        << "| Водитель: " << _driverInfo << std::endl
        << "| Номер: " << _busNumber << std::endl
        << "| Маршрут: " << _routeNumber << std::endl
        << "| Марка: " << _brand << std::endl
        << "| Год начала эксплуатации: " << _startYear << std::endl
        << "| Пробег: " << _mileage << std::endl
        << "************************************************" << std::endl
        << std::endl;
};


bool Bus::isEmpty()
{
    if (!_driverInfo.empty())
        return false;
    if (!_busNumber.empty())
        return false;
    if (!_routeNumber.empty())
        return false;
    if (!_brand.empty())
        return false;

    if (_startYear != 0)
        return false;
    if (_mileage != 0)
        return false;

    return true;
}
