#pragma once
#include "GameObject.h"
class Floor : public GameObject
{
public:
	Floor(sf::Vector2f newScreenSize);

	virtual void Update(sf::Time deltaTime) override;
	void HandleCollision(GameObject& other);
	sf::FloatRect GetFloorCollider();
private:
	static sf::Texture* floorTexture;
	sf::Vector2f screenSize;
	
};

