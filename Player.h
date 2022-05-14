#pragma once

#include "Grid.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"

class Player
{
private:
	//sf::RectangleShape Body;
	sf::Window *i_win;
	Grid* grids;
	sf::Texture playerTex;
	sf::Sprite body;
	Animation* playerAnimation;
	float PlayerMovementSpeed;
	sf::Vector2f velocity;
	// Private Functions
	void SetClockTime();
	bool isRight;
	sf::FloatRect playerNextMove;
public:
	Player(float GridSize, sf::Window& window);
	void MovePlayer(const float& DT);
	void CheckCollision(float location_x, float location_y);
	void Draw(sf::RenderWindow& i_window);
	sf::FloatRect SetHitBox();

	~Player();
};

