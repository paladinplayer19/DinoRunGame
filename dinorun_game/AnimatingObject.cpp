#include "AnimatingObject.h"
#include <iostream>
AnimatingObject::AnimatingObject()
	: GameObject()
	, animations()
	, currentAnimation(nullptr)
	, speed(10)
	, position()
	, collider()
{
}

Animation* AnimatingObject::CreateAnimation(std::string name)
{
	Animation* newAnimation = &animations[name];

	newAnimation->SetSprite(&sprite);
	return newAnimation;
	
}

void AnimatingObject::Play()
{
	if (currentAnimation)
	{
		currentAnimation->Play();
	}
}

void AnimatingObject::Play(std::string newAnimation)
{
	Stop();

	currentAnimation = &animations[newAnimation];

	Play();
}

void AnimatingObject::Pause()
{
	if (currentAnimation)
	{
		currentAnimation->Pause();
	}
}

void AnimatingObject::Stop()
{
	if (currentAnimation)
	{
		currentAnimation->Stop();
	}
}

void AnimatingObject::Update(sf::Time frameTime)
{
	GameObject::Update(frameTime);

	
	if (currentAnimation)
	{
		currentAnimation->Update(frameTime);
	}
}
