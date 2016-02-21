#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <map>
#include <sstream>

class Screen
{
public:
	Screen()
	{
		//Simple screen name creation
		std::stringstream sstm;
		sstm << m_name << m_screenCount;
		m_name = sstm.str();
		m_screenCount++;
	}

	void SetName(const std::string& name){ m_name = name; }
	const std::string& getName(){ return m_name; }

	virtual void Shutdown() = 0;
	virtual void Start() = 0;
	virtual void Update(float dt) = 0;
	virtual void DrawScene(sf::Window& window) = 0;
	virtual void OnEnable() = 0;

private:
	static int m_screenCount;
	std::string m_name;
};

class SceneManager : private Screen
{
public:
	enum Error
	{
		None,
		Exists,
		NotFound
	};

	Error addScreen(Screen& screen)
	{
		for (int i = 0; i < m_screens.size(); i++)
		{
			if (m_screens[i] == &screen)
				return Error::Exists;
		}
		screen.OnEnable();
		m_screens.push_back(&screen);
		return Error::None;
	}

	Error removeScreen(Screen& screen){
		for (int i = 0; i < m_screens.size(); i++)
		{
			if (m_screens[i] == &screen)
			{
				m_screens.erase(m_screens.begin() + i);
				return Error::None;
			}
		}
		return Error::NotFound;
	}

	void setCurrentScreen(Screen& screen)
	{
		m_currentScreen = &screen;
		screen.Start();
	}

	void setCurrentScreen(int index)
	{
		m_currentScreen = m_screens[index];
		setCurrentScreen(*m_screens[index]);
	}

	void setCurrentScreen(const std::string& name)
	{
		for (int i = 0; i < m_screens.size(); i++)
		{
			if (strcmp(name.c_str(), m_screens[i]->getName().c_str()) == 0)
			{
				setCurrentScreen(*m_screens[i]);
			}
		}
	}

	void Start()
	{
		if (m_currentScreen) m_currentScreen->Start();
	}

	void Update(float dt)
	{
		if (m_currentScreen) m_currentScreen->Update(dt);
	}

	void DrawScene(sf::Window& window)
	{
		if (m_currentScreen) m_currentScreen->DrawScene(window);
	}

	void Shutdown()
	{
		for (int i = 0; i < m_screens.size(); i++)
			m_screens[i]->Shutdown();
	}

	void keyDown(const sf::Keyboard::Key& key)
	{
		//if (m_currentScreen) m_currentScreen->keyDown(key);
	}

	void keyUp(const sf::Keyboard::Key& key)
	{
		//if (m_currentScreen) m_currentScreen->keyUp(key);
	}
	void OnEnable()
	{

	}

	static SceneManager& Instance()
	{
		static SceneManager instance;
		return instance;
	}
	Screen* GetCurrentScreen()
	{
		return m_currentScreen;
	}



private:
	std::vector<Screen*> m_screens;
	Screen* m_currentScreen;
};

int Screen::m_screenCount = 0;
#endif