#include "AnimatingObject.h"
#include <iostream>
AnimatingObject::AnimatingObject()
	: GameObject()
	, animations()
	, currentAnimation(nullptr)
	, spriteTexture()
	, speed(10)	
{
}

Animation* AnimatingObject::CreateAnimation(std::string name)
{
	// Creates a new animation
	Animation* newAnimation = &animations[name];

	newAnimation->SetSprite(&sprite);
	return newAnimation;
	
}

void AnimatingObject::Play()
{
	// plays current animation selected
	if (currentAnimation)
	{
		currentAnimation->Play();
	}
}

void AnimatingObject::Play(std::string newAnimation)
{
	Stop();

	// play desired animation
	currentAnimation = &animations[newAnimation];

	Play();
}

void AnimatingObject::Pause()
{
	// pauses animation
	if (currentAnimation)
	{
		currentAnimation->Pause();
	}
}

void AnimatingObject::Stop()
{
	// stops animation
	if (currentAnimation)
	{
		currentAnimation->Stop();
	}
}

void AnimatingObject::Update(sf::Time frameTime)
{
	GameObject::Update(frameTime);

	// updates current animation
	if (currentAnimation)
	{
		currentAnimation->Update(frameTime);
	}
}
