#include "Unit.h"
#include <string>

using namespace std;

Unit::Unit()
{
	this->m_Name = "Default";
	this->m_MaxHealth = 0.0f;
	this->m_CurrentHealth = 0.0f;
	this->m_MaxMana = 0.0f;
	this->m_CurrentMana = 0.0f;
	this->m_Strength = 0.0f;
	this->m_Attack = 0.0f;
	this->m_Agility = 0.0f;
	this->m_Dexterity = 0.0f;
	this->m_Luck = 0.0f;
	this->m_Level = 0;
}


Unit::~Unit()
{
}

void Unit::InitializeUnit(const string& name, float health, float mana, float strength, float attack, float magic, float agility, float dexterity, float luck, int level)
{
	m_Name = name;
	m_MaxHealth = m_CurrentHealth = health;
	m_MaxMana = m_CurrentMana = mana;
	m_Strength = strength;
	m_Attack = attack;
	m_Magic = magic;
	m_Agility = agility;
	m_Dexterity = dexterity;
	m_Luck = luck;
	m_Level = level;
}

float Unit::getStat(Unit::STAT stat)
{
	if (stat == Unit::STAT::HEALTH) return m_CurrentHealth;
	else if (stat == Unit::STAT::MANA) return m_CurrentMana;
	else if (stat == Unit::STAT::AGILITY) return m_Agility;
	else if (stat == Unit::STAT::ATTACK) return m_Attack;
	else if (stat == Unit::STAT::LUCK) return m_Luck;
	else if (stat == Unit::STAT::DEXTERITY) return m_Dexterity;
	else if (stat == Unit::STAT::MAGIC) return m_Magic;
	else if (stat == Unit::STAT::STRENGTH) return m_Strength;
}

int Unit::getLevel()
{
	return m_Level;
}
bool Unit::IsAlive()
{
	return m_CurrentHealth > 0;
}

string Unit::getName()
{
	return m_Name;
}
