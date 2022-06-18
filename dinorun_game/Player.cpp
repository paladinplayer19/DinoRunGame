#include "Player.h"

Player::Player()
	: score()
	, jumpBuffer()
	, hitBuffer()
	, itemBuffer()
	, jumpSound()
	, hitSound()
	, itemSound()
{
}

void Player::Jump()
{
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
