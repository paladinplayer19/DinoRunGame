#include "Obstacle.h"
#include "Bird.h"
#include "Cactus.h"
#include "Player.h"

Obstacle::Obstacle(sf::Vector2f newScreenSize)
	: AnimatingObject()
	, obstacleFrequency(0.5f)
	, timeSinceObstacle()
	, screenSize(newScreenSize)
	, isTouching(false)
	, hitSound()
	, hitBuffer()
{	
	// load hit sound
	hitBuffer.loadFromFile("Assets/Audio/death.wav");
	hitSound.setBuffer(hitBuffer);
}

void Obstacle::Update(sf::Time frameTime)
{
	AnimatingObject::Update(frameTime);
	
}
void Obstacle::HandleCollision(GameObject& other)
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
	

	// plays hit sound
	hitSound.play();
	
	sf::Vector2f depth = GetCollisionDepth(other);
	sf::Vector2f absDepth = sf::Vector2f(abs(depth.x), abs(depth.y));
	sf::Vector2f playerPosition = checkPlayer->GetPosition();

	checkPlayer->ChangePos(playerPosition);


}

bool Obstacle::GetIsTouching()
{
	return isTouching;
}


