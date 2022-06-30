#include "Cactus.h"

sf::Texture* Cactus::cactusTexture = nullptr;

Cactus::Cactus(sf::Vector2f newScreenSize)
	: Obstacle(newScreenSize)
	, screenSize(newScreenSize)
	, newPosition(0, 0)
	, currentPosition(0, 0)
	, velocity(-500.0f, 0.0f)
	, cactusFrequency(3.0f)
	, timeSinceCactus()
{
	// loads texture
	if (cactusTexture == nullptr)
	{
		cactusTexture = new sf::Texture();
		cactusTexture->loadFromFile("Assets/Graphics/cactus.png");
	}

	// sets texture
	sprite.setTexture(*cactusTexture);
	sprite.setOrigin(spriteTexture.getSize().x / 2, spriteTexture.getSize().y);

	rand();
	rand();
	rand();

	// sets up position of cactus 
	newPosition.x = screenSize.x + rand() % (int)screenSize.x + 50;
	newPosition.y = (screenSize.y - (screenSize.y / 4) - 90);
	ChangePos(newPosition);

	
}

void Cactus::Update(sf::Time deltaTime)
{
	Obstacle::Update(deltaTime);

	// gets current position of cactus
	sf::Vector2f cactusPosition = GetPosition();

	// checks to see if cactus is off screen
	if (cactusPosition.x + cactusTexture->getSize().x <= 0)
	{

		timeSinceCactus += deltaTime;

		// resets cactus after time is up
		if (timeSinceCactus.asSeconds() >= cactusFrequency)
		{
			Reset();
			timeSinceCactus = sf::Time();
		}


	}


}

void Cactus::Reset()
{
	// resets cactus off screen to the right
	newPosition.x = screenSize.x + 10;
	newPosition.y = (screenSize.y - (screenSize.y / 4) - 90);
	currentPosition.x = newPosition.x;
	currentPosition.y = newPosition.y;
	ChangePos(currentPosition);
}
