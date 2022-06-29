#include "Cactus.h"

sf::Texture* Cactus::cactusTexture = nullptr;

Cactus::Cactus(sf::Vector2f newScreenSize)
	: Obstacle(newScreenSize)
	, screenSize(newScreenSize)
	, newPosition(0, 0)
	, currentPosition(0, 0)
	, velocity(-500.0f, 0.0f)
	, cactusFrequency(0.75f)
	, timeSinceCactus()
{
	if (cactusTexture == nullptr)
	{
		cactusTexture = new sf::Texture();
		cactusTexture->loadFromFile("Assets/Graphics/cactus.png");
	}

	sprite.setTexture(*cactusTexture);
	sprite.setOrigin(spriteTexture.getSize().x / 2, spriteTexture.getSize().y);

	/*rand();
	rand();
	rand();*/
	newPosition.x = screenSize.x + 10;
	newPosition.y = (screenSize.y - (screenSize.y / 4) - 90);
	ChangePos(newPosition);

	SetVelocity(velocity);
}

void Cactus::Update(sf::Time deltaTime)
{
	Obstacle::Update(deltaTime);

	sf::Vector2f cactusPosition = GetPosition();

	if (cactusPosition.x + cactusTexture->getSize().x <= 0)
	{

		timeSinceCactus += deltaTime;

		if (timeSinceCactus.asSeconds() >= cactusFrequency)
		{
			Reset();
			timeSinceCactus = sf::Time();
		}


	}

}

void Cactus::Reset()
{
	newPosition.x = screenSize.x + 10;
	newPosition.y = (screenSize.y - (screenSize.y / 4) - 90);
	currentPosition.x = newPosition.x;
	currentPosition.y = newPosition.y;
	ChangePos(currentPosition);
}
