#include "Hero.h"


Hero::Hero() {
	
	h_name = "Hero";
	h_alive = true;
	h_bossCount = 0;

	h_level = 1;
	h_exp = 0;

	h_maxHP = 15;
	h_hp = 15;
	h_attack = 5;
	h_defence = 2;
}

void Hero::display() {
	cout << getName() << endl;
	cout << "Level: " << getLevel() << endl;
	cout << "HP: " << getHP() << endl;
}

void Hero::levelUp() {
	h_level++;
	//raise stats
	h_maxHP += rint(h_maxHP * 0.3);
	h_attack += rint(h_attack * 0.2);
	h_defence += rint(h_defence * 0.2);
	//reset HP and lv
	h_hp = h_maxHP;
	h_exp = 0;
	cout << "You leveled up!\n";
}

//value is monster's attack
int Hero::damage(int value) {
	int dmg = 0;
	dmg = (rand() % (value) + (value-1)) - h_defence;
	if (dmg <= 0) {
		dmg = 1;
	}
	h_hp -= dmg;

	return dmg;
}

void Hero::gainEXP(int value) {
	h_exp += value;
	cout << "You gained " << value << " EXP.\n";
	//Level up algorithm
	if (h_exp >= (h_level * 5)) {
		//Take remaining exp if any to next level
		if (h_exp > (h_level * 3)) {
			int temp = (h_exp % (h_level * 3));
			levelUp();
			h_exp += temp;
		}
		else {
			levelUp();
		}
	}
}

void Hero::gainHP(int value) {
	h_hp += value;
	//HP cannot be more than max
	if (h_hp > h_maxHP) {
		h_hp = h_maxHP;
	}
}

void Hero::setName(string name) {
	h_name = name;
}