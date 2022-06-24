#include "Game.h"
#include <iostream>
Game::Game()
	: gameClock()
	, player(this, sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height))
	, window(sf::VideoMode::getDesktopMode(), "Dino Run", sf::Style::Titlebar | sf::Style::Close)
	, backgroundMusic()
	, hasCollided()
	, cloudVector()
	, score(0)
	, quitCollider()
	, resetCollider()
	, mousePos(0.0f,0.0f)
	, floor(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height))
{
}

void Game::Run()
{
	
	SetupGame();

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			// Closes Window
			window.close();
		}

		
		Update();

		Draw();

		

	}
}

void Game::Update()
{
	sf::Time deltaTime = gameClock.restart();

	player.Update(deltaTime);
	
	floor.Update(deltaTime);

	for (int i = 0; i < birdVector.size(); ++i)
	{

		birdVector[i]->Update(deltaTime);

	}
	for (int i = 0; i < cactusVector.size(); ++i)
	{

		cactusVector[i]->Update(deltaTime);

	}

	for (int i = 0; i < cloudVector.size(); ++i)
	{

		cloudVector[i]->Update(deltaTime);

	}
}

void Game::Draw()
{
	

	window.clear();
    
	player.Draw(window);

	for (int i = 0; i < birdVector.size(); ++i)
	{
		birdVector[i]->Draw(window);
	}
	for (int i = 0; i < cactusVector.size(); ++i)
	{
		cactusVector[i]->Draw(window);
	}

	floor.Draw(window);

	for (int i = 0; i < cloudVector.size(); ++i)
	{
		cloudVector[i]->Draw(window);
	}

	window.display();
}

void Game::DisplayGameOver()
{
}

void Game::SetupGame()
{
	sf::Vector2f screenSize(window.getSize());
	int numbObstacles = 5;

	int CHOICE = 0;
	CHOICE = rand() % 2;

	for (int i = 0; i < numbObstacles; ++i)
	{

		
	if (CHOICE == 1)
	{
		// spawn bird
		birdVector.push_back(new Bird(screenSize));

	}
	else {
		// spawn cactus
		cactusVector.push_back(new Cactus(screenSize));

	}
	CHOICE = rand() % 2;
	}

	int numbStars = 5;

	for (int i = 0; i < numbStars; ++i)
	{
		
		cloudVector.push_back(new Cloud(screenSize));
	}
}

void Game::SpawnObstacle()
{
}

void Game::Reset()
{
}
