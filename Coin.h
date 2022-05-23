#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "Player.h"
using namespace std;

class Coin :public Entity
{
	//sf::RectangleShape Body;
	sf::Texture CoinTex;
	sf::Sprite body;
	int counter;
	// Private Functions
public:
	Coin(float GridSize, sf::Window& window, int level);
	void CheckCollision(Player &player, float location_x, float location_y);
	void Draw(sf::RenderWindow& i_window);
	sf::Vector2f GetPlacement();
	sf::FloatRect SetHitBox();
	~Coin();

};