#include "Layer.h"


Layer::Layer()
{
}


Layer::~Layer()
{
}


void Layer::Render(sf::RenderWindow *window)
{
	for each (sf::Drawable* drawable in Drawables)
	{
		window->draw(*drawable);
	}
}

void Layer::AddDrawable(sf::Sprite* drawable)
{
	Drawables.push_back(drawable);
}

vector<sf::Sprite*> Layer::GetDrawables()
{
	return Drawables;
}