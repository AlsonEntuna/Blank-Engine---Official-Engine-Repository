#pragma once
#ifndef _BLANK_ENGINE_H_
#define _BLANK_ENGINE_H_

#include "SFML\Window.hpp"
#include "SFML\OpenGL.hpp"

// Engine Components
#include "Component.h"
#include "GameObject.h"
#include <iostream>
#include "SpriteRenderer.h"
#include "Collision.h"
#include "Layer.h"
#include "Animator.h"
#include "Animation.h"
#include "Sound.h"
#include "Movement.h"
#include "SceneManager.h"
#include "MainMenuScene.h"
#include "ExplorationScene.h"
#include "CombatScene.h"
#include "CharacterManager.h"

// C++ Libraries
#include <vector>
#include <iostream>

int windowWidth;
int windowHeight;

// GameObjects
vector<GameObject*> GameObjects;
vector<sf::Drawable*> Drawables;

void SetScreenDimensions(int w, int h)
{
	windowWidth = w;
	windowHeight = h;
}
void AddGameObject(GameObject* object)
{
	GameObjects.push_back(object);
}
void AddDrawable(sf::Drawable* drawable)
{
	Drawables.push_back(drawable);
}
using namespace std;
#endif
