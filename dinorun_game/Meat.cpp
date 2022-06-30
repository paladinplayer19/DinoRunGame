#include "Meat.h"
#include <iostream>
#include "Player.h"

sf::Texture* Meat::meatTexture = nullptr;

Meat::Meat(sf::Vector2f newScreenSize)
	: GameObject()
	, screenSize(newScreenSize)
	, newPosition(0, 0)
	, currentPosition(0, 0)
	, velocity(-1000.0f, 0.0f)
	, meatFrequency(10.0f)
	, timeSinceMeat()
	, itemBuffer()
	, itemSound()
	, isTouching(false)
	, isAlive(true)
{
	// loads texture
	if (meatTexture == nullptr)
	{
		meatTexture = new sf::Texture();
		meatTexture->loadFromFile("Assets/Graphics/pickup.png");
	}

	// loads item sound
	itemBuffer.loadFromFile("Assets/Audio/pickup.wav");
	itemSound.setBuffer(itemBuffer);

	// sets texture
	sprite.setTexture(*meatTexture);

	
	// sets x and y beginning position
	newPosition.x = screenSize.x;
	newPosition.y = (screenSize.y - (screenSize.y / 4) - 50);
	ChangePos(newPosition);

	// sets velocity
	SetVelocity(velocity);

}

void Meat::Update(sf::Time deltaTime)
{
	GameObject::Update(deltaTime);

	// gets currer position of meat
	sf::Vector2f meatPosition = GetPosition();

	// checks to see if meat is off screen
	if (meatPosition.x + meatTexture->getSize().x <= 0)
	{

		timeSinceMeat += deltaTime;

		// waits till time is up for next meat to spawn
		if (timeSinceMeat.asSeconds() >= meatFrequency)
		{
			// resets position
			Reset();
			timeSinceMeat = sf::Time();
		}


	}


}

void Meat::Reset()
{
	//moves meat off screen to the right
	isAlive = true;
	newPosition.x = screenSize.x + 10;
	newPosition.y = (screenSize.y - (screenSize.y / 4) - 50);
	currentPosition.x = newPosition.x;
	currentPosition.y = newPosition.y;
	ChangePos(currentPosition);
}

void Meat::HandleCollision(GameObject& other)
{
	// Checking if the thing is actually the player
	Player* checkPlayer = dynamic_cast<Player*>(&other);

	// checks if checkPlayer has something in it
	if (checkPlayer == nullptr) {
		return;
	}

	// checks if there is collision
	if (!IsColliding(other))
	{
		isTouching = false;

		return;
	}

	isTouching = true;
	isAlive = false;

	// plays item sound
	itemSound.play();
	
	sf::Vector2f depth = GetCollisionDepth(other);
	sf::Vector2f absDepth = sf::Vector2f(abs(depth.x), abs(depth.y));
	sf::Vector2f playerPosition = checkPlayer->GetPosition();

	checkPlayer->ChangePos(playerPosition);


}
bool Meat::GetIsTouching()
{
	return isTouching;
}

bool Meat::GetIsAlive()
{
	return isAlive;
}
