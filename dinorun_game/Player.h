#pragma once
#include "AnimatingObject.h"
#include <SFML/Audio.hpp>

class Player : public AnimatingObject
{
public:
	Player();

	void Update(sf::Time frameTime) override;
	void Jump();
	void Crouch();
	bool isCollidingObstacle();
    bool isCollidingMeat();

private:
	int score;
	sf::SoundBuffer jumpBuffer;
	sf::SoundBuffer hitBuffer;
	sf::SoundBuffer itemBuffer;
	sf::Sound jumpSound;
	sf::Sound hitSound;
	sf::Sound itemSound;

};

