#pragma once

#include "Grid.h"
#include <SFML/Graphics.hpp>

class Player : public Grid
{
private:
	sf::RectangleShape Body;

public:
	Player(float GridSize);
	void MovePlayer();
	void Draw(sf::RenderWindow *i_window);
	~Player();
};

