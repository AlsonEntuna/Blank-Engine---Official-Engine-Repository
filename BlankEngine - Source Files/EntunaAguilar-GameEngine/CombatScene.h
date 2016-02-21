#ifndef _COMBAT_SCENE_H_
#define _COMBAT_SCENE_H_

#include <SFML\Graphics.hpp>
#include <vector>
#include "SceneManager.h"
#include <iostream>

using namespace std;

class CombatScene : public Screen
{
public:
	CombatScene()
	{
		this->SetName("CombatScene");
	}

	void OnEnable()
	{

	}
	void Start()
	{

	}

	void Update(float dt)
	{

	}

	void DrawScene(sf::Window& window)
	{
		sf::RenderWindow* rw = (sf::RenderWindow*)&window;
	}

	void Shutdown()
	{

	}
private:
};
#endif