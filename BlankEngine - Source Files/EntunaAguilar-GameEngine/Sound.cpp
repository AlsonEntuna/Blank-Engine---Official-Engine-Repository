#include "Sound.h"
#include <iostream>
#include <SFML\Audio.hpp>

using namespace std;

Sound::Sound()
{
	m_SoundName = "default";
}


Sound::~Sound()
{
}

void Sound::InitializeSound(string name, Sound::SoundType type, const string& fileName)
{
	m_SoundName = name;
	m_type = type;
	m_Music = unique_ptr<sf::Music>(new sf::Music());
	m_SoundBuffer = unique_ptr<sf::SoundBuffer>(new sf::SoundBuffer());
	if (type == Sound::Music)
	{
		if (!m_Music->openFromFile(fileName))
			cout << "No Music File Detected" << endl;
	}
	else
	{
		if (!m_SoundBuffer->loadFromFile(fileName))
			cout << "No File Detected" << endl;
	}
}
void Sound::PlayBGMusic(float volume)
{
	m_Music->setVolume(volume);
	m_Music->play();
}

void Sound::StopBGMPlayback()
{
	m_Music->stop();
}

void Sound::PlaySFX(float volume)
{
	m_Sound.setBuffer(*m_SoundBuffer);
	m_Sound.setVolume(volume);
	m_Sound.play();
}