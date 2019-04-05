// Start Date: 02.23.18
// Stephen Diep

//Files:
//Headers:
//	Game.h 
//	Hero.h
//	Inventory.h
//	Item.h
//	Map.h
//	Monsters.h

//CPP's:
//	battle.cpp - battle algorithm
//	events.cpp - contains most of not all of events. most functions are here unrelated to anything else
//	game.cpp - main loop of the game + gameover
//	hero.cpp - contains hero constructor and related functions
//	inventory.cpp - handles inventory related functions
//	NPC.cpp - NPC related interactions
//	main.cpp - runs the game
//	map.cpp - draws the map, handles main input, leads to other events
//	monster.cpp - monster database

#include "Game.h"
int main()
{
	srand(static_cast<unsigned int> (time(0))); //seed
	Game game;
	
    return 0;
}

