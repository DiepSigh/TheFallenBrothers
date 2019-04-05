#pragma once

#include "Game.h"

class Hero {
public:
	Hero();

	void dead() { h_alive = false; }
	void alive() { h_alive = true; }

	void display(); //Displays level and hp;
	void levelUp(); //raises hero stats and resets exp. Called in gainEXP()
	int damage(int value); //takes HP from hero taking defence into account
	void gainEXP(int value); //adds value to exp of hero
	void gainHP(int value); //called for potions
	void resetHP() { h_hp = h_maxHP; }
	void bossKill() { h_bossCount++; }

	//Setters
	void setName(string name);
	
	//Getters
	string getName() { return h_name; }
	int getLevel() { return h_level; }
	bool getAlive() { return h_alive; }
	int bossCount() { return h_bossCount; }
	int getMaxHP() { return h_maxHP; }
	int getHP() { return h_hp; }
	int getAtt() { return h_attack; }

private:
	string h_name;
	bool h_alive;
	int h_bossCount; //Number of bosses defeated

	int h_level;
	int h_exp;
	//Stats
	int h_maxHP;
	int h_hp;
	int h_attack;
	int h_defence;
};

