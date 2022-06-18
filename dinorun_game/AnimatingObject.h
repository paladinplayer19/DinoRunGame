#pragma once
#include "GameObject.h"
#include "Animation.h";

class AnimatingObject : public GameObject
{
public:
	AnimatingObject();

	Animation* CreateAnimation(std::string name);
	void Play();
	void Play(std::string newAnimation);
	void Pause();
	void Stop();
	void Update(sf::Time frameTime);


protected:
	sf::Sprite sprite;
	sf::Texture spriteTexture;
	float speed;
	sf::Vector2f position;
	sf::FloatRect collider;
};

