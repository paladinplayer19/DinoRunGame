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
	, hitBuffer()
	, itemBuffer()
	, jumpSound()
	, hitSound()
	, itemSound()
	, screenSize(newScreenSize)
	, JUMP_SPEED(5)
{
	ChangePos(sf::Vector2f(screenSize.x /2, screenSize.y /2));
	SetVelocity(sf::Vector2f(0, 10));
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
	
	sprite.setTexture(*playerRunning1);
	

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


	
}

void Player::Update(sf::Time frameTime)
{
	
	AnimatingObject::Update(frameTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		Jump(frameTime);
	}

	velocity.y += gravity * frameTime.asSeconds();

}

void Player::Jump(sf::Time frameTime)
{
	velocity.y -= JUMP_SPEED;

	Play("jump");
}

void Player::Crouch()
{
}

bool Player::isCollidingObstacle()
{
	return false;
}

bool Player::isCollidingMeat()
{
	return false;
}
