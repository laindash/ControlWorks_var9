#include "bus.h"
#include "input.h"

void Bus::setDriverInfo() {
    std::cout << "������� ������ � �������� �������� (������� � ��������): ";
    getLine(std::cin, _driverInfo, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Bus::setDriverInfo(std::istream& input) {
    std::getline(input, _driverInfo);
}


void Bus::setBusNumber() {
    std::cout << "������� ����� ��������: ";
    getLine(std::cin, _busNumber, WITH_DIGITS, MANUAL_INPUT);
}

void Bus::setBusNumber(std::istream& input) {
    std::getline(input, _busNumber);
}


void Bus::setRouteNumber() {
    std::cout << "������� ����� ��������: ";
    getLine(std::cin, _routeNumber, WITH_DIGITS, MANUAL_INPUT);
}

void Bus::setRouteNumber(std::istream& input) {
    std::getline(input, _routeNumber);
}


void Bus::setBrand() {
    std::cout << "������� ����� ��������: ";
    getLine(std::cin, _brand, WITH_DIGITS, MANUAL_INPUT);
}

void Bus::setBrand(std::istream& input) {
    std::getline(input, _brand);
}


void Bus::setStartYear() {
    std::cout << "������� ��� ������ ������������ ��������: ";
    _startYear = getPosInt();
    while (_startYear > 2023) {
        std::cout << "��������� �������� ��������� ������� ���, ������� ������! ";
        _startYear = getPosInt();
    }
}

void Bus::setStartYear(std::istream& input) {
    input >> _startYear;  input.get();
}


void Bus::setMileage() {
    std::cout << "������� ������: ";
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
        << "| ��������: " << _driverInfo << std::endl
        << "| �����: " << _busNumber << std::endl
        << "| �������: " << _routeNumber << std::endl
        << "| �����: " << _brand << std::endl
        << "| ��� ������ ������������: " << _startYear << std::endl
        << "| ������: " << _mileage << std::endl
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
