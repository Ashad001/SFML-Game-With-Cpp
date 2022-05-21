#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
class Entity
{
private:		
	sf::Window* i_win;

public:
	Grid* grids;

	Entity(sf::Window & i_win);



};

