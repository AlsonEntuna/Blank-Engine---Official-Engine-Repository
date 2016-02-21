#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_
#pragma once
#include "Component.h"
#include "Animator.h"
#include "GameObject.h"
class Movement : public Component
{
public:
	Movement(int id);
	~Movement();
	void Update() override;
	void SetSpeed(float speed);
	bool Collided();
private:
	float m_Speed;
	sf::Vector2f m_Direction;
	bool m_IsMoving;
	bool m_Collided;
};

#endif

