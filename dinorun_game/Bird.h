#pragma once
#include "Obstacle.h"
class Bird : public Obstacle
{
public:
	Bird(sf::Vector2f newScreenSize);
	virtual void Update(sf::Time deltaTime) override;

	void Reset();

private:

	sf::Vector2f screenSize;
	static sf::Texture* birdTexture;
	sf::Vector2f newPosition = sf::Vector2f();
	sf::Vector2f currentPosition = sf::Vector2f();
	sf::Vector2f velocity = sf::Vector2f();
	float birdFrequency;
	sf::Time timeSinceBird;
};

