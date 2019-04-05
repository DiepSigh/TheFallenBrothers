#include "Monsters.h"

Monster::Monster() {
	m_name = "Richard";
	m_alive = true;

	m_hp = 1;
	m_attack = 1;
	m_defence = 1;
	m_exp = 1;
}
//value is hero's attack
int Monster::damage(int value) {
	int dmg = 0;
	dmg = (rand() % (value+2) + (value)) - m_defence;
	m_hp -= dmg;
	if (dmg <= 0) {
		dmg = 1;
	}
	return dmg;
}

void Monster::set(int id) {
	switch (id) {
	case 1:
		m_name = "Slime";
		m_hp = 8;
		m_attack = 5;
		m_defence = 2;
		m_exp = 5;
		break;
	case 2:
		m_name = "Mushroom";
		m_hp = 10;
		m_attack = 6;
		m_defence = 2;
		m_exp = 7;
		break;
	case 3:
		m_name = "Snail";
		m_hp = 14;
		m_attack = 3;
		m_defence = 4;
		m_exp = 5;
		break;
	case 4:
		m_name = "Skeleton";
		m_hp = 20;
		m_attack = 10;
		m_defence = 3;
		m_exp = 15;
		break;
	case 5:
		m_name = "Bandit";
		m_hp = 22;
		m_attack = 8;
		m_defence = 8;
		m_exp = 18;
		break;
	case 10:
		m_name = "Dark Overlord of the Universe";
		m_hp = 200;
		m_attack = 30;
		m_defence = 20;
		m_exp = 400;
		break;
	case 11:
		m_name = "Dark Overlord of the Universe's Father";
		m_hp = 600;
		m_attack = 50;
		m_defence = 30;
		m_exp = 800;
		break;
	case 12:
		m_name = "Stephen";
		m_hp = 3000;
		m_attack = 400;
		m_defence = 400;
		m_exp = 5000;
		break;
	case 13:
		m_name = "Richard Reborn";
		m_hp = 10000;
		m_attack = 3000;
		m_defence = 3000;
		m_exp = 3000;
		break;
	}

}

