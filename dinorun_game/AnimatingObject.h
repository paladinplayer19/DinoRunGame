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
	virtual void Update(sf::Time frameTime) override;

private:
	std::map<std::string, Animation> animations;
	Animation* currentAnimation;
protected:
	sf::Sprite sprite;
	sf::Texture spriteTexture;
	float speed;
	sf::Vector2f position;
	sf::FloatRect collider;
};

