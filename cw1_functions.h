#ifndef CW1_FUNCTIONS_H
#define CW1_FUNCTIONS_H

#include "bus.h"

bool allocateArray(Bus* buses, int amount);
void showBuses(Bus* buses, int amount);
void fillBuses(Bus* buses, int amount);
void searchByRouteNumber(Bus* buses, Bus* ansBuses, int amount, int isTest);
void searchByStartYear(Bus* buses, Bus* ansBuses, int amount, int isTest);
void searchByMileage(Bus* buses, Bus* ansBuses, int amount, int isTest);
bool isListEmpty(Bus* buses, int amount);

#endif