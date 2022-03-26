#include "Player.h"

Player::Player(float GridSize) : Grid(GridSize)
{
	this->Body.setFillColor(sf::Color::White);
	this->Body.setOutlineColor(sf::Color::Red);
	this->Body.setOutlineThickness(1.f);
	this->Body.setSize(sf::Vector2f(GetGridSize(), GetGridSize()));
	SetGrids();
}

void Player::MovePlayer()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		tileNumber_Y--;
	
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		tileNumber_Y++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		tileNumber_X++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		tileNumber_X--;
	}
	if (tileNumber_X < 0)
	{
		tileNumber_X = 0;
	}
	else if (tileNumber_X > MapSize - 1)
	{
		tileNumber_X = MapSize - 1;
	}
	if (tileNumber_Y < 0)
	{
		tileNumber_Y = 0;
	}
	else if (tileNumber_Y > MapSize - 2)
	{
		tileNumber_Y = MapSize - 2;
	}
	Body.setPosition(tileNumber_X * GetGridSize()  , tileNumber_Y * GetGridSize() );

}

void Player::Draw(sf::RenderWindow* i_window)
{
	i_window->draw(Body);
	DrawGrids(*i_window);
}

Player::~Player()
{

}
