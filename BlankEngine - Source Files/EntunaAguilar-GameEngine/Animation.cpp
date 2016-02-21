#include "Animation.h"


Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::AddFrame(string filePath)
{
	sf::Texture texture;
	if (texture.loadFromFile(filePath))
	{
		m_Frames.push_back(texture);
	}
}

sf::Texture* Animation::GetFrame(int index)
{
	if (index < m_Frames.size() && index >= 0)
	{
		return &m_Frames[index];
	}
	return &m_Frames[0];
}

int Animation::GetFramesCount()
{
	return m_Frames.size();
}
