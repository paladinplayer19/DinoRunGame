#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cloud.h"
#include "Player.h"
#include "Floor.h"
#include "Bird.h"
#include "Cactus.h"
#include "Meat.h"

class Game
{
public:

	Game();

	void Run();
	void Update();
	void Draw();
	void DisplayGameOver();
	void Reset();

private:
	void SetupGame();

	sf::Clock gameClock;
	Floor floor;
	Player player;
	Meat meat;
	sf::RenderWindow window;
	std::vector<Bird*> birdVector;
	std::vector<Cactus*> cactusVector;
	std::vector<Cloud*> cloudVector;
	int score;
	sf::FloatRect quitCollider;
	sf::FloatRect resetCollider;
	sf::Vector2f mousePos;
	sf::Texture quitButtonTexture;
	sf::Texture resetButtonTexture;
	sf::Sprite resetButton;
	sf::Sprite quitButton;
	sf::Sound backgroundMusic;
	sf::SoundBuffer backgroundMusicBuffer;
	sf::Vector2f collidetestSize;
	sf::RectangleShape colliderRectangleTestFloor;
	sf::Vector2f collidetestSizeplayer;
	sf::RectangleShape colliderRectangleTestplayer;
	sf::Font font;
	sf::Text text;
	sf::Text scoreText;
	float timePassed;
	float speedCount;
	bool isGameOver;
	sf::Text gameOverText;
	



};

