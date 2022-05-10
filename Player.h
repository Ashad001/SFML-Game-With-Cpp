#pragma once

#include "Grid.h"
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::RectangleShape Body;
	Grid* grids;
public:
	Player(float GridSize);
	void MovePlayer(const float DT);
	void Draw(sf::RenderWindow& i_window);
	~Player();
};

