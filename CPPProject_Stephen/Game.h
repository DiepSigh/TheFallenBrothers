#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>
#include <math.h>
#include <conio.h>
#include <windows.h>

using namespace std;

//events.cpp
void clearScreen();
int choiceSelect(string prompt1, string prompt2, string prompt3);

class Game {
public:
	Game();
	bool gameOver();
};