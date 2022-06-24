#include "Floor.h"

sf::Texture* Floor::floorTexture = nullptr;

Floor::Floor(sf::Vector2f newScreenSize)
	: screenSize(newScreenSize)
	, collider()
{
	if (floorTexture == nullptr)
	{
		floorTexture = new sf::Texture();
		floorTexture->loadFromFile("Assets/Graphics/floor.png");
	}
	
	sprite.setTexture(*floorTexture);
	

}

void Floor::Update(sf::Time deltaTime)
{
	GameObject::Update(deltaTime);
	sprite.setPosition(0.0f, screenSize.y - 400);
}


