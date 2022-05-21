#pragma once

#include "Grid.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Entity.h"
class Player : public Entity
{
private:
	//sf::RectangleShape Body;
	sf::Window *i_win;
	sf::Texture playerTex;
	sf::Sprite body;
	bool IsDead;
	Animation* playerAnimation;
	float PlayerMovementSpeed;
	sf::Vector2f velocity;
	// Private Functions
	void SetClockTime();
	bool isRight;
	sf::FloatRect playerNextMove;
public:
	Player(float GridSize, sf::Window& window, int level);
	void MovePlayer(const float& DT);
	void CheckCollision(float location_x, float location_y);
	void Draw(sf::RenderWindow& i_window);
	sf::Vector2f GetPlayerPosition();
	sf::FloatRect SetHitBox();
	void SetView(sf::View* view);

	~Player();
};

