#pragma once
#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_
#include "Component.h"
#include "GameObject.h"
#include "Animation.h"
#include <iostream>
using namespace std;
class Animator : public Component
{
public:
	Animator(int id);
	~Animator();
	void Update() override;

	void SetAnimation(const string& key, Animation animation);
	void SetFrameSpeed(float speed);
	void Play(const string& key);
	Animation* GetAnimation(const string& key);

private:
	std::map<string, Animation> m_Animation;
	sf::Texture m_CurrentFrame;
	float m_Index = 0;
	float m_FrameSpeed = 0;
};

#endif

