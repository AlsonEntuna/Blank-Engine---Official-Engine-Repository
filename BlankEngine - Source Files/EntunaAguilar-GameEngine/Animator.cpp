#include "Animator.h"

using namespace std;
Animator::Animator(int id)
{
	this->m_ComponentName = "Animator";
	this->m_ComponentID = id;
}


Animator::~Animator()
{
}

void Animator::Update()
{
	// << "Animator Running. . ." << endl;
	m_GameObject->GetComponent<SpriteRenderer>(SpriteRendererComponent)->Sprite.setTexture(m_CurrentFrame);
}


void Animator::SetAnimation(const string& key, Animation animation)
{
	if (m_Animation.count(key) == 0)
	m_Animation[key] = animation;
}

Animation* Animator::GetAnimation(const string& key)
{
	return &m_Animation[key];
}

void Animator::SetFrameSpeed(float speed)
{
	m_FrameSpeed = speed;
}

void Animator::Play(const string& key)
{
	if (m_Animation[key].GetFramesCount() > m_Index)
	{
		//cout << m_Index << endl;
		m_CurrentFrame = *m_Animation[key].GetFrame((int)m_Index);
		m_Index += m_FrameSpeed;
	}
	else m_Index = 0;
}