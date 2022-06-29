#include "Bird.h"

sf::Texture* Bird::birdTexture = nullptr;

Bird::Bird(sf::Vector2f newScreenSize)
	: Obstacle(newScreenSize)
	, screenSize(newScreenSize)
	, newPosition(0, 0)
	, currentPosition(0, 0)
	, velocity(-500.0f, 0.0f)
	, birdFrequency(0.75f)
	, timeSinceBird()
{
	if (birdTexture == nullptr)
	{
		birdTexture = new sf::Texture();
		birdTexture->loadFromFile("Assets/Graphics/flyer-2.png");
	}

	sprite.setTexture(*birdTexture);
	

	rand();
	rand();
	rand();
	newPosition.x = screenSize.x;
	newPosition.y = 500;

	ChangePos(newPosition);

	SetVelocity(velocity);

}

void Bird::Update(sf::Time deltaTime)
{
	Obstacle::Update(deltaTime);

	sf::Vector2f birdPosition = GetPosition();

	if (birdPosition.x + birdTexture->getSize().x <= 0)
	{

		timeSinceBird += deltaTime;

		if (timeSinceBird.asSeconds() >= birdFrequency)
		{
			Reset();
			timeSinceBird = sf::Time();
		}


	}

}

void Bird::Reset()
{
	newPosition.x = screenSize.x;
	newPosition.y = 500;
	currentPosition.x = newPosition.x;
	currentPosition.y = newPosition.y;
	ChangePos(currentPosition);
}
