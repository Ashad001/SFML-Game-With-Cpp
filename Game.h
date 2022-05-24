#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <string>
#include <stdlib.h>
#include "Grid.h"
#include "Player.h"
#include "Enemy.h"
#include "Coin.h"

using namespace std;

class Game
{
private:
	// Attributes
	sf::RenderWindow* Window;
	sf::View* Camera;
	sf::Event EVNT;
	sf::Clock DTClock;
	float DeltaTime;
	Grid* grids;
	Player* player;
	vector<std::shared_ptr<Enemy>> enemies;
	Enemy* tempenm;
	sf::Font font;
	sf::Text text;


	vector<std::shared_ptr<Coin>> coins;
	Coin* tempCoin;
	int CoinsCollected;

	int LEVEL;

	int moves;
	//int EnemyCount; // Optimzed

	// Sounds
	sf::Music Intro;
	sf::SoundBuffer CoinBuffer;
	sf::Sound CoinSound;
	sf::SoundBuffer EnemyKill;
	sf::Sound EnemySound;

	// Private Setters
	void SetWindow();
public:
	// Constructors / Destructors
	Game();
	virtual ~Game();

	void SetEntites(bool PlayerGenerate);
	// Public Functions / Setters
	void UpdateEvents();
	void UpdateDT();
	void Update();
	void Render();
	void Run();
	void DeleteEntities(); // Except Enemy..!
};