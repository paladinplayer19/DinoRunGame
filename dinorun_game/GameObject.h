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
	sf::FloatRect GetCollider();

	sf::Vector2f GetPosition();

protected:
	bool IsColliding(GameObject& other);
	sf::Vector2f GetCollisionDepth(GameObject& other);

	sf::Sprite sprite;
	float speed;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::FloatRect collider;
	
};

