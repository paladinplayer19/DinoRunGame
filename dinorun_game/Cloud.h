#pragma once
#include "GameObject.h"
class Cloud : public GameObject
{
public:
	Cloud(sf::Vector2f newScreenSize);

	virtual void Update(sf::Time deltaTime) override;

private:

	void Reset();


	static sf::Texture* cloudTexture;
	sf::Vector2f screenSize;
	sf::Vector2f newPosition = sf::Vector2f();
	sf::Vector2f currentPosition = sf::Vector2f();
	sf::Vector2f velocity = sf::Vector2f();
	float cloudFrequency;
	sf::Time timeSinceCloud;
};

