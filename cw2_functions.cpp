#include "input.h"
#include "filefunctions_cw2.h"
#include "employees.h"
#include <vector>
#include <iostream>


void fillHourly(std::vector<Worker*>& employees, int amount) {
    std::cout << std::endl;
    int employees_id = 1;
    for (int i = 0; i < amount; i++, employees_id++) {
        std::cout << "��������� ���������� � ��������� ���������� # " << employees_id << std::endl;
        HourlyEmployee* new_employee = new HourlyEmployee;
        new_employee->setName();
        new_employee->setAge();
        new_employee->setPosition();
        new_employee->setWorkTime();
        new_employee->setSalary();
        employees.push_back(new_employee);
    }
}

void showHourly(std::vector<Worker*>& employees) {
    int employees_id = 1;
    for (std::vector<Worker*>::const_iterator it = employees.cbegin(); it != employees.cend(); it++, employees_id++) {
        std::cout << "�������� � ��������� ������� # " << employees_id << std::endl;
        (*it)->show();
    }
}


void fillState(std::vector<Worker*>& employees, int amount) {
    std::cout << std::endl;
    int employees_id = 1;
    for (int i = 0; i < amount; i++, employees_id++) {
        std::cout << "��������� ���������� � ������� ���������� # " << employees_id << std::endl;
        StateEmployee* new_employee = new StateEmployee;
        new_employee->setName();
        new_employee->setAge();
        new_employee->setPosition();
        new_employee->setWorkExperience();
        new_employee->setSalary();
        employees.push_back(new_employee);
    }
}

void showState(std::vector<Worker*>& employees) {
    int employees_id = 1;
    for (std::vector<Worker*>::const_iterator it = employees.cbegin(); it != employees.cend(); it++, employees_id++) {
        std::cout << "�������� � ����� # " << employees_id << std::endl;
        (*it)->show();
    }
}

void chooseWorkerType(int &workerType) {
    std::cout
        << "��� ������ �������� ��� ����������, � �������� ����������� �������������� � ���������." << std::endl
        << "1 - �������� � ��������� �������." << std::endl
        << "2 - �������� � �����." << std::endl
        << "ESC - �����." << std::endl;
    workerType = getKey(HOURLY_EMPLOYEE, STATE_EMPLOYEE);
}