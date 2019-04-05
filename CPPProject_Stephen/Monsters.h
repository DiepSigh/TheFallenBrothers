#pragma once

#include "Game.h"

class Monster {
public:
	Monster();

	int damage(int value); //deals dmg to monster taking defence into account
	void dead() { m_alive = false; }

	//Sets the stats of a monster based on ID
	void set(int id);

	//Getters
	bool getAlive() { return m_alive; }
	string getName() { return m_name; }
	int getHP() { return m_hp; }
	int getAtt() { return m_attack; }
	int getDef() { return m_defence; }
	int getEXP() { return m_exp; }

private:

	bool m_alive;
	string m_name;
	
	int m_hp;
	int m_attack;
	int m_defence;
	int m_exp;
};