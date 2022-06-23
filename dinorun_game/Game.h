#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cloud.h"

class Game
{
public:

	Game();

	void Run();
	void Update();
	void Draw();
	void DisplayGameOver();
	void SpawnObstacle();
	void Reset();

private:
	void SetupGame();

	sf::Clock gameClock;
	sf::RenderWindow window;
	sf::Music backgroundMusic;
	bool hasCollided;
	std::vector<Cloud*> cloudVector;
	int score;
	sf::FloatRect quitCollider;
	sf::FloatRect resetCollider;
	sf::Vector2f mousePos;
};

