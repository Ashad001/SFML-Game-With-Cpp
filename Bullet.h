#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
private:
	sf::RectangleShape bullet;
	std::vector <Bullet> bulletVec;
	float size_x, size_y;
	float pos_x, pos_y;
	int speed;
public:
	Bullet();
	Bullet(float x, float y);
	void SetBulletSize(float x, float y);
	void SetBulletColor(sf::Color color);
	void SetBulletPosition(float x, float y);
	int getspeed(int speed);
	sf::Vector2f BulletPosition();
	void fire(int speed); //need to add radius
	void moving(int speed);
	int getright();
	int getleft();
	int gettop();
	int getbottom();
	void draw(sf::RenderWindow& window);
};