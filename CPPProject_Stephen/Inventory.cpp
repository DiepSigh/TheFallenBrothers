#include "Inventory.h"

Inventory::Inventory() {
	open = false;
	gold = 0;
	items = 0;
}

void Inventory::openInventory(Hero &hero) {
	clearScreen();
	bool open = true;
	int nTemp = 0; //holds choice
	do {
		cout << "Gold: " << getGold() << endl;
		cout << "Potions: " << getItems() << endl;
		nTemp = choiceSelect("View Items",
			"Use Potion",
			"Exit Inventory");
		switch (nTemp) {
		case 1:
			listItems();
			break;
		case 2:
			if (!isEmpty()) {
				useItem(inventory.back(), hero);
			}
			break;
		case 3:
			open = false;
			break;
		}
	} while (open);
}

void Inventory::listItems() {
	//if not empty go through list of items and displays.
	if (!isEmpty()) {
		for (iter = inventory.begin(); iter != inventory.end(); iter++) {
			cout << iter->getName() << endl;
		}
	}
}

void Inventory::useItem(Item item, Hero &hero) {
	//Type 1 = HP Potion
	if (item.getType() == 1) {
		//If Hero HP is not maxed
		if (hero.getHP() != hero.getMaxHP()) {
			hero.gainHP(item.getRestore());
			inventory.pop_back();
			items -= 1;
			cout << "You used " << item.getName() << "." << endl;
			cout << "HP: " << hero.getHP() << endl;
		}
		else {
			cout << "You are already at full HP.\n";
		}
	}
}

bool Inventory::isEmpty() {
	if (inventory.empty()) {
		cout << "Your inventory is empty.\n";
		return true;
	}
	else {
		return false;
	}
}

void Inventory::collectItem(Item item) {
	inventory.push_back(item);
	items += 1;
	cout << "+1 " << item.getName() << ".\n";
}

void Inventory::collectGold(int amount) {
	gold += amount;
	cout << "\n+" << amount << " gold.\n";
}

void Inventory::spendGold(int amount) {
	gold -= amount;
	cout << "\n-" << amount << " gold.\n";
}