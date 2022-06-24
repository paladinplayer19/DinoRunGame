#pragma once
#include "AnimatingObject.h"

class Bird;
class Cactus;

class Obstacle : public AnimatingObject
{
public:
	Obstacle(sf::Vector2f newScreenSize);

	virtual void Update(sf::Time frameTime) override;


private:

	float obstacleFrequency;
	sf::Time timeSinceObstacle;
	
	sf::Vector2f screenSize;

};

