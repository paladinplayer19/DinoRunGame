#pragma once
#include "AnimatingObject.h"
#include <SFML/Audio.hpp>
class Bird;
class Cactus;

class Obstacle : public AnimatingObject
{
public:
	Obstacle(sf::Vector2f newScreenSize);

	virtual void Update(sf::Time frameTime) override;
	void HandleCollision(GameObject& other);
	bool GetIsTouching();

private:

	float obstacleFrequency;
	sf::Time timeSinceObstacle;
	
	sf::Vector2f screenSize;
	bool isTouching;
	sf::Sound hitSound;
	sf::SoundBuffer hitBuffer;
};

