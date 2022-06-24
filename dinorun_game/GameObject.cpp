#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
	: sprite()
	, speed(10)
	, position(0,0)
	, collider()
	, velocity(0,0)
{
}

void GameObject::Update(sf::Time frameTime)
{
	ChangePos(position + velocity * frameTime.asSeconds());
}

void GameObject::Draw(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void GameObject::ChangePos(sf::Vector2f newPosition)
{
	position = newPosition;
	sprite.setPosition(position);
}

void GameObject::SetVelocity(sf::Vector2f newVelocity)
{
	velocity = newVelocity;
}

sf::Vector2f GameObject::GetPosition()
{
	return position;
}
