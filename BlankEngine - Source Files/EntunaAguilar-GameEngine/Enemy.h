#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Unit.h"
#include <string>

using namespace std;

class Enemy : public Unit
{
public:
	Enemy(const string& name, float health, float mana, float strength, float attack, float magic, float agility, float dexterity, float luck, int level);
	~Enemy();

	bool BasickAttack(Unit* target) override;

private:
	Enemy(){};
	Enemy(const Enemy&){}; 
};

#endif

