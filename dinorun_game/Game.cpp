#include "Game.h"
#include <iostream>
Game::Game()
	: gameClock()
	, window(sf::VideoMode::getDesktopMode(), "Dino Run", sf::Style::Titlebar | sf::Style::Close)
	, backgroundMusic()
	, hasCollided()
	, cloudVector()
	, score()
	, quitCollider()
	, resetCollider()
	, mousePos()
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

	
	

	for (int i = 0; i < cloudVector.size(); ++i)
	{

		cloudVector[i]->Update(deltaTime);

	}
}

void Game::Draw()
{
	window.clear();
    
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

	//player.SetPosition(sf::Vector2f(100, screenSize.y / 2 - 50));

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
