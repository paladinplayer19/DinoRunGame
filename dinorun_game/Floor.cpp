#include "Floor.h"
#include "Player.h"
sf::Texture* Floor::floorTexture = nullptr;

Floor::Floor(sf::Vector2f newScreenSize)
	: GameObject()
	, screenSize(newScreenSize)
	, canJump(true)
	, isTouching(false)
	
{
	// load texture
	if (floorTexture == nullptr)
	{
		floorTexture = new sf::Texture();
		floorTexture->loadFromFile("Assets/Graphics/floor.png");
	}
	
	//set texture
	sprite.setTexture(*floorTexture);
	
	
	ChangePos(sf::Vector2f(0.0f, screenSize.y - (screenSize.y / 4)));
}

void Floor::Update(sf::Time deltaTime)
{
	GameObject::Update(deltaTime);
	
	
}

void Floor::HandleCollision(GameObject& other)
{
	// Checking if the thing is actually the player
	Player* checkPlayer = dynamic_cast<Player*>(&other);

	// checks if checkPlayer has something in it
	if (checkPlayer == nullptr) {
		return;
	}
	// checks if there is collision

	if (!IsColliding(other))
	{
		isTouching = false;

		return;
	}

	isTouching = true;
	sf::Vector2f depth = GetCollisionDepth(other);
	sf::Vector2f absDepth = sf::Vector2f(abs(depth.x), abs(depth.y));
	sf::Vector2f playerPosition = checkPlayer->GetPosition();

	
	// blocks player from falling any further if they collide
	if (isTouching)
	{
      playerPosition.y -= absDepth.y;
	  canJump = true;
	  checkPlayer->SetCanJump(canJump);
	}
	


	checkPlayer->ChangePos(playerPosition);
		
	
	
}

sf::FloatRect Floor::GetFloorCollider()
{
	return collider;
}

bool Floor::GetCanJump()
{
	return canJump;
}


