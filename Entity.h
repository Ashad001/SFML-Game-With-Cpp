#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
class Entity
{
private:		
	sf::Window* i_win;
	Grid* grids;
	bool IsDead;
public:
	virtual void Draw() = 0;
	virtual sf::FloatRect GetHitBox() = 0;
	Entity(sf::Window & i_win);



};

