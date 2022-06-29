#include "Game.h"
#include <iostream>
#include <sstream>
Game::Game()
	: gameClock()
	, floor(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height))
	, player(this, sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height))
	, meat(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height))
	, window(sf::VideoMode::getDesktopMode(), "Dino Run", sf::Style::Titlebar | sf::Style::Close)
	, hasCollided()
	, cloudVector()
	, score(0)
	, quitCollider()
	, resetCollider()
	, mousePos(0.0f,0.0f)
	, backgroundMusic()
	, backgroundMusicBuffer()
	, collidetestSize()
	, colliderRectangleTestFloor()
	, collidetestSizeplayer()
	, colliderRectangleTestplayer()
	, font()
	, text()
	, scoreText()
	, timePassed(0.0f)
	, speedCount(-500.0f)
	, isGameOver(false)
{
	backgroundMusicBuffer.loadFromFile("Assets/Audio/music.ogg"); /// Uncomment to get background music
	backgroundMusic.setBuffer(backgroundMusicBuffer);

	
	font.loadFromFile("Assets/Font/enter-command.ttf");
	
	text.setFont(font);
	text.setPosition(window.getSize().x - 400, 0 + 10);
	text.setString("Score: ");
	scoreText.setFont(font);
	scoreText.setPosition(text.getPosition().x + 100, 0 + 10);
	
		
	
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
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Down) {

				player.Crouch();
			}
		}

		
		Update();

		Draw();

		

	}
}

void Game::Update()
{
		
	
	sf::Time deltaTime = gameClock.restart();

	timePassed += deltaTime.asSeconds();

	if (!isGameOver)
	{
		score++;
		
		///// start of code
		scoreText.setString(std::to_string(score));

		player.Update(deltaTime);

		meat.Update(deltaTime);
		meat.HandleCollision(player);

		floor.Update(deltaTime);
		floor.HandleCollision(player);

		if (meat.GetIsTouching() == true)
		{
			score += 250;
		}

		for (int i = 0; i < birdVector.size(); ++i)
		{
			birdVector[i]->HandleCollision(player);

			if (birdVector[i]->GetIsTouching())
			{
				isGameOver = true;

			}

			if (timePassed >= 10.0f)
			{
				speedCount--;
				birdVector[i]->SetVelocity(sf::Vector2f(speedCount, 0.0f));
				timePassed = 0;
			}

			birdVector[i]->Update(deltaTime);

		}
		for (int i = 0; i < cactusVector.size(); ++i)
		{
			cactusVector[i]->HandleCollision(player);

			if (cactusVector[i]->GetIsTouching())
			{
				isGameOver = true;


			}

			if (timePassed >= 10.0f)
			{
				speedCount--;
				cactusVector[i]->SetVelocity(sf::Vector2f(speedCount, 0.0f));
				timePassed = 0;
			}

			cactusVector[i]->Update(deltaTime);

		}

		for (int i = 0; i < cloudVector.size(); ++i)
		{

			cloudVector[i]->Update(deltaTime);

		}

		// Test Colliders
		collidetestSize = sf::Vector2f(floor.GetCollider().width, floor.GetCollider().height);
		colliderRectangleTestFloor = sf::RectangleShape(collidetestSize);
		colliderRectangleTestFloor.setPosition(floor.GetPosition().x, floor.GetPosition().y);
		colliderRectangleTestFloor.setFillColor(sf::Color::Green);

		collidetestSizeplayer = sf::Vector2f(player.GetCollider().width, player.GetCollider().height);
		colliderRectangleTestplayer = sf::RectangleShape(collidetestSizeplayer);
		colliderRectangleTestplayer.setPosition(player.GetPosition().x, player.GetPosition().y);
		colliderRectangleTestplayer.setFillColor(sf::Color::Red);



		///// end of code
	}
	else
	{
		DisplayGameOver();
		backgroundMusic.stop();
	}
	
	
	

	
}

void Game::Draw()
{
	
	window.clear();
    
	//window.draw(colliderRectangleTestFloor);
	//window.draw(colliderRectangleTestplayer);
	player.Draw(window);
	floor.Draw(window);

	if (meat.GetIsAlive() == true)
	{
	  meat.Draw(window);
	}

	window.draw(scoreText);
	window.draw(text);

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
	player.SetCanJump(false);

	meat.SetVelocity(sf::Vector2f(0.0f, 0.0f));
	for (int i = 0; i < cactusVector.size(); ++i)
	{

		cactusVector[i]->SetVelocity(sf::Vector2f(0.0f, 0.0f));

	}
	for (int i = 0; i < birdVector.size(); ++i)
	{

		birdVector[i]->SetVelocity(sf::Vector2f(0.0f, 0.0f));

	}
	for (int i = 0; i < cloudVector.size(); ++i)
	{

		cloudVector[i]->SetVelocity(sf::Vector2f(0.0f, 0.0f));

	}

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
	   else
	   {
		// spawn cactus
		cactusVector.push_back(new Cactus(screenSize));

	   }

	   CHOICE = rand() % 2;
	}

	int numbClouds = 5;

	for (int i = 0; i < numbClouds; ++i)
	{
		
		cloudVector.push_back(new Cloud(screenSize));
	}
}


void Game::Reset()
{
}
