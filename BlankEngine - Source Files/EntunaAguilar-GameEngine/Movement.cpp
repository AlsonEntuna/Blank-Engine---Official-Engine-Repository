#include "Movement.h"

Movement::Movement(int id)
{
	m_ComponentID = id;
	m_ComponentName = "Movement";
	m_IsMoving = false;
}


Movement::~Movement()
{
}

void Movement::Update()
{
	m_IsMoving = false;
	if (m_GameObject == NULL) throw new invalid_argument("No GameObject Assigned!");
	
	m_Direction = sf::Vector2f(0.0f, 0.0f);
	
	if (!m_Collided)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_Direction = sf::Vector2f(1, m_Direction.y);
			m_IsMoving = true;
			m_GameObject->Translate(sf::Vector2f(m_Speed * m_Direction.x, m_Speed * m_Direction.y));
			m_GameObject->Scale(sf::Vector2f(-2.5f, 2.5f));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_Direction = sf::Vector2f(-1, m_Direction.y);
			m_IsMoving = true;
			m_GameObject->Translate(sf::Vector2f(-m_Speed, m_Speed * m_Direction.y));
			m_GameObject->Scale(sf::Vector2f(2.5f, 2.5f));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_Direction = sf::Vector2f(m_Direction.x, -1);
			m_GameObject->Translate(sf::Vector2f(m_Speed * m_Direction.x, -m_Speed));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_Direction = sf::Vector2f(m_Direction.x, 1);
			m_GameObject->Translate(sf::Vector2f(m_Speed * m_Direction.x, m_Speed));
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		m_GameObject->Rotate(m_Speed);

	//m_Direction = sf::Vector2f(0.0f, 0.0f);
	if (m_IsMoving) m_GameObject->GetComponent<Animator>(AnimatorComponent)->Play("Run");
	else m_GameObject->GetComponent<Animator>(AnimatorComponent)->Play("Idle");
}

bool Movement::Collided()
{
	m_Collided = true;
	if (m_Collided)
	{
		m_Collided = false;
		if (m_Direction == sf::Vector2f(1, 0)) m_GameObject->Translate(sf::Vector2f(-m_Speed * 5, 0.0f));
		else if (m_Direction.x == -1) m_GameObject->Translate(sf::Vector2f(m_Speed * 5, 0.0f));
		else if (m_Direction.y == 1) m_GameObject->Translate(sf::Vector2f(0.0f, -m_Speed * 5));
		else if (m_Direction.y == -1) m_GameObject->Translate(sf::Vector2f(0.0f, m_Speed * 5));
		return true;
	}
	return false;
}

void Movement::SetSpeed(float speed)
{
	m_Speed = speed;
}
