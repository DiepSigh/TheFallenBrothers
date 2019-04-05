#pragma once

#include "Game.h"
//for map array
const int ROWS = 6;
const int COLS = 32;

class Map {
public:
	Map();
	
	void drawMap(); //Displays the map using the legend.
	char legend(int k); //Legend for map array

	void move(Hero &hero, Inventory &inv, bool &MapInteraction); //WASD movement, i for inventory, MapInteraction changes to false when in fights.

	void moveSouth();
	void moveEast();
	void moveWest();
	void moveNorth();

private:
	int NPCCount; //counts which NPC interaction to go through

	//Coordinates of hero
	int heroPosX;
	int heroPosY;

	//Used in legend function
	const char HERO = 'o';
	const char TREE = 'T';
	const char NPC = 'n';
	const char STORE = 'm';
	const char BOSS = 'b';

	//Map array
	// 0 = Space
	// 1 = Player
	// 2 = NPC
	// 3 = Trees/Walls
	// 4 = Store
	// 5 = Boss
	int map[ROWS][COLS] = {
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
	{ 3, 1/*PLAYER*/, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
	{ 3, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 3, 3, 3 },
	{ 3, 0, 3, 3, 3, 3, 3, 4/*MERCH*/, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5/*BOSS*/, 3, 3 },
	{ 3, 2/*NPC*/, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
	};
};
