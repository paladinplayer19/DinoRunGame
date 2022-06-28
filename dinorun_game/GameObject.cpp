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

sf::FloatRect GameObject::GetCollider()
{
	collider = sprite.getGlobalBounds();

	return collider;
}

sf::Vector2f GameObject::GetPosition()
{
	return position;
}

bool GameObject::IsColliding(GameObject& other)
{
	sf::FloatRect myCollider = GetCollider();
	sf::FloatRect otherCollider = other.GetCollider();

	return myCollider.intersects(otherCollider);
}

sf::Vector2f GameObject::GetCollisionDepth(GameObject& other)
{

	sf::FloatRect myCollider = GetCollider();
	sf::FloatRect otherCollider = other.GetCollider();

	sf::Vector2f myPos(myCollider.left, myCollider.top);
	sf::Vector2f otherPos(otherCollider.left, otherCollider.top);

	sf::Vector2f myWidthHeight(myCollider.width, myCollider.height);
	sf::Vector2f otherWidthHeight(otherCollider.width, otherCollider.height);

	sf::Vector2f myCentre = myPos + 0.5f * myWidthHeight;
	sf::Vector2f otherCentre = otherPos + 0.5f * otherWidthHeight;

	sf::Vector2f distance = otherCentre - myCentre;
	sf::Vector2f minDistance = 0.5f * myWidthHeight + 0.5f * otherWidthHeight;

	if (distance.x < 0) {
		minDistance.x = -minDistance.x;
	}

	if (distance.y < 0) {
		minDistance.y = -minDistance.y;
	}

	sf::Vector2f depth = minDistance - distance;

	return depth;
}
