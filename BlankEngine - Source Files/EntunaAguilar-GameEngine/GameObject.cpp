#include "GameObject.h"

using namespace std;

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::AddComponent(Component* component)
{
	component->SetGameObject(this);
	m_Components.push_back(component);
}

void GameObject::RemoveComponent(int componentID)
{
	Component* compToRemove = NULL;
	for each (Component* c in m_Components)
	{
		if (c->getComponentID() != componentID) continue;
		compToRemove = c; break;
	}
	if (compToRemove == NULL) throw invalid_argument("No Component In List!");

	m_Components.erase(remove(m_Components.begin(), m_Components.end(), compToRemove), m_Components.end());
}

void GameObject::SetPosition(sf::Vector2f position)
{
	m_ObjectPosition = position;
}

void GameObject::SetName(string name)
{
	m_ObjectName = name;
}

string GameObject::GetName()
{
	return m_ObjectName;
}

void GameObject::SetTag(int tag)
{
	m_ObjectTag = tag;
}

int GameObject::GetTag()
{
	return m_ObjectTag;
}

void GameObject::ViewObjectComponents()
{
	cout << m_ObjectName + "'s List of Components: " << endl;
	for each (Component* var in m_Components)
		cout << "- " << var->getComponentName() << endl;
}

// Movement
void GameObject::Translate(sf::Vector2f direction)
{
	m_ObjectPosition += direction;
}
void GameObject::Rotate(float angle)
{
	m_ObjectRotation += angle;
}
void GameObject::Scale(sf::Vector2f scale)
{
	m_ObjectScale = scale;
}

void GameObject::GameObjectUpdate()
{
	for each (Component* component in m_Components)
		component->Update();
}

