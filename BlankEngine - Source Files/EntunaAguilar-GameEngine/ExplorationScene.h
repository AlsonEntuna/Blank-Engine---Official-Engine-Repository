#ifndef _EXPLORATION_SCENE_H_
#define _EXPLORATION_SCENE_H_

#include <SFML\Graphics.hpp>
#include "SceneManager.h"
#include "CharacterManager.h"
#include <iostream>
#include <vector>

using namespace std;
class ExplorationScene : public Screen
{
public:
	ExplorationScene()
	{
		this->SetName("ExplorationScene");
	}

	void OnEnable()
	{

	}

	void Start()
	{
		Player->SetName("Player");
		Player->SetTag(PlayerTag);
		Player->SetPosition(sf::Vector2f(250.0f, 250.0f));
		Player->Scale(sf::Vector2f(2.5f, 2.5f));

		Background->SetName("Background");
		Background->SetTag(EnvironmentTag);
		Background->SetPosition(sf::Vector2f(0.0f, 0.0f));
		Background->Scale(sf::Vector2f(10.0f, 10.0f));

		RockCollidable->SetName("RockCollidable");
		RockCollidable->SetTag(Collidable);
		RockCollidable->SetPosition(sf::Vector2f(0.0f, 0.0f));
		RockCollidable->Scale(sf::Vector2f(1.0f, 1.0f));

		RockCollidable->SetName("RockCollidable2");
		RockCollidable->SetTag(Collidable);
		RockCollidable->SetPosition(sf::Vector2f(400.0f, 0.0f));
		RockCollidable->Scale(sf::Vector2f(1.0f, 1.0f));

		//// Sample SpriteRenderer Component Creation
		SpriteRenderer* SpriteRendererOne = new SpriteRenderer(SpriteRendererComponent);
		Player->AddComponent(SpriteRendererOne);
		Player->GetComponent<SpriteRenderer>(SpriteRendererComponent)->setSprite("Images/Cecil4.png");

		SpriteRenderer* BG = new SpriteRenderer(SpriteRendererComponent);
		Background->AddComponent(BG);
		Background->GetComponent<SpriteRenderer>(SpriteRendererComponent)->setSprite("Images/Asteroid.png");

		SpriteRenderer* CollidableSpriteRenderer = new SpriteRenderer(SpriteRendererComponent);
		RockCollidable->AddComponent(CollidableSpriteRenderer);
		RockCollidable->GetComponent<SpriteRenderer>(SpriteRendererComponent)->setSprite("Images/Rock.png");

		SpriteRenderer* CollidableSpriteRenderer2 = new SpriteRenderer(SpriteRendererComponent);
		RockCollidable2->AddComponent(CollidableSpriteRenderer2);
		RockCollidable2->GetComponent<SpriteRenderer>(SpriteRendererComponent)->setSprite("Images/Rock.png");

		//// Sample Animator Component Creation
		Animator* PlayerAnimator = new Animator(AnimatorComponent);

		//// Sample Movement Component Creation
		Movement* PlayerMovement = new Movement(MovementComponent);

		//// Add Components to GameObject
		Player->AddComponent(PlayerAnimator);
		Player->AddComponent(PlayerMovement);

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

		Player->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Run", *WalkAnimation);
		Player->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Cast", *CastAnimation);
		Player->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Idle", *IdleAnimation);
		Player->GetComponent<Animator>(AnimatorComponent)->SetAnimation("Flinch", *FlinchAnimation);
		Player->GetComponent<Animator>(AnimatorComponent)->SetFrameSpeed(0.2f);
		Player->GetComponent<Movement>(MovementComponent)->SetSpeed(2.0f);

		// Sample Print Components in an Object
		Player->ViewObjectComponents();

		/*SOUND FEATURE

		See Sound.h for more details
		*/
		Sound* samplesound = new Sound();
		samplesound->InitializeSound("sample", Sound::Music, "Music/Exploration.wav");
		samplesound->PlayBGMusic(1000);

		Sound* sampleSFX = new Sound();
		sampleSFX->InitializeSound("sampleSFX", Sound::SFX, "Music/Exploration.wav");
		sampleSFX->PlaySFX(1000);

		// Add ALL GameObjects to GameObject vector
		AddGameObject(Player);
		AddGameObject(Background);
		AddGameObject(RockCollidable);
		AddGameObject(RockCollidable2);

		// Add All Drawables to Layer
		player->AddDrawable(&Player->GetComponent<SpriteRenderer>(SpriteRendererComponent)->Sprite);
		background->AddDrawable(&Background->GetComponent<SpriteRenderer>(SpriteRendererComponent)->Sprite);
		collidable->AddDrawable(&RockCollidable->GetComponent<SpriteRenderer>(SpriteRendererComponent)->Sprite);
		collidable->AddDrawable(&RockCollidable2->GetComponent<SpriteRenderer>(SpriteRendererComponent)->Sprite);
	}

	void Update(float dt)
	{
		// Update All GameObjects
		for each (GameObject* var in GameObjects)
		{
			var->GameObjectUpdate();
			if (var->GetTag() == PlayerTag)
			{
				for each (GameObject* object in GameObjects)
				{
					if (object->GetTag() == Collidable) 
					{
						if (Collision::BoundingBoxTest(var->GetComponent<SpriteRenderer>(SpriteRendererComponent)->Sprite, object->GetComponent<SpriteRenderer>(SpriteRendererComponent)->Sprite))
						{
							var->GetComponent<Movement>(MovementComponent)->Collided();
							cout << "Collide!" << endl;

						}
					}
				}
			}
		}
	}

	void DrawScene(sf::Window& window)
	{
		sf::RenderWindow* rw = (sf::RenderWindow*)&window;
		background->Render(rw);
		player->Render(rw);
		collidable->Render(rw);
	}

	void Shutdown()
	{

	}
	
	void AddGameObject(GameObject* object)
	{
		GameObjects.push_back(object);
	}
private:
	// Sameple Layer Creation
	Layer* background = new Layer();
	Layer* collidable = new Layer();
	Layer* player = new Layer();

	vector<GameObject*> GameObjects;

	//// Sample GameObject Creation
	GameObject* Player = new GameObject();
	GameObject* Background = new GameObject();
	GameObject* RockCollidable = new GameObject();
	GameObject* RockCollidable2 = new GameObject();
};

#endif