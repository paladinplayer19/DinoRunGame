#include "Player.h"
#include "AnimatingObject.h"
#include <iostream>

sf::Texture* Player::playerRunning1 = nullptr;
sf::Texture* Player::playerRunning2 = nullptr;
sf::Texture* Player::playerCrouch1 = nullptr;
sf::Texture* Player::playerCrouch2 = nullptr;

Player::Player(Game* newGame, sf::Vector2f newScreenSize)
	: AnimatingObject()
	, gravity(2000)
	, score(0)
	, jumpBuffer()
	, jumpSound()
	, screenSize(newScreenSize)
	, JUMP_SPEED(-810)
	, canJump(false)
	, hasPressedDown(false)
	, orginalCollider()
{
	// Set position
	ChangePos(sf::Vector2f(100, 100.0f));

	// Load animation frames
	if (playerRunning1 == nullptr)
	{
		playerRunning1 = new sf::Texture();
		playerRunning1->loadFromFile("Assets/Graphics/dino-run-1.png");
	}
	if (playerRunning2 == nullptr)
	{
		playerRunning2 = new sf::Texture();
		playerRunning2->loadFromFile("Assets/Graphics/dino-run-2.png");
	}
	if (playerCrouch1 == nullptr)
	{
		playerCrouch1 = new sf::Texture();
		playerCrouch1->loadFromFile("Assets/Graphics/dino-crouch-1.png");
	}
	if (playerCrouch2 == nullptr)
	{
		playerCrouch2 = new sf::Texture();
		playerCrouch2->loadFromFile("Assets/Graphics/dino-crouch-2.png");
	}



	// Setup animations
	Animation* run = CreateAnimation("run");
	Animation* crouchRun = CreateAnimation("crouchRun");

	run->AddFrame(playerRunning1);
	run->AddFrame(playerRunning2);

	crouchRun->AddFrame(playerCrouch1);
	crouchRun->AddFrame(playerCrouch2);

	run->SetPlayBackSpeed(10);
	run->SetLoop(true);

	crouchRun->SetPlayBackSpeed(10);
	crouchRun->SetLoop(false);


	
	Play("run");

	// gets non modified collider
	orginalCollider = collider;

	// Loads jump sound
	jumpBuffer.loadFromFile("Assets/Audio/jump.wav");
	jumpSound.setBuffer(jumpBuffer);

}

void Player::Update(sf::Time frameTime)
{

	AnimatingObject::Update(frameTime);

	// Allows the player to jump and play the corresponding audio 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && canJump == true)
	{
		Jump(frameTime);
		jumpSound.play();
		canJump = false;
	}

	// Applies gravity
	velocity.y += gravity * frameTime.asSeconds();
	
}


void Player::Jump(sf::Time frameTime)
{
	
	hasPressedDown = false;
	velocity.y = JUMP_SPEED;
	Play("run");
	
}

void Player::Crouch()
{
	hasPressedDown = true;
	Play("crouchRun");
	
}

void Player::SetCanJump(bool newCanJump)
{
	canJump = newCanJump;
}

sf::FloatRect Player::GetCollider()
{
	collider = sprite.getGlobalBounds();

	

	// Modify collider if in crouch mode
	if (hasPressedDown == true)
	{
		
		collider.top = sprite.getPosition().y;
		collider.height = sprite.getGlobalBounds().height /2;

	}
	else
	{
		collider = sprite.getGlobalBounds();
	}

	
	return collider;
}





