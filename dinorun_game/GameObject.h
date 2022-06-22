#pragma once
#include <SFML/Graphics.hpp>;

class GameObject
{
public:
	GameObject();

	virtual void Update(sf::Time frameTime);
	void Draw();
	void ChangePos();

protected:
	sf::Sprite sprite;
	sf::Texture spriteTexture;
	float speed;
	sf::Vector2f position;
	sf::FloatRect collider;
	sf::Vector2f velocity;
};

