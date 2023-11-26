#include "employees.h"
#include "input.h"
#include <iomanip>

void HourlyEmployee::show(void) const {
    std::cout
        << "************************************************" << std::endl
        << "| ФИО: " << _name << std::endl
        << "| Возраст: " << _age << std::endl
        << "| Должность: " << _position << std::endl
        << "| Количество отработанных часов: " << _workTime << std::endl
        << "| Зарплата: " << std::fixed << std::setprecision(2) << _salary << " руб/час" << std::endl
        << "************************************************" << std::endl;
}

void HourlyEmployee::setWorkTime(void) {
    std::cout << "Введите количество отработанных сотрудником часов: ";
    _workTime = getPosInt();
}

void HourlyEmployee::setWorkTime(std::istream& input) {
    input >> _workTime; input.get();
}

void HourlyEmployee::setSalary(void) {
    std::cout << "Введите зарплату сотрудника в час: ";
    _salary = getPosInt();
}

void HourlyEmployee::setSalary(std::istream& input) {
    input >> _salary; input.get();
}

void StateEmployee::show(void) const {
    std::cout
        << "************************************************" << std::endl
        << "| ФИО: " << _name << std::endl
        << "| Возраст: " << _age << std::endl
        << "| Должность: " << _position << std::endl
        << "| Опыт работы (в месяцах): " << _workExperience << std::endl
        << "| Зарплата: " << std::fixed << std::setprecision(2) << _salary << " руб/мес" << std::endl
        << "************************************************" << std::endl;
}

void StateEmployee::setWorkExperience(void) {
    std::cout << "Введите опыт работы сотрудника в месяцах (считать за минимум 1 месяц): ";
    _workExperience = getPosInt();
}

void StateEmployee::setWorkExperience(std::istream& input) {
    input >> _workExperience; input.get();
}

void StateEmployee::setSalary(void) {
    std::cout << "Введите зарплату сотрудника в месяц: ";
    _salary = getPosInt();
}

void StateEmployee::setSalary(std::istream& input) {
    input >> _salary; input.get();
}