#include "Game.h"

Game::Game()
	: backgroundMusic()
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
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Works!");


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//window.draw();
		window.display();

	}
}

void Game::Update()
{
}

void Game::Draw()
{
}

void Game::DisplayGameOver()
{
}

void Game::SetupGame()
{
}

void Game::SpawnObstacle()
{
}

void Game::Reset()
{
}
