#ifndef _CHARACTER_MANAGER_H_
#define _CHARACTER_MANAGER_H_

#include "GameObject.h"
#include "Component.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <map>
#include <sstream>

using namespace std;

class CharacterManager
{
public:
	void SetPlayer(GameObject* selected)
	{
		player = selected;
	}

	GameObject* GetPlayer()
	{
		return player;
	}

	static CharacterManager& Instance()
	{
		static CharacterManager instance;
		return instance;
	}
private:
	GameObject* player = new GameObject();	
};

#endif