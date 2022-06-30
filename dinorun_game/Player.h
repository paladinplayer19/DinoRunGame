#pragma once
#include "AnimatingObject.h"
#include <SFML/Audio.hpp>

class Game;
class Floor;

class Player : public AnimatingObject
{
public:
	Player(Game* newGame, sf::Vector2f newScreenSize);

	virtual void Update(sf::Time frameTime) override;
	void Jump(sf::Time frameTime);
	void Crouch();
	void SetCanJump(bool newCanJump);
	virtual sf::FloatRect GetCollider();

private:
	

	static sf::Texture* playerRunning1;
	static sf::Texture* playerRunning2;
	static sf::Texture* playerCrouch1;
	static sf::Texture* playerCrouch2;
	float gravity;
	int score;
	sf::SoundBuffer jumpBuffer;
	sf::Sound jumpSound;
	sf::Vector2f screenSize;
	int JUMP_SPEED;
	bool canJump;
	bool hasPressedDown;
	sf::FloatRect orginalCollider;
	
	

};

