#include "Cloud.h"
#include <iostream>
sf::Texture* Cloud::cloudTexture = nullptr;

Cloud::Cloud(sf::Vector2f newScreenSize)
	: GameObject()
	, screenSize(newScreenSize)
	, newPosition(0, 0)
	, currentPosition(0, 0)
	, velocity(-1000.0f, 0.0f)
	, cloudFrequency(0.5f)
	, timeSinceCloud()
{
	//loads texture
	if (cloudTexture == nullptr)
	{
		cloudTexture = new sf::Texture();
		cloudTexture->loadFromFile("Assets/Graphics/cloud.png");
	}

	//sets texture
	sprite.setTexture(*cloudTexture);

	
	rand();
	rand();

	//sets cloud position randomly on screen
	newPosition.x = rand() % (int)screenSize.x;
	
	ChangePos(newPosition);

	SetVelocity(velocity);

}

void Cloud::Update(sf::Time deltaTime)
{
	GameObject::Update(deltaTime);

	// gets current position of cloud
	sf::Vector2f cloudPosition = GetPosition();

	// checks to see if cloud is off screen
	if (cloudPosition.x + cloudTexture->getSize().x <= 0)
	{
		
		timeSinceCloud += deltaTime;

		// resets cloud after time is up
		if (timeSinceCloud.asSeconds() >= cloudFrequency)
		{
			Reset();
			timeSinceCloud = sf::Time();
		}

		
	}


}

void Cloud::Reset()
{
	// resets cloud off screen to the right
	newPosition.x = screenSize.x;
	newPosition.y = rand() % 300;
	currentPosition.x = newPosition.x;
	currentPosition.y = newPosition.y;
	ChangePos(currentPosition);
}
