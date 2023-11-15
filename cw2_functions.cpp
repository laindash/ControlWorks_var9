#include "input.h"
#include "filefunctions_cw2.h"
#include "employees.h"
#include <vector>
#include <iostream>


void FillHerbivoress(std::vector<Mammal*>& employees, int amount)
{
    std::cout << std::endl;
    int Herbivoress_id = 1;
    for (int i = 0; i < amount; i++, Herbivoress_id++)
    {
        std::cout << "Заполните информацию о травоядном # " << Herbivoress_id << std::endl;
        Herbivoress* new_employees = new Herbivoress;
        new_employees->SetWayOfEating();
        new_employees->SetWeight();
        new_employees->SetHabitat();
        new_employees->SetGender();
        new_employees->SetMovementSpeed();
        employees.push_back(new_employees);
    }
}


void ShowHerbivoress(std::vector<Mammal*>& employees)
{
    int Herbivoress_id = 1;
    for (std::vector<Mammal*>::const_iterator it = employees.cbegin(); it != employees.cend(); it++, Herbivoress_id++)
    {
        std::cout << "Травоядное # " << Herbivoress_id << std::endl;
        (*it)->Show();
    }
}