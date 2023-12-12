#ifndef INPUT_H
#define INPUT_H

#include <conio.h>
#include <string>
#include <vector>


constexpr auto KEY_ESC = 0x1B;
constexpr auto KEY_1 = 0x31;
constexpr auto KEY_2 = 0x32;
constexpr auto KEY_3 = 0x33;
constexpr auto KEY_4 = 0x34;
constexpr auto KEY_5 = 0x35;
constexpr auto KEY_6 = 0x36;
constexpr auto KEY_7 = 0x37;
constexpr auto KEY_8 = 0x38;
const double DBL_WRONG = 100000000000000000;

enum InputMenu {
    FILE_INPUT = KEY_1,
    MANUAL_INPUT = KEY_2,
    MODUL_TESTS = KEY_3,
    RANDOM_INPUT = KEY_4
};

enum MenuCW {
    CW1 = KEY_1,
    CW2 = KEY_2,
    CW3 = KEY_3,
    CW4 = KEY_4,
    QUIT = KEY_ESC
};

enum BoolMenu {
    YES = KEY_1,
    NO = KEY_2
};

enum BoolInput {
    WITHOUT_DIGITS,
    WITH_DIGITS,
    ONLY_DIGITS,
    ALMOST_ALL_DIGITS,
    CW4_INPUT
};

enum MainMenuCW1 {
    SEARCH_BY_ROUTE_NUMBER = KEY_1,
    SEARCH_BY_START_YEAR = KEY_2,
    SEARCH_BY_MILEAGE = KEY_3,
    SHOW_ALL = KEY_4,
    SAVECW1 = KEY_5
};

enum EmployeeChoiceCW2 {
    HOURLY_EMPLOYEE = KEY_1,
    STATE_EMPLOYEE = KEY_2
};

enum MainMenuCW2 {
    SHOW = KEY_1,
    SAVECW2 = KEY_2
};

enum MainMenuCW3 {
    SAVECW3 = KEY_2
};

enum MainMenuCW4 {
    SHOW_ORIGINAL = KEY_1,
    SHOW_CONTEXTS = KEY_2,
    SAVE_ORIGINAL = KEY_3,
};

enum SORTS {
    BUBBLE_SORT,
    SELECTION_SORT,
    INSERTION_SORT,
    SHELL_SORT,
    QUICK_SORT
};

int getKey(int key_min, int key_max);

int getPosInt();
int getInt();
int getRandInt(int lowBound, int upBound);

double getDouble();
double getPosDouble();

bool getBool();

std::string getLine(std::istream& _Input, std::string& line, int num_exists, int isInput);

#endif