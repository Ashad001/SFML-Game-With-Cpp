#include "Enemy.h"
#include "Animation.h"

Enemy::Enemy(float GridSize, sf::Window& window, sf::Vector2f pos)
{
	this->e_win = &window;
	grids = new Grid;
	cout << "ENEMY" << endl;
	enemyTex = new sf::Texture;
	enemyTex->loadFromFile("Enemy2.png");

	this->grids->SetGrids(); //parameter chahye hoga
	
	this->body.setTexture(*enemyTex);
	this->body.setPosition(pos);
	this->body.setScale(0.55f, 0.55f);
	this->enemy_animation = new Animation(enemyTex, sf::Vector2u(3, 1), 0.3f);
	SetHitBox();
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
	return body.getGlobalBounds();
}


Enemy::~Enemy()
{
	delete grids;
}