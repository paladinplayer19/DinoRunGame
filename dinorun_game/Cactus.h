#pragma once
#include "Obstacle.h"
class Cactus : public Obstacle
{
public:
	Cactus(sf::Vector2f newScreenSize);
	virtual void Update(sf::Time deltaTime) override;

	void Reset();

private:

	sf::Vector2f screenSize;
	static sf::Texture* cactusTexture;
	sf::Vector2f newPosition = sf::Vector2f();
	sf::Vector2f currentPosition = sf::Vector2f();
	sf::Vector2f velocity = sf::Vector2f();
	float cactusFrequency;
	sf::Time timeSinceCactus;
};

