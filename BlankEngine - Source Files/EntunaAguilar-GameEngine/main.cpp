#include "BlankEngine.h"

void main()
{
	SetScreenDimensions(800, 600);
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "BlankEngine V0.0.27");
	srand(time(NULL));
	window.setFramerateLimit(60);



	// Sample Scene Manager Creation
	CharacterManager& characterManager = CharacterManager::Instance();
	SceneManager& sceneManager = SceneManager::Instance();
	MainMenuScene mainMenuScene;
	ExplorationScene explorationScene;
	CombatScene combatScene;

	sceneManager.addScreen(mainMenuScene);
	sceneManager.addScreen(explorationScene);

	sceneManager.setCurrentScreen(mainMenuScene);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))window.close();	
		}
		sceneManager.Update(0);
		window.clear(sf::Color::Black);

		// Draw All Drawables
		sceneManager.DrawScene(window);
		
		
		window.display();
	}
}