#pragma once
#ifndef _SPRITERENDERER_H_
#define _SPRITERENDERER_H_
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <string>
#include <iostream>
#include "Component.h"
#include "GameObject.h"
using namespace std;
class SpriteRenderer : public Component
{
public:
	SpriteRenderer(int id);
	~SpriteRenderer();
	sf::Texture SpriteTexture;
	sf::Sprite  Sprite;
	void setSprite(string filename);
	void Update() override;
};

#endif

