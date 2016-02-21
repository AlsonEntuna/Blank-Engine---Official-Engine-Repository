#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include <string>
#include <SFML\Audio.hpp>
#include <memory>

using namespace std;
class Sound
{
public:
	enum SoundType
	{
		Music,
		SFX
	};
	Sound();
	~Sound();
	// Sound Initializer
	void InitializeSound(string name, SoundType type, const string& fileName);
	// BG Music
	void PlayBGMusic(float volume);
	void StopBGMPlayback();
	void PuasePlayback();
	// Sound Effects
	void PlaySFX(float volume);
private:
	string			m_SoundName;
	SoundType		m_type;
	unique_ptr<sf::Music> m_Music;
	unique_ptr<sf::SoundBuffer> m_SoundBuffer;
	sf::Sound m_Sound;
};

#endif
