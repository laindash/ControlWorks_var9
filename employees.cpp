#include "employees.h"
#include "input.h"
#include <iomanip>

void HourlyEmployee::show(void) const {
    std::cout
        << "************************************************" << std::endl
        << "| ���: " << _name << std::endl
        << "| �������: " << _age << std::endl
        << "| ���������: " << _position << std::endl
        << "| ���������� ������������ �����: " << _workTime << std::endl
        << "| ��������: " << std::fixed << std::setprecision(2) << _salary << " ���/���" << std::endl
        << "************************************************" << std::endl;
}

void HourlyEmployee::setWorkTime(void) {
    std::cout << "������� ���������� ������������ ����������� �����: ";
    _workTime = getPosInt();
}

void HourlyEmployee::setWorkTime(std::istream& input) {
    input >> _workTime; input.get();
}

void HourlyEmployee::setSalary(void) {
    std::cout << "������� �������� ���������� � ���: ";
    _salary = getPosInt();
}

void HourlyEmployee::setSalary(std::istream& input) {
    input >> _salary; input.get();
}

void StateEmployee::show(void) const {
    std::cout
        << "************************************************" << std::endl
        << "| ���: " << _name << std::endl
        << "| �������: " << _age << std::endl
        << "| ���������: " << _position << std::endl
        << "| ���� ������ (� �������): " << _workExperience << std::endl
        << "| ��������: " << std::fixed << std::setprecision(2) << _salary << " ���/���" << std::endl
        << "************************************************" << std::endl;
}

void StateEmployee::setWorkExperience(void) {
    std::cout << "������� ���� ������ ���������� � ������� (������� �� ������� 1 �����): ";
    _workExperience = getPosInt();
}

void StateEmployee::setWorkExperience(std::istream& input) {
    input >> _workExperience; input.get();
}

void StateEmployee::setSalary(void) {
    std::cout << "������� �������� ���������� � �����: ";
    _salary = getPosInt();
}

void StateEmployee::setSalary(std::istream& input) {
    input >> _salary; input.get();
}