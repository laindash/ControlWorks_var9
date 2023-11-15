#include <filesystem>
#include <fstream>
#include "employees.h"
#include "input.h"


bool IsDataCorrectCW2(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    std::string test_string{};
    double test_double{};

    if (!file.eof())
    {
        getLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //way of eating
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������� �������!" << std::endl;
            return false;
        }

        file >> test_double; //weight
        if (test_double > DBL_WRONG)
        {
            std::cout << "������ ���������� ����, ��������� ������������ ��������!" << std::endl;
            return false;
        }
        if (file.fail())
        {
            std::cout << "������ ���������� ����!" << std::endl;
            return false;
        };

        file.get();
        getLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //habitat
        if (test_string.empty())
        {
            std::cout << test_string << std::endl;
            std::cout << "������ ���������� ����� ��������!" << std::endl;
            return false;
        }

        getLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //gender
        if (test_string.empty())
        {
            std::cout << "������ ���������� ����!" << std::endl;
            return false;
        }

        file >> test_double; //movement speed
        if (test_double > DBL_WRONG)
        {
            std::cout << "������ ���������� �������� ������������, ��������� ������������ ��������!" << std::endl;
            return false;
        }
        if (file.fail())
        {
            std::cout << "������ ���������� �������� ������������!" << std::endl;
            return false;
        };

        while (file.get() != EOF); //to clean up possible residual information
    }
    else
        std::cout << "���� ����!" << std::endl;

    file.seekg(0, std::ios::beg);  //If everything went well, then return the pointer to the beginning of the file

    return true;
}

std::string CheckFileCW2(void)
{
    std::error_code error{};

    std::string path{};
    bool isLoaded = false;

    std::ifstream file;

    do
    {
        std::cout << "������� ���� � �����: ";
        getLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);

        if (!std::ifstream(path))
        {
            std::cout << "��������� ���� �� ������!" << std::endl;
            continue;
        }

        if (!std::filesystem::is_regular_file(path, error))
        {
            std::cout << "������, ������������ ����� �����!" << std::endl;
            continue;
        }

        file.open(path);

        if (!file)
        {
            std::cout << "������ �������� �����!" << std::endl;
            file.close();
        }
        else if (!IsDataCorrectCW2(file))
        {
            std::cout << "������ �����������!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } 
    while (!isLoaded);

    std::cout << "���� ������!" << std::endl;
    file.close();

    return path;
}

void GetHerbivoressFromFile(std::vector<Mammal*>& employees, int amount, std::string path = CheckFileCW2())
{
    std::ifstream file(path);

    for (int i = 0; i < amount && !file.eof(); i++)
    {
        Herbivoress* new_employees = new Herbivoress;
        new_employees->SetWayOfEatingFromFile(file);
        new_employees->SetWeightFromFile(file);
        new_employees->SetHabitatFromFile(file);
        new_employees->SetGenderFromFile(file);
        new_employees->SetMovementSpeedFromFile(file);

        employees.push_back(new_employees);
    }

    std::cout << "������ ��������!" << std::endl;

    file.close();
}

void saveToFile(std::vector<Mammal*>& employees)
{
    std::ofstream file;
    std::string path{};
    bool isOpened = false;

    std::error_code error{};

    do
    {
        std::cout
            << "������� ���� � ����� ��� ����������. "
            << "���� ������� ������ ��� � ���������� �����, ����������� ���� ����� �������� ���� � ��������� ���� ���������." << std::endl;
        std::getline(std::cin, path);

        if (std::ifstream(path))
        {
            if (!std::filesystem::is_regular_file(path, error))
            {
                std::cout << "������, ������������ ����� �����!" << std::endl;
                continue;
            }

            std::cout
                << "������ ���� ��� ����������!." << std::endl
                << "1 - ������������." << std::endl
                << "2 - ������� ������." << std::endl;

            if (getKey(YES, NO) == NO)
                continue;
        }

        file.open(path, std::ios::trunc);

        if (!file)
            std::cout << "������ �������� �����!" << std::endl;
        else
            isOpened = true;
    } 
    while (!isOpened);

    std::string outputWayOfEating{}, outputHabitat{}, outputGender{};
    double outputWeight{}, outputMovementSpeed{};

    for (std::vector<Mammal*>::iterator it = employees.begin(); it != employees.end(); it++)
    {
        outputWayOfEating = (*it)->GetWayOfEating();
        outputWeight = (*it)->GetWeight();
        outputHabitat = (*it)->GetHabitat();
        outputGender = dynamic_cast<Herbivoress*>(*it)->GetGender();
        outputMovementSpeed = dynamic_cast<Herbivoress*>(*it)->GetMovementSpeed();

        if (it != employees.begin())
            file << std::endl;
        file << outputWayOfEating << std::endl;
        file << outputWeight << std::endl;
        file << outputHabitat << std::endl;
        file << outputGender << std::endl;
        file << outputMovementSpeed;
    }
    std::cout << "������� ��������� � " << path << std::endl;
}

int countStringsCW2(std::string path)
{
    int stringsAmount{};

    std::ifstream file;
    file.open(path);
    std::string tmp{};

    while (!file.eof())
    {
        std::getline(file, tmp);
        stringsAmount++;
    }

    return stringsAmount;
}