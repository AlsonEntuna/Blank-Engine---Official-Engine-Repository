#include "Component.h"


Component::Component()
{
	m_ComponentName = "default";
	m_ComponentID = NULL;
}


Component::~Component()
{
}

int Component::getComponentID()
{
	return m_ComponentID;
}
string& Component::getComponentName()
{
	return m_ComponentName;
}

void Component::SetGameObject(GameObject* object)
{
	m_GameObject = object;
}
