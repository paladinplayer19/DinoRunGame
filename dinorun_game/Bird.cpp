#include "Bird.h"

sf::Texture* Bird::birdTexture = nullptr;

Bird::Bird(sf::Vector2f newScreenSize)
	: Obstacle(newScreenSize)
	, screenSize(newScreenSize)
	, newPosition(0, 0)
	, currentPosition(0, 0)
	, velocity(-500.0f, 0.0f)
	, birdFrequency(3.0f)
	, timeSinceBird()
{
	//loads texture
	if (birdTexture == nullptr)
	{
		birdTexture = new sf::Texture();
		birdTexture->loadFromFile("Assets/Graphics/flyer-2.png");
	}

	// sets texture
	sprite.setTexture(*birdTexture);
	

	rand();
	rand();
	rand();

	// sets up position of cactus 
	newPosition.x = screenSize.x + rand() % (int)screenSize.x + 10;
	newPosition.y = 450;

	ChangePos(newPosition);

}

void Bird::Update(sf::Time deltaTime)
{
	Obstacle::Update(deltaTime);

	// gets current position of bird
	sf::Vector2f birdPosition = GetPosition();

	// checks to see if bird is off screen
	if (birdPosition.x + birdTexture->getSize().x <= 0)
	{

		timeSinceBird += deltaTime;
		// resets bird after time is up
		if (timeSinceBird.asSeconds() >= birdFrequency)
		{
			Reset();
			timeSinceBird = sf::Time();
		}


	}

}

void Bird::Reset()
{
	// resets bird off screen to the right
	newPosition.x = screenSize.x + rand() % (int)screenSize.x + 10;
	newPosition.y = 475;
	currentPosition.x = newPosition.x;
	currentPosition.y = newPosition.y;
	ChangePos(currentPosition);
}
