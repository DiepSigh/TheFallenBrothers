#include "Hero.h"
#include "Inventory.h"
#include "Map.h"

//Events.cpp
void monsterEncounter(Hero &hero, Inventory& inv);
void bossFight(Hero &hero, Inventory &inv);
//NPC.cpp
void NPCInteract(int &count, Hero &hero, Inventory &inv);
void Merchant(Inventory &inv);

// 0 = Space
// 1 = Player
// 2 = NPC
// 3 = Trees/Walls
// 4 = Store
// 5 = Boss

Map::Map() {
	NPCCount = 0; //counts which NPC interaction to go through

	heroPosX = 1;
	heroPosY = 1;
}

void Map::drawMap() {
	cout << endl << endl;
	char temp;

	for (int row = 0; row < ROWS; row++) {
		cout << "\t";
		//loops through map and displays based on legend
		for (int col = 0; col < COLS; col++) {
			temp = legend(map[row][col]);
			cout << temp;
		}
		cout << endl;
	}
}

char Map::legend(int k) {
	switch (k) {
	case 0:
		return ' ';
		break;
	case 1:
		return HERO;
		break;
	case 2:
		return NPC;
		break;
	case 3:
		return TREE;
		break;
	case 4:
		return STORE;
		break;
	case 5:
		return BOSS;
		break;
	default:
		return 'P';
	}
}

void Map::move(Hero &hero, Inventory &inv, bool &MapInteraction) {

	char input;

	cout << endl;
	cin >> input;

	switch (input) {
	case 'w':
		for (int i = 0; i < ROWS; i++) {
			//if next position is a tree, don't move and output msg.
			if (map[heroPosY-1][heroPosX] == 3) {
				cout << endl;
				clearScreen();
				cout << "There's a tree there. You do not enter the tree." << endl << endl;
				return;
			}
		}
		moveNorth();
		monsterEncounter(hero, inv);
		break;
	case 'a':
		for (int i = 0; i < ROWS; i++) {
			if (map[heroPosY][heroPosX - 1] == 3) {
				cout << endl;
				clearScreen();
				cout << "There's a tree there. You do not enter the tree." << endl << endl;
				return;
			}
			//If next position is merchant
			if (map[heroPosY][heroPosX-1] == 4) {
				MapInteraction = false;
				Merchant(inv);
				MapInteraction = true;
				return;
			}
		}
		moveWest();
		monsterEncounter(hero, inv);
		break;
	case 's':
		for (int i = 0; i < COLS; i++) {
			if ((map[heroPosY + 1][heroPosX] == 3)) { //Checks if there's a tree below hero
				cout << endl;
				clearScreen();
				cout << "There's a tree there. You do not enter the tree." << endl << endl;
				return;
			}
			//If next position is NPC
			if (map[heroPosY + 1][heroPosX] == 2) {
				MapInteraction = false;
				NPCInteract(NPCCount, hero, inv);
				MapInteraction = true;
				return;
			}
		}
		moveSouth();
		monsterEncounter(hero, inv);
		break;
	case 'd':
		for (int i = 0; i < COLS; i++) {
			if ((map[heroPosY][heroPosX + 1] == 3)) { 
				cout << endl;
				clearScreen();
				cout << "There's a tree there. You do not enter the tree." << endl << endl;
				return;
			}
			//If next position is the boss
			if (map[heroPosY][heroPosX+1] == 5) {
				MapInteraction = false;
				bossFight(hero, inv);
				MapInteraction = true;
				return;
			}
		}
		moveEast();
		monsterEncounter(hero, inv);
		break;
	case 'i':
		//Opens inventory
		inv.openInventory(hero);
		clearScreen();
		break;
	default:
		clearScreen();
		drawMap();
		move(hero, inv, MapInteraction);
	}

}

void Map::moveNorth() {
	//Change current spot to empty space
	map[heroPosY][heroPosX] = 0;
	//Move Hero
	heroPosY -= 1;
	//Display moved Hero
	map[heroPosY][heroPosX] = 1;
	clearScreen();
}

void Map::moveWest() {
	map[heroPosY][heroPosX] = 0;
	heroPosX -= 1;
	map[heroPosY][heroPosX] = 1;
	clearScreen();
}

void Map::moveSouth() {
	map[heroPosY][heroPosX] = 0;
	heroPosY += 1;
	map[heroPosY][heroPosX] = 1;
	clearScreen();
}

void Map::moveEast() {
	map[heroPosY][heroPosX] = 0;
	heroPosX += 1;
	map[heroPosY][heroPosX] = 1;
	clearScreen();
}