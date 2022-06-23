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
	if (cloudTexture == nullptr)
	{
		cloudTexture = new sf::Texture();
		cloudTexture->loadFromFile("Assets/Graphics/cloud.png");
	}

	sprite.setTexture(*cloudTexture);

	rand();
	rand();
	rand();
	newPosition.x = rand() % (int)screenSize.x;
	
	ChangePos(newPosition);

	SetVelocity(velocity);

}

void Cloud::Update(sf::Time deltaTime)
{
	GameObject::Update(deltaTime);

	sf::Vector2f cloudPosition = GetPosition();

	if (cloudPosition.x + cloudTexture->getSize().x <= 0)
	{
		
		timeSinceCloud += deltaTime;

		if (timeSinceCloud.asSeconds() >= cloudFrequency)
		{
			Reset();
			timeSinceCloud = sf::Time();
		}

		
	}


}

void Cloud::Reset()
{
	newPosition.x = screenSize.x;
	newPosition.y = rand() % 300;
	currentPosition.x = newPosition.x;
	currentPosition.y = newPosition.y;
	ChangePos(currentPosition);
}
