#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(const string& name, float health, float mana, float agility, float strength, float dexterity, float attack, float magic, float luck, int level)
{
	Unit::InitializeUnit(name, health, mana, strength, attack, magic, agility, dexterity, luck, level);
}


Player::~Player()
{
}

bool Player::BasickAttack(Unit* target)
{
	cout << "Attacks: " + target->getName();
	return false;
}
