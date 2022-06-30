#pragma once
#include "GameObject.h"
#include <SFML/Audio.hpp>
class Meat : public GameObject
{
public:
	Meat(sf::Vector2f newScreenSize);

	virtual void Update(sf::Time deltaTime) override;
	void HandleCollision(GameObject& other);
	bool GetIsTouching();
	bool GetIsAlive();

	void Reset();

private:



	static sf::Texture* meatTexture;
	sf::Vector2f screenSize;
	sf::Vector2f newPosition = sf::Vector2f();
	sf::Vector2f currentPosition = sf::Vector2f();
	sf::Vector2f velocity = sf::Vector2f();
	float meatFrequency;
	sf::Time timeSinceMeat;
	sf::SoundBuffer itemBuffer;
	sf::Sound itemSound;
	bool isTouching;
	bool isAlive;
};

