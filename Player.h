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
	sf::Window* i_win;
	sf::Texture playerTex;
	sf::Sprite body;
	bool IsDead;
	Animation* playerAnimation;
	float PlayerMovementSpeed;
	sf::Vector2f velocity;
	// Private Functions
	void SetClockTime();
	bool isRight;
	int PlayerGridIndex;
	sf::FloatRect playerNextMove;
	int CurrentLevel;
	int index;
public:
	Player(float GridSize, sf::Window& window);
	void MovePlayer(const float& DT);
	void CheckCollision(float location_x, float location_y);
	void Draw(sf::RenderWindow& i_window);
	sf::Vector2f GetPlayerPosition();
	sf::FloatRect SetHitBox();
	void SetView(sf::View* view);
	void SetPlayerGridPosition(int index);
	const int &GetPlayerGridPosition() const;
	void SetPlayerCurrentLevel(int lev);
	void SetPlayerPosition(sf::Vector2f pos);
	const int &GetPlayerCurrentLevel() const;



	~Player();
};