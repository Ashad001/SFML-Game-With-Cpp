#include "Player.h"

Player::Player(float GridSize)
{
	grids = new Grid;
	this->Body.setFillColor(sf::Color::White);
	this->Body.setOutlineColor(sf::Color::Red);
	this->Body.setOutlineThickness(1.f);
	this->Body.setSize(sf::Vector2f(grids->GetGridSize(), grids->GetGridSize()));


}

void Player::MovePlayer(const float DT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->grids->tileNumber_Y--;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->grids->tileNumber_Y++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->grids->tileNumber_X++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->grids->tileNumber_X--;
	}
	if (this->grids->tileNumber_X < 0)
	{
		this->grids->tileNumber_X = 0;
	}
	else if (this->grids->tileNumber_X > this->grids->GetMapSize() - 1)
	{
		this->grids->tileNumber_X = this->grids->GetMapSize() - 1;
	}
	if (this->grids->tileNumber_Y < 0)
	{
		this->grids->tileNumber_Y = 0;
	}
	else if (this->grids->tileNumber_Y > this->grids->GetMapSize() - 1)
	{
		this->grids->tileNumber_Y = this->grids->GetMapSize() - 1;
	}
	Body.setPosition(this->grids->tileNumber_X * grids->GetGridSize(), this->grids->tileNumber_Y * grids->GetGridSize());
	//Body.move(this->grids->tileNumber_X * DT, this->grids->tileNumber_Y * DT);

}

void Player::Draw(sf::RenderWindow& i_window)
{
	i_window.draw(Body);
}

Player::~Player()
{
	delete grids;
}
