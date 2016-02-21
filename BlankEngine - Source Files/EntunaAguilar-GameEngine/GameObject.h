#pragma once
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_


#include "SpriteRenderer.h"
#include "Component.h"
#include <string>
#include <vector>
#include <iostream>

#define PlayerTag 0
#define EnemyTag  1
#define EnvironmentTag 2
#define Collidable 3

using namespace std;
//template < class T >
class GameObject
{
public:
	GameObject();
	~GameObject();

	// Getters
	const sf::Vector2f ObjectPosition() { return m_ObjectPosition; }
	const sf::Vector2f ObjectScale() { return m_ObjectScale; }
	const float ObjectRotation() { return m_ObjectRotation; }

	// Object Modification
	void SetPosition(sf::Vector2f position);
	void Translate(sf::Vector2f direction);
	void Rotate(float angle);
	void Scale(sf::Vector2f scale);

	// Tags and Name
	void SetTag(int tag);
	int GetTag();
	void SetName(string name);
	string GetName();

	void AddComponent(Component* component);
	void RemoveComponent(int componentID);
	template <class T>
	T* GetComponent(int componentID)
	{
		Component* comp = NULL;
		for each (Component* c in m_Components)
		{
			if (c->getComponentID() != componentID) continue;
			comp = c; break;
		}
		if (comp == NULL) throw invalid_argument("No Component Found");
		return (T*)comp;
	}

	void ViewObjectComponents();

	// Update
	void GameObjectUpdate();

private:
	string   m_ObjectName;
	int		 m_ObjectTag;
	sf::Vector2f m_ObjectPosition;
	sf::Vector2f m_ObjectScale;
	float m_ObjectRotation;
	vector<Component*> m_Components;
};

#endif

