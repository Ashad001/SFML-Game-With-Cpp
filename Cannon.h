#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Grid.h"
#include "Bullet.h"
class Cannon
{
private:
	sf::Window* e_win;
	Grid* grids;
	sf::Texture* cannonTex;
	sf::Sprite body;
	Animation* cannon_animation;
	int c_rad;
	int speeed;

public:
	Cannon(float GridSize, sf::Window& window, sf::Vector2f pos);
	sf::FloatRect SetHitBox();
	void Draw(sf::RenderWindow& e_window);
	void SetPosition(float x, float y);
	void UpdateCannon(float DT);
	int CheckRadius(int checkrad);
	void ShootCannon(int if_rad);

	~Cannon();
};

