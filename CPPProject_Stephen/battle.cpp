#include "Game.h"
#include "Monsters.h"
#include "Hero.h"
#include "Inventory.h"

void battleStart(Hero &hero, Monster &monster, Inventory &inv); //Battle menu. Loops while hero or monster is alive.
void fight(Hero &hero, Monster &monster); //Called when player chooses to attack
void whoDied(Hero &hero, Monster &monster, bool &alive); //Checks to see if monster or hero died. Sets alive to false if so.
void hurtHero(Hero &hero, Monster &monster); //Damage to hero from monster.
bool flee(); //Chance to flee. Returns true if lucky.

void battleStart(Hero &hero, Monster &monster, Inventory &inv) {
	bool alive = true; //Used for loop
	char temp = '0'; //Takes input
	do {
		cout << endl;
		cout << hero.getName() << endl;
		cout << "HP: " << hero.getHP() << endl << endl;
		cout << monster.getName() << endl;
		cout << "HP: " << monster.getHP() << endl;
		cout << "\n1. Attack\n";
		cout << "2. Use Potion\n";
		cout << "3. Flee\n";
		cin >> temp;
		switch (temp) {
		case '1':
			fight(hero, monster);
			whoDied(hero, monster, alive);
			break;
		case '2':
			clearScreen();
			//Uses last potion in inventory if not empty.
			if (!inv.isEmpty()) {
				inv.useItem(inv.getInv().back(), hero);
			}
			break;
		case '3':
			clearScreen();
			//Chance to flee from fight.
			if (flee()) {
				alive = false;
				cout << "You have fled.\n";
			}
			else {
				cout << "You failed to flee.\n";
				hurtHero(hero, monster);
				whoDied(hero, monster, alive);
			}
			break;
		default:
			clearScreen();
			cout << "Invalid option selected.\n";
			break;
		}
	} while (alive);
}

void fight(Hero &hero, Monster &monster) {
	int temp = 0;
	clearScreen();
	//Damage monster based on hero's attack
	temp = monster.damage(hero.getAtt());
	cout << hero.getName() << " attacks. Deals " << temp << " damage.\n";
	if (monster.getHP() <= 0) {
		monster.dead();
	}
	else {
		//Similar to above but in a function
		hurtHero(hero, monster);
	}
}

void whoDied(Hero &hero, Monster &monster, bool &alive) {
	if (monster.getAlive() == false) {
		cout << "You have defeated " << monster.getName() << ".\n";
		hero.gainEXP(monster.getEXP());
		alive = false;
	}
	if (hero.getAlive() == false) {
		cout << "You have died.\n";
		alive = false;
		//GameOver in game.cpp loop
	}
}

void hurtHero(Hero &hero, Monster &monster) {
	int temp = 0;
	//Damage to hero based on monster's attack
	temp = hero.damage(monster.getAtt());
	cout << monster.getName() << " attacks. Deals " << temp << " damage.\n";
	if (hero.getHP() <= 0) {
		hero.dead();
	}
}

bool flee() {
	int rng = (rand() % 6) + 1;
	if (rng == 6) {
		return true;
	}
	else {
		return false;
	}
}