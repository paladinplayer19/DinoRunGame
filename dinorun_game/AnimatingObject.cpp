#include "AnimatingObject.h"

AnimatingObject::AnimatingObject()
	: sprite()
	, spriteTexture()
	, speed()
	, position()
	, collider()
{
}

Animation* AnimatingObject::CreateAnimation(std::string name)
{
	return nullptr;
}

void AnimatingObject::Play()
{
}

void AnimatingObject::Play(std::string newAnimation)
{
}

void AnimatingObject::Pause()
{
}

void AnimatingObject::Stop()
{
}

void AnimatingObject::Update(sf::Time frameTime)
{
}
