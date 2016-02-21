#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <vector>
#include <string>
using namespace std;
class Animation
{
public:
	Animation();
	~Animation();

	void AddFrame(string filePath);
	sf::Texture* GetFrame(int index);
	int GetFramesCount();

private:
	vector<sf::Texture> m_Frames;
	sf::Texture m_CurrentTexture;

};

#endif