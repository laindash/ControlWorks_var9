#include "employees.h"
#include "input.h"
#include <iomanip>

void Herbivoress::Show(void) const
{
    std::cout
        << "************************************************" << std::endl
        << "| ������ �������: " << _wayOfEating << std::endl
        << "| ���: " << std::fixed << std::setprecision(2) << _weight << " ��" << std::endl
        << "| ����� ��������: " << _habitat << std::endl
        << "| ���: " << _gender << std::endl
        << "| �������� ������������: " << std::fixed << std::setprecision(2) << _movementSpeed << " ��/�" << std::endl
        << "************************************************" << std::endl;
}

void Herbivoress::SetGender(void)
{
    std::cout << "������� ���: ";
    getLine(std::cin, _gender, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Herbivoress::SetGenderFromFile(std::istream& input)
{
    std::getline(input, _gender);
}

void Herbivoress::SetMovementSpeed()
{
    std::cout << "������� �������� ������������: ";
    _movementSpeed = getPosDouble();
}

void Herbivoress::SetMovementSpeedFromFile(std::istream& input)
{
    input >> _movementSpeed; input.get();
}
