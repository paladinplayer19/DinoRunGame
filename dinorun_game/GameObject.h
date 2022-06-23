#pragma once
#include <SFML/Graphics.hpp>;

class GameObject
{
public:
	GameObject();

	virtual void Update(sf::Time frameTime);
	void Draw(sf::RenderTarget& target);
	void ChangePos(sf::Vector2f newPos);
	void SetVelocity(sf::Vector2f newVel);

	sf::Vector2f GetPosition();

protected:
	sf::Sprite sprite;
	float speed;
	sf::Vector2f position;
	sf::FloatRect collider;
	sf::Vector2f velocity;
};

