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
	Grid *grids;
	Player* player;
	vector<Enemy> enemies;

	int moves;   
	//int EnemyCount; // Optimzed
	
	
	// Private Setters
	void SetWindow();
public:
	// Constructors / Destructors
	Game();
	virtual ~Game();

	void SetEntites();
	// Public Functions / Setters
	void UpdateEvents();
	void UpdateDT();
	void Update();
	void Render();
	void Run();

};