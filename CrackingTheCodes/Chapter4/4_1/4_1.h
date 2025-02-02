#pragma once
#include "../Ch4Common.h"

void test4_1();

bool existRouteInTwoNodes(directedGraph &g, int n1, int n2);
bool existConnection(node* nodeStart, int target);

bool existRouteInTwoNodes_UseQueue(directedGraph &g, int n1, int n2);
bool existConnection_UseQueue(directedGraph &g, int n1, int n2);
