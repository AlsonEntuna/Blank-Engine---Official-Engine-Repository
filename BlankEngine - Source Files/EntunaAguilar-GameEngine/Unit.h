#pragma once

#ifndef _UNIT_H_
#define _UNIT_H_

#include <string>
#include "GameObject.h"

using namespace std;

class Unit : public GameObject
{
public:
	enum STAT
	{
		HEALTH,
		MANA,
		STRENGTH,
		AGILITY,
		ATTACK,
		LUCK,
		DEXTERITY,
		MAGIC
	};
	Unit(); 
	~Unit();

	void InitializeUnit(const string& name, float health, float mana, float strength, float attack, float magic, float agility, float dexterity, float luck, int level);
	virtual bool BasickAttack(Unit* target) = 0;

	bool   IsAlive();
	string getName();
	float  getStat(STAT stat);
	int    getLevel();
private:
	string m_Name;
	float  m_MaxHealth;
	float  m_CurrentHealth;
	float  m_MaxMana;
	float  m_CurrentMana;
	float  m_Strength;
	float  m_Attack;
	float  m_Magic;
	float  m_Agility;
	float  m_Dexterity;
	float  m_Luck;
	int	   m_Level;


};

#endif

