#include "Game.h"
#include "Hero.h"
#include "Inventory.h"
#include "Map.h"

void welcome(Hero &hero); //Welcomes the hero and introduces the game. event.cpp

Game::Game(){
	//objects
	Hero hero;
	Map board;
	Inventory inv;
	//Changes console color
	
	system("Color 0E");
	bool gg = false;
	
	welcome(hero);
	bool MapInteraction = true;
	do {
		//Main loop of the game
		hero.display();
		board.drawMap();
		board.move(hero, inv, MapInteraction);
		//If player dies, prompt to continue
		if (hero.getAlive() == false) {
			gg = gameOver();
			if (!gg) {
				hero.resetHP();
				hero.alive();
			}
		}
	} while (MapInteraction && gg == false);
}

bool Game::gameOver() {
	
	string choice;
	cout << "All hope is lost. Darkness envelopes you. Stay determined hero!\n\n";
	cout << "Would you like to continue?\n";
	cin >> choice;
	if (choice == "yes" || choice == "Yes" || choice == "y" || choice == "Y") {
		return false;
	}
	else if (choice == "no" || choice == "No" || choice == "n" || choice == "N") {
		cout << "You drown yourself deeper into the darkness.\n";
		cout << "Press any key to continue.";
		_getch();
		return true;
	}
	else {
		cout << "You failed to enter yes and plummet deeper into the darkness.\n";
		cout << "Press any key to continue.";
		_getch();
		return true;
	}
}