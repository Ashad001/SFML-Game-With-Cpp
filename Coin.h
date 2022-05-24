#pragma once
#include "Grid.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace std;

class Coin
{
	sf::Window* e_win;
	Grid* grids;
	//sf::RectangleShape Body;
	sf::Texture *CoinTex;
	sf::Sprite body;
	int counter;
	Animation* coin_animation;

	// Private Functions
public:
	Coin(sf::Window& window, sf::Vector2f Pos);
	void CheckCollision(Player &player, float location_x, float location_y);
	void Draw(sf::RenderWindow& i_window);
	sf::Vector2f GetPlacement();
	void UpdateCoin(float DT);
	sf::FloatRect SetHitBox();
	void SetPosition(sf::Vector2f Pos);
	~Coin();

};