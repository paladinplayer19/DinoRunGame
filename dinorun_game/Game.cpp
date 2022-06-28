#include "Game.h"
#include <iostream>
Game::Game()
	: gameClock()
	, player(this, sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height))
	, window(sf::VideoMode::getDesktopMode(), "Dino Run", sf::Style::Titlebar | sf::Style::Close)
	, hasCollided()
	, cloudVector()
	, score(0)
	, quitCollider()
	, resetCollider()
	, mousePos(0.0f,0.0f)
	, floor(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height))
	, backgroundMusic()
	, backgroundMusicBuffer()
	, collidetestSize()
	, colliderRectangleTestFloor()
	, collidetestSizeplayer()
	, colliderRectangleTestplayer()
{
	//backgroundMusicBuffer.loadFromFile("Assets/Audio/music.ogg"); /// Uncomment to get background music
	//backgroundMusic.setBuffer(backgroundMusicBuffer);

	sf::Font font;
	font.loadFromFile("Assets/Font/enter-command.ttf");

	sf::Text text;
	text.setFont(font);
	text.setPosition(window.getSize().x - 10, 0 + 10);

	
	
	
}

void Game::Run()
{
	backgroundMusic.play();
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

	score++;

	player.Update(deltaTime);
	
	floor.Update(deltaTime);
	floor.HandleCollision(player);

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

	// Test Colliders
	 collidetestSize = sf::Vector2f(floor.GetCollider().width , floor.GetCollider().height);
	 colliderRectangleTestFloor = sf::RectangleShape(collidetestSize);
	 colliderRectangleTestFloor.setPosition(floor.GetPosition().x, floor.GetPosition().y);
	 colliderRectangleTestFloor.setFillColor(sf::Color::Green);

	 collidetestSizeplayer = sf::Vector2f(player.GetCollider().width, player.GetCollider().height);
	 colliderRectangleTestplayer = sf::RectangleShape(collidetestSizeplayer);
	 colliderRectangleTestplayer.setPosition(player.GetPosition().x, player.GetPosition().y);
	 colliderRectangleTestplayer.setFillColor(sf::Color::Red);

	/*if (player.isCollidingObstacle() == true)
	{
		DisplayGameOver();
	}*/
}

void Game::Draw()
{
	
	window.clear();
    
	floor.Draw(window);
	window.draw(colliderRectangleTestFloor);
	window.draw(colliderRectangleTestplayer);
	player.Draw(window);

	for (int i = 0; i < birdVector.size(); ++i)
	{
		birdVector[i]->Draw(window);
	}
	for (int i = 0; i < cactusVector.size(); ++i)
	{
		cactusVector[i]->Draw(window);
	}


	for (int i = 0; i < cloudVector.size(); ++i)
	{
		cloudVector[i]->Draw(window);
	}

	window.display();
}

void Game::DisplayGameOver()
{
	std::cout << "Hit" << std::endl;
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


void Game::Reset()
{
}
