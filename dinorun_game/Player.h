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
	

private:
	

	float gravity;
	static sf::Texture* playerRunning1;
	static sf::Texture* playerRunning2;
	static sf::Texture* playerCrouch1;
	static sf::Texture* playerCrouch2;
	int score;
	sf::SoundBuffer jumpBuffer;
	sf::SoundBuffer hitBuffer;
	sf::SoundBuffer itemBuffer;
	sf::Sound jumpSound;
	sf::Sound hitSound;
	sf::Sound itemSound;
	sf::Vector2f screenSize;
	int JUMP_SPEED;
	bool canJump;
	
	

};

