#pragma once
#include "Bullet.h"
//#include "Grid.h"
#include <SFML/Graphics.hpp>


class Enemy
{
private:
	sf::Window* e_win;
	//Grid* grids;
	sf::Texture enemyTex;
	sf::Sprite body;
public:
	Enemy(float GridSize, sf::Window& window);
	sf::FloatRect SetHitBox();
	void Draw(sf::RenderWindow& e_window);
	~Enemy();
};