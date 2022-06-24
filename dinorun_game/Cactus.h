#pragma once
#include "Obstacle.h"
class Cactus : public Obstacle
{
public:
	Cactus(sf::Vector2f newScreenSize);

private:
	sf::Vector2f screenSize;
};

