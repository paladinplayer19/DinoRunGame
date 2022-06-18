#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Game
{
public:

	Game();

	void Run();
	void Update();
	void Draw();
	void DisplayGameOver();
	void SetupGame();
	void SpawnObstacle();
	void Reset();

private:
	sf::Music backgroundMusic;
	bool hasCollided;
	std::vector<Cloud*> cloudVector;
	int score;
	sf::FloatRect quitCollider;
	sf::FloatRect resetCollider;
	sf::Vector2f mousePos;
};

