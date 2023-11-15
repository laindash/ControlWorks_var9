#include <filesystem>
#include <fstream>
#include "input.h"
#include <iostream>
#include "cw4_functions.h"


bool IsDataCorrectCW4(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    std::string test_string{};
    if (file.eof())
    {
        std::cout << "���� ����!";
        return false;
    }

    return true;
}

std::string CheckFileCW4()
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
        else if (!IsDataCorrectCW4(file))
        {
            std::cout << "������ �����������!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } while (!isLoaded);

    std::cout << "���� ������!" << std::endl;
    file.close();

    return path;
}

void getTextFromFile(std::string& text, std::string& path)
{
    std::ifstream file(path);
    std::string input{};

    while (!file.eof())
    {
        getLine(file, input, CW4_INPUT, FILE_INPUT);
        text += (input);
        if (!file.eof())
            text += '\n';
    }

    std::cout << "����� ��������!" << std::endl;
    file.close();
}

void saveToFile(const std::string& restoredText, const std::string& modifiedText, const std::string& text, int save_choice)
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
        getLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);
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
    } while (!isOpened);


    if (save_choice == SAVE_RESTORED)
        file << restoredText;

    else if (save_choice == SAVE_MODIFIED)
        file << modifiedText;

    else if (save_choice == SAVECW4)
        file << text;

    std::cout << "������� ��������� � " << path << std::endl;
}