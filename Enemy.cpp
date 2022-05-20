#include "Enemy.h"

Enemy::Enemy(float GridSize, sf::Window& window)
{
	this->e_win = &window;
	//grids = new Grid;
	enemyTex.loadFromFile("Textures/Ghost2.png");
	enemyTex.setSmooth(true);
	this->body.setTexture(this->enemyTex);
	this->body.setScale(0.45f, 0.45f);
	//this->grids->SetGrids(); //parameter chahye hoga
}

void Enemy::Draw(sf::RenderWindow& e_window)
{
	e_window.draw(body);
}

sf::FloatRect Enemy::SetHitBox()
{
	return sf::FloatRect(body.getGlobalBounds().left, body.getGlobalBounds().top, grids->GridSize, grids->GridSize);
}


Enemy::~Enemy()
{
	//delete grids;
}
