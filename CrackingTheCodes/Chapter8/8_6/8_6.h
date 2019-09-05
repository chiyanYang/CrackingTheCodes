#pragma once
#include "../Ch8Common.h"

void test8_6();

void towersOfHanoi(stack<int> towers[3], int source, int des, int middle);
void moveHanoi(stack<int> towers[3], int stackCountToMove, int source, int des, int middle);

void fillDestinationTower(stack<int>& tower, int num);
void printTotwers(stack<int> towers[3]);