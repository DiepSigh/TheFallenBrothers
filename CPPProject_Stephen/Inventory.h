#pragma once

#include "Game.h"
#include "Item.h"
#include "Hero.h"

class Inventory {
public:
	Inventory();

	void openInventory(Hero &hero); //Opens inventory menu
	void listItems(); //Lists items in inventory if any
	void useItem(Item item, Hero &hero); //Uses a potion

	bool isEmpty(); //Returns true if inventory is empty else false...

	void collectItem(Item item); //Adds item to inventory and increases count
	void collectGold(int amount); //Adds amount to gold
	void spendGold(int amount); //Subtracts amount from gold

	//Getters
	vector<Item> getInv() { return inventory; }
	bool getOpen() { return open; }
	int getGold() { return gold; }
	int getItems() { return items; }

private:
	vector<Item> inventory;
	vector<Item>::iterator iter;

	bool open;
	int gold;
	int items;
};