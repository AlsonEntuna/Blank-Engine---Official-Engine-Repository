#ifndef _MAIN_MENU_SCENE_H_
#define _MAIN_MENU_SCENE_H_

#include <SFML\Graphics.hpp>
#include "SceneManager.h"
#include "CharacterManager.h"
#include <iostream>
#include <vector>

using namespace std;

class MainMenuScene : public Screen
{
public:
	MainMenuScene()
	{
		this->SetName("MainMenuScene");

	}

	void OnEnable()
	{

	}

	void Start()
	{
		CharacterOne->SetName("Alson");
		CharacterOne->SetTag(PlayerTag);
		CharacterOne->SetPosition(sf::Vector2f(250.0f, 250.0f));
		CharacterOne->Scale(sf::Vector2f(2.5f, 2.5f));

		CharacterTwo->SetName("Paul");
		CharacterTwo->SetTag(PlayerTag);
		CharacterTwo->SetPosition(sf::Vector2f(550.0f, 250.0f));
		CharacterTwo->Scale(sf::Vector2f(-2.5f, 2.5f));
		
		// Sample Text
		font.loadFromFile("Images/comicsans.ttf");
		text.setFont(font);
		text.setString("Choose a Character: \n[1] " + CharacterOne->GetName() + "\n[2] " + CharacterTwo->GetName() + "\nPress Enter to Select");
		text.setCharacterSize(30);
		text.setColor(sf::Color::White);
		text.setPosition(0.0f, 0.0f);


		//// Sample SpriteRenderer Component Creation
		SpriteRenderer* SpriteRendererOne = new SpriteRenderer(SpriteRendererComponent);
		CharacterOne->AddComponent(SpriteRendererOne);
		CharacterOne->GetComponent<SpriteRenderer>(SpriteRendererComponent)->setSprite("Images/Cecil4.png");
		CharacterOne->GetComponent<SpriteRenderer>(SpriteRendererComponent)->Sprite.setColor(sf::Color::Blue);

		SpriteRenderer* SpriteRendererTwo = new SpriteRenderer(SpriteRendererComponent);
		CharacterTwo->AddComponent(SpriteRendererTwo);
		CharacterTwo->GetComponent<SpriteRenderer>(SpriteRendererComponent)->setSprite("Images/Cecil4.png");
		CharacterTwo->GetComponent<SpriteRenderer>(SpriteRendererComponent)->Sprite.setColor(sf::Color::Red);

		//// Sample Animator Component Creation
		Animator* CharacterOneAnimator = new Animator(AnimatorComponent);
		Animator* CharacterTwoAnimator = new Animator(AnimatorComponent);

		//// Sample Animation Creation
		Animation* WalkAnimation = new Animation();
		WalkAnimation->AddFrame("Images/Cecil2.png");
		WalkAnimation->AddFrame("Images/Cecil3.png");
		WalkAnimation->AddFrame("Images/Cecil4.png");
		WalkAnimation->AddFrame("Images/Cecil3.png");

		Animation* CastAnimation = new Animation();
		CastAnimation->AddFrame("Images/Cecil8.png");
		CastAnimation->AddFrame("Images/Cecil9.png");

		Animation* IdleAnimation = new Animation();
		IdleAnimation->AddFrame("Images/Cecil1.png");

		Animation* FlinchAnimation = new Animation();
		FlinchAnimation->AddFrame("Images/Cecil12.png");

		//// Add Components to GameObject
		CharacterOne->AddComponent(CharacterOneAnimator);
		CharacterTwo->AddComponent(CharacterTwoAnimator);

		//// Modify Components' Values
		CharacterOne->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Run", *WalkAnimation);
		CharacterOne->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Cast", *CastAnimation);
		CharacterOne->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Idle", *IdleAnimation);
		CharacterOne->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Flinch", *FlinchAnimation);
		CharacterOne->GetComponent<Animator>(AnimatorComponent)->SetFrameSpeed(0.2f);

		CharacterTwo->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Run", *WalkAnimation);
		CharacterTwo->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Cast", *CastAnimation);
		CharacterTwo->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Idle", *IdleAnimation);
		CharacterTwo->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Flinch", *FlinchAnimation);
		CharacterTwo->GetComponent<Animator>(AnimatorComponent)->SetFrameSpeed(0.2f);

		// Sample Print Components in an Object
		CharacterOne->ViewObjectComponents();
		CharacterTwo->ViewObjectComponents();

		// Sample Sound Feature
		Sound* samplesound = new Sound();
		samplesound->InitializeSound("sample", Sound::Music, "Music/Menu.wav");
		samplesound->PlayBGMusic(1000);

		// Add All GameObjects to GameObject Vector
		AddGameObject(CharacterOne);
		AddGameObject(CharacterTwo);

		// Add All Drawables to Layer
		userInterface->AddDrawable(&CharacterOne->GetComponent<SpriteRenderer>(SpriteRendererComponent)->Sprite);
		userInterface->AddDrawable(&CharacterTwo->GetComponent<SpriteRenderer>(SpriteRendererComponent)->Sprite);
	}

	void Update(float dt)
	{
		for each (GameObject* var in GameObjects)
		{
			var->GameObjectUpdate();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || selectIndex == 0)
		{
			selectIndex = 0;
			CharacterOne->GetComponent<Animator>(AnimatorComponent)->Play("Cast");
			CharacterTwo->GetComponent<Animator>(AnimatorComponent)->Play("Cast");
		}

		if (selectIndex == 1)
		{
			CharacterOne->GetComponent<Animator>(AnimatorComponent)->Play("Flinch");
			CharacterTwo->GetComponent<Animator>(AnimatorComponent)->Play("Cast");
		}
		else if (selectIndex == 2)
		{
			CharacterTwo->GetComponent<Animator>(AnimatorComponent)->Play("Flinch"); 
			CharacterOne->GetComponent<Animator>(AnimatorComponent)->Play("Cast");
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))	selectIndex = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))	selectIndex = 2;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			if (selectIndex == 1)
			{
				CharacterManager::Instance().SetPlayer(CharacterOne);
				SceneManager::Instance().setCurrentScreen("ExplorationScene");
			}
			if (selectIndex == 2)
			{
				CharacterManager::Instance().SetPlayer(CharacterTwo);
				SceneManager::Instance().setCurrentScreen("ExplorationScene");
			}
			
		}

		
	}

	void DrawScene(sf::Window& window)
	{
		sf::RenderWindow* rw = (sf::RenderWindow*)&window;
		userInterface->Render(rw);
		rw->draw(text);
	}

	void Shutdown()
	{

	}

	void AddGameObject(GameObject* object)
	{
		GameObjects.push_back(object);
	}
private:
	//// Sample GameObject Creation
	GameObject* CharacterOne = new GameObject();
	GameObject* CharacterTwo = new GameObject();

	//// Sample Layer Setup
	Layer* userInterface = new Layer();

	//// Text Setup
	sf::Font font;
	sf::Text text;

	//// Vector of GameObjects
	vector<GameObject*> GameObjects;
	int selectIndex = 0;
};
#endif