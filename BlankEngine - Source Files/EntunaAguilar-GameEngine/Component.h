#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <string>

#define SpriteRendererComponent 1
#define AudioComponent 2
#define AnimatorComponent 3
#define MovementComponent 4
using namespace std;
class GameObject;
class Component
{
public:
	Component();
	~Component();
	// Getters
	int getComponentID();
	string& getComponentName();

	// Setter
	void SetGameObject(GameObject* object);

	// Update
	virtual void Update() = 0;
protected:
	string m_ComponentName;
	int m_ComponentID;
	GameObject* m_GameObject;

};
#endif




