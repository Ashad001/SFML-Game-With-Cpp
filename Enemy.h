#pragma once
#include "Grid.h"
#include "Player.h"
#include <SFML/Graphics.hpp>


class Enemy
{
private:
	sf::Window* e_win;
	Grid* grids;
	sf::Texture *enemyTex;
	sf::Sprite body;
	Animation* enemy_animation;

public:
	Enemy(float GridSize, sf::Window& window, sf::Vector2f pos);
	sf::FloatRect SetHitBox();
	void Draw(sf::RenderWindow& e_window);
	void SetPosition(float x, float y);
	void UpdateEnemy(float DT);
	~Enemy();
};