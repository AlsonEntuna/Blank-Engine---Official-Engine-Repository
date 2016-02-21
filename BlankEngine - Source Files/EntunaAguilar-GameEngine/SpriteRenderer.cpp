#include "SpriteRenderer.h"


SpriteRenderer::SpriteRenderer(int id)
{
	m_ComponentID = id;
	m_ComponentName = "SpriteRenderer";
}


SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::setSprite(string filename)
{
	if (!this->SpriteTexture.loadFromFile(filename))
	{
		cout << filename << " not found." << endl;
	}

	this->Sprite.setTexture(this->SpriteTexture);
}

void SpriteRenderer::Update()
{
	Sprite.setScale(m_GameObject->ObjectScale());
	Sprite.setPosition(m_GameObject->ObjectPosition());
	Sprite.setRotation(m_GameObject->ObjectRotation());
	Sprite.setOrigin(25.0f, 25.0f);
}
