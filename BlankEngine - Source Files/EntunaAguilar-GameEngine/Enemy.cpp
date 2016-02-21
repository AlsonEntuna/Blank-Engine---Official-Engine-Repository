#include "Enemy.h"
#include <iostream>

using namespace std;
Enemy::Enemy(const string& name, float health, float mana, float strength, float attack, float magic, float agility, float dexterity, float luck, int level)
{
	Unit::InitializeUnit(name, health, mana, strength, attack, magic, agility, dexterity, luck, level);
}


Enemy::~Enemy()
{
}

bool Enemy::BasickAttack(Unit* target)
{
	cout << this->getName() << " attacks" << target->getName() << endl;

	return false;
}
