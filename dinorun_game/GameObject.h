#pragma once
#include <SFML/Graphics.hpp>;

class GameObject
{
public:
	GameObject();

	void Update();//////////// sort out virtual function stuff
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

