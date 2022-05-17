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
	int moves;    
	
	
	// Private Setters
	void SetWindow();
public:
	// Constructors / Destructors
	Game();
	virtual ~Game();


	// Public Functions / Setters
	void UpdateEvents();
	void UpdateDT();
	void Update();
	void Render();
	void Run();

};