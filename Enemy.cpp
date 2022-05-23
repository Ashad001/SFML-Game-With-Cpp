#include "Enemy.h"
#include "Animation.h"

Enemy::Enemy(float GridSize, sf::Window& window, sf::Vector2f pos)
{
	this->e_win = &window;
	grids = new Grid;
	enemyTex.loadFromFile("Textures/Enemy2.png");

	enemyTex.setSmooth(true);
	this->body.setTexture(this->enemyTex);
	this->body.setPosition(pos);
	this->body.setScale(0.5f, 0.5f);
	this->grids->SetGrids(); //parameter chahye hoga
	this->enemy_animation = new Animation(&enemyTex, sf::Vector2u(3, 1), 0.3f);
}

void Enemy::Draw(sf::RenderWindow& e_window)
{
	e_window.draw(body);
}

void Enemy::SetPosition(float x, float y)
{
	body.setPosition(sf::Vector2f(x, y));
}

void Enemy::UpdateEnemy(float DT)
{
	this->enemy_animation->Update(0, DT, 1);
	this->body.setTextureRect(enemy_animation->uvRect);
}


sf::FloatRect Enemy::SetHitBox()
{
	return sf::FloatRect(body.getGlobalBounds().left, body.getGlobalBounds().top, grids->GetGridSize(), grids->GetGridSize());
}


Enemy::~Enemy()
{
	delete grids;
}