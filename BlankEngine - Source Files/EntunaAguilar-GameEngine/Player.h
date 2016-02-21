#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Unit.h"
class Player : public Unit
{
public:
	Player(const string& name, float health, float mana, float agility, float strength, float dexterity, float attack, float magic, float luck, int level);
	~Player();
	bool BasickAttack(Unit* target) override;

private:
	Player(){};
	Player(const Player&){};
};

#endif

