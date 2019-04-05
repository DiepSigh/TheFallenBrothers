#include "Hero.h"
#include "Monsters.h"
#include "Inventory.h"

void welcome(Hero &hero); //Welcomes the hero and introduces the game
int choiceSelect(string prompt1, string prompt2, string prompt3); //Returns a value based on the choice chosen
void clearScreen(); //Clears screen. Global function.

void monsterEncounter(Hero &hero, Inventory &inv);
void spawnMonster(Hero &hero, Inventory &inv);
void bossFight(Hero &hero, Inventory &inv);

void battleStart(Hero &hero, Monster &monster, Inventory &inv); //battle.cpp

void welcome(Hero &hero) {

	string sTemp; // Stores values temporarily to set Hero values
	int nTemp; // Stores a temp number value
	string choice; // Stores the answer of the player
	bool stay = true; // Determines whether to continue the story based on conditions 

	cout << "Welcome to The Fallen Brother\n";
	cout << "(For the sake of not breaking anything and for your best experience do not enter any inputs with spaces thx).\n\n";

	do {
		cout << "Young one, what is your name?\n";
		//Input and Set
		cin >> sTemp;
		hero.setName(sTemp);
		//Confirm and Input
		cout << "So... your name is " << hero.getName() << ". Is this correct?\n";
		cin >> choice;
		//Continue if yes or similar else loop
		if (choice == "yes" || choice == "Yes" || choice == "y" || choice == "Y") {
			cout << "Let us begin our journey...\n";
			stay = false;
		}
		else {
			cout << "Tell me your name... ";
		}
	} while (stay);

	cout << "\n\n";
	//Mini choice tutorial
	cout << "In this game, you, Sir " << hero.getName() << ", represent 'o'; a hero. \n";
	nTemp = choiceSelect(
		"I am not a Sir, I am a Madam",
		"I'd like to be addressed as...",
		"Continue.");
	switch (nTemp) {
	case 1:
		cout << "Oh, I do apologize, Madam " << hero.getName() << ". Moving on...\n";
		break;
	case 2:
		cout << "Oh, what would you like to be addressed as?\n";
		cin >> sTemp;
		cout << "OK, " << sTemp << " " << hero.getName() << ". \n";
		break;
	case 3:
		break;
	default:
		"Please enter one of the numbers to select the choices for the rest of the game...";
	}
	//Map move tutorial
	cout << "'T' represent trees and 'n' reprsent my brothers in this game.\n";
	cout << "To move North, West, South, and East, we'll be using the WASD input respectively.\n";
	cout << "Please move towards my first brother to the south to interact with him.\n";
	cout << "He will show you the way. I will meet with you again the distant future.\n";
	cout << "(example: type 's' and press enter to move south)\n";
}

int choiceSelect(string prompt1, string prompt2, string prompt3) {
	cout << "\n";
	cout << "1. " << prompt1 << endl;
	cout << "2. " << prompt2 << endl;
	cout << "3. " << prompt3 << endl;
	char c = '0';
	cin >> c;
	clearScreen();
	switch(c) {
	case '1': 
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	default:
		return 0;
	}
}

inline void clearScreen() {
	system("CLS");
}

//Chance to encounter a monster.
void monsterEncounter(Hero &hero, Inventory &inv) {
	int rng = (rand() % 10) + 1;

	if (rng <= 2) {
		spawnMonster(hero, inv);
	}
}
//Generates a random monster based on level
void spawnMonster(Hero &hero, Inventory &inv) {
	int id = 0;
	Monster monster;
	//Higher the level, more difficult the monster.
	if (hero.getLevel() <= 5) {
		id = (rand() % 3) + 1;
	}
	else {
		id = (rand() % 5) + 4;
	}
	//Sets all the monster's stats
	monster.set(id);
	clearScreen();
	cout << "You encountered " << monster.getName() << "!\n";
	//battle procedure in battle.cpp
	battleStart(hero, monster, inv);
}

void bossFight(Hero &hero, Inventory &inv) {
	clearScreen();
	Monster boss;
	system("Color 0C");
	//Boss ID's start at 10
	boss.set(hero.bossCount()+10);
	cout << "An epic fight is about to begin.\n";
	cout << "You approach " << boss.getName() << ".\n";
	battleStart(hero, boss, inv);
	//Increase boss kill count for harder bosses
	if (boss.getAlive() == false) {
		hero.bossKill();
		if (hero.bossCount() >= 4) {
			cout << "You're a hacker!!!\n";
			cout << "There's nothing else left in this game for you to do.\n";
		}
		else {
			cout << "You defeated the dark lord... Maybe a stronger one will appear...\n";
		}
	}
	system("Color 0E");
}