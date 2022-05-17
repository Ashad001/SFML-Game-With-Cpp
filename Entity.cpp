#include "Entity.h"

Entity::Entity(sf::Window&i_win)
{

	this->i_win = &i_win;
	grids = new Grid;
	grids->SetGrids();
	IsDead = false;
}
