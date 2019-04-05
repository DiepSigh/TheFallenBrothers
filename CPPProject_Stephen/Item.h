#pragma once

#include "Game.h"

class Item {
public:
	Item();
	Item(int id);

	//Getters
	string getName() { return i_name; }
	int getID() { return i_id; }
	int getRestore() { return i_restore; }
	int getType() { return i_type; }

private:
	string i_name;
	int i_id;
	int i_restore;
	int i_type;
	//Types:
	// 1 - HP Potions
};