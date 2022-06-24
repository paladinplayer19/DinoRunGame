#include "Obstacle.h"
#include "Bird.h"
#include "Cactus.h"

Obstacle::Obstacle(sf::Vector2f newScreenSize)
	: AnimatingObject()
	, obstacleFrequency(0.5f)
	, timeSinceObstacle()
	, screenSize()
{	

}

void Obstacle::Update(sf::Time frameTime)
{
	AnimatingObject::Update(frameTime);
	
}

