#pragma once
#ifndef _LAYER_H_
#define _LAYER_H_
#include <SFML\Graphics.hpp>
#include <vector>
using namespace std;
class Layer
{
public:
	Layer();
	~Layer();
	
	void Render(sf::RenderWindow *window);
	void AddDrawable(sf::Sprite* drawable);
	vector<sf::Sprite*> GetDrawables();
private:
	vector<sf::Sprite*> Drawables;
};
#endif
