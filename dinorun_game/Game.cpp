#include "Game.h"
#include <iostream>
#include <sstream>
Game::Game()
	: gameClock()
	, floor(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height))
	, player(this, sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height))
	, meat(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height))
	, window(sf::VideoMode::getDesktopMode(), "Dino Run", sf::Style::Titlebar | sf::Style::Close)
	, birdVector()
	, cactusVector()
	, cloudVector()
	, score(0)
	, quitCollider()
	, resetCollider()
	, mousePos(0.0f,0.0f)
	, quitButtonTexture()
	, resetButtonTexture()
	, resetButton()
	, quitButton()
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
	, speedCount(10.0f)
	, isGameOver(false)
	, gameOverText()
{
	backgroundMusicBuffer.loadFromFile("Assets/Audio/music.ogg"); /// Uncomment to get background music
	backgroundMusic.setBuffer(backgroundMusicBuffer);

	
	font.loadFromFile("Assets/Font/enter-command.ttf");
	
	text.setFont(font);
	text.setPosition(window.getSize().x - 400, 0 + 10);
	text.setString("Score: ");
	scoreText.setFont(font);
	scoreText.setPosition(text.getPosition().x + 100, 0 + 10);
	

	resetButtonTexture.loadFromFile("Assets/Graphics/button-retry.png");
	resetButton.setTexture(resetButtonTexture);
	resetButton.setPosition((window.getSize().x /2) - 100, window.getSize().y / 2);
	resetCollider = resetButton.getGlobalBounds();


	quitButtonTexture.loadFromFile("Assets/Graphics/button-quit.png");
	quitButton.setTexture(quitButtonTexture);
	quitButton.setPosition((window.getSize().x / 2) + 100, window.getSize().y / 2);
	quitCollider = quitButton.getGlobalBounds();

	gameOverText.setFont(font);
	gameOverText.setPosition(window.getSize().x / 2, window.getSize().y / 2 - 150);
	gameOverText.setCharacterSize(30);
	gameOverText.setString("Game Over!");

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
	// gets mouse position
	mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

	sf::Time deltaTime = gameClock.restart();

	// checks if game is over
	if (!isGameOver)
	{
	    timePassed += deltaTime.asSeconds();

		// increments score each frame of time played
		score++;
		
		// Sets string to current score aquired
		scoreText.setString(std::to_string(score));
		
		// Updates objects
		player.Update(deltaTime);
		floor.Update(deltaTime);
		meat.Update(deltaTime);

		meat.SetVelocity(sf::Vector2f(-1000.0f, 0.0f));


		// Checks to see if player collides with meat or floor
		meat.HandleCollision(player);
		floor.HandleCollision(player);

		// increments score if player has touched meat
		if (meat.GetIsTouching() == true)
		{
			score += 250;
		}

		if (timePassed >= 1.0f)
		{
			// increments speed of obstacles based on how long player has lasted
			speedCount += 30;
			timePassed = 0;
		}
		// Updates birds
		for (int i = 0; i < birdVector.size(); ++i)
		{
			birdVector[i]->HandleCollision(player);

			// checks to see if player is colliding with bird
			if (birdVector[i]->GetIsTouching())
			{
				isGameOver = true;

			}

			// increases speed of bird based on how long game has been played
		    birdVector[i]->SetVelocity(sf::Vector2f(-speedCount, 0.0f));
			
				
			

			birdVector[i]->Update(deltaTime);

		}
		// Updates cacti
		for (int i = 0; i < cactusVector.size(); ++i)
		{
			cactusVector[i]->HandleCollision(player);

			// checks to see if player is colliding with cactus
			if (cactusVector[i]->GetIsTouching())
			{
				
				isGameOver = true;


			}

			
			// increases speed of cactus based on how long game has been played
			cactusVector[i]->SetVelocity(sf::Vector2f(-speedCount, 0.0f));
				
			

			cactusVector[i]->Update(deltaTime);

		}

		// Updates clouds
		for (int i = 0; i < cloudVector.size(); ++i)
		{

			cloudVector[i]->Update(deltaTime);
			cloudVector[i]->SetVelocity(sf::Vector2f(-1000.0f, 0.0f));
		}

		//// Test Colliders
		//collidetestSize = sf::Vector2f(floor.GetCollider().width, floor.GetCollider().height);
		//colliderRectangleTestFloor = sf::RectangleShape(collidetestSize);
		//colliderRectangleTestFloor.setPosition(floor.GetPosition().x, floor.GetPosition().y);
		//colliderRectangleTestFloor.setFillColor(sf::Color::Green);

		//collidetestSizeplayer = sf::Vector2f(player.GetCollider().width, player.GetCollider().height);
		//colliderRectangleTestplayer = sf::RectangleShape(collidetestSizeplayer);
		//colliderRectangleTestplayer.setPosition(player.GetPosition().x, player.GetPosition().y);
		//colliderRectangleTestplayer.setFillColor(sf::Color::Red);




	}
	else
	{
		// displays game over interface
		DisplayGameOver();
		
	}
	
	
	

	
}

void Game::Draw()
{
	// Draws all objects / texts within the level

	window.clear();
    
	//window.draw(colliderRectangleTestFloor);
	//window.draw(colliderRectangleTestplayer);
	
	
	player.Draw(window);
	floor.Draw(window);

	// checks if meat is meant to be visible or not
	if (meat.GetIsAlive() == true)
	{
	  meat.Draw(window);
	}
	
	// updates score
	window.draw(scoreText);
	window.draw(text);

	// checks if the game is over
	if (isGameOver == true)
	{
		window.draw(gameOverText);
		window.draw(resetButton);
		window.draw(quitButton);
	}

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
	// stops all objects from moving
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
	// checks if mouse position is on the quit collider
	if (quitCollider.contains(mousePos))
	{
		// checks if mouse button left was clicked
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			//closes window
			window.close();
		}
	}

	// checks if mouse position is on the reset collider
	if (resetCollider.contains(mousePos))
	{


		// checks if mouse button left was clicked
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			//resets level
			Reset();
			
		}
	}
}

void Game::SetupGame()
{
	// plays background music
	backgroundMusic.play();

	sf::Vector2f screenSize(window.getSize());
	int numbCactus = 1;
	int numbBirds = 1;
	int numbClouds = 5;

	
	// creates object instances and puts them into a vector
	for (int i = 0; i < numbBirds; ++i)
	{
		// Create bird instance
		birdVector.push_back(new Bird(screenSize));
	}
	for (int i = 0; i < numbCactus; ++i)
	{
		// Create cactus instance 
		cactusVector.push_back(new Cactus(screenSize));

	}

	for (int i = 0; i < numbClouds; ++i)
	{
		// Create cloud instance
		cloudVector.push_back(new Cloud(screenSize));
	}
}


void Game::Reset()
{
	// resets score to 0
	score = 0;

	// Resets all objects back to normal positions
	meat.Reset();
	for (int i = 0; i < cactusVector.size(); ++i)
	{

		cactusVector[i]->Reset();

	}
	for (int i = 0; i < birdVector.size(); ++i)
	{

		birdVector[i]->Reset();

	}
	for (int i = 0; i < cloudVector.size(); ++i)
	{

		cloudVector[i]->Reset();

	}
	
	// allows game to be run again
	isGameOver = false;

	

}
