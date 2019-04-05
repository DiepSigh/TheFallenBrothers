#include "Hero.h"
#include "Inventory.h"

void NPCInteract(int &count, Hero &hero, Inventory &inv);
void Merchant(Inventory &inv);

void NPCInteract(int &count, Hero &hero, Inventory &inv) {

	clearScreen();
	if (hero.bossCount() == 0) {
		switch (count) {
		case 0:
			//Story
			cout << "\"Ah yes... young one. My brother has told me much about you.\n";
			cout << "In this game, your goal is to restore order by bringing down the dark lord.\n";
			cout << "He has reduced the population of my breathren to only us brothers after\n";
			cout << "capturing all of our sisters...\n";
			cout << "You will encounter monsters, evil beings, and more on your journey.\n";
			cout << "\tI wish you luck, " << hero.getName() << ".\n\n";
			cout << "Please see my other brother to the right. He can supply you with the goods.\n";
			cout << "Here is a bit of gold and items you may access through your inventory by entering 'i'\"\n";
			inv.collectGold(100);
			inv.collectItem(Item(1));
			inv.collectItem(Item(1));
			inv.collectItem(Item(1));
			count++;
			break;
		case 1:
			cout << "I have nothing else to give you...\n";
			count++;
			break;
		case 2:
			cout << "Can you leave me alone?\n";
			count++;
			break;
		case 5:
			cout << "You really have a lot of time on your hands don't you.";
			break;
		default:
			count++;
			cout << "...";
			break;
		}
	}
	else {
		cout << "You have avenged us! You will forever be remembered, " << hero.getName() << ".";
		inv.collectGold(1000);
	}
}

void Merchant(Inventory &inv) {
	clearScreen();
	cout << "I'm not a masochist I swear...\n";
	cout << "Welcome to my store\n";
	int temp = 0;
	bool shopping = true;
	do {
		cout << "Gold: " << inv.getGold() << endl;
		temp = choiceSelect("20g - Potion", "60g - Hi-Potion", "Exit Store");
		switch (temp) {
		case 1:
			if (inv.getGold() >= 20) {
				cout << "You bought Potion.\n";
				inv.collectItem(Item(1));
				inv.spendGold(20);
				break;
			}
			else {
				cout << "You don't have enough gold.\n";
				break;
			}
		case 2:
			if (inv.getGold() >= 60) {
				cout << "You bought Hi-Potion.\n";
				inv.collectItem(Item(2));
				inv.spendGold(60);
				break;
			} 
			else {
				cout << "You don't have enough gold.\n";
				break;
			}
		case 3:
			shopping = false;
		}
	} while (shopping);
}