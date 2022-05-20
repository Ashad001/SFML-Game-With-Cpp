#include "Bullet.h"
Bullet::Bullet(float x,float y) {
	SetBulletSize(x, y);
}
void Bullet::fire(int speed) { //and in radius
	Bullet newBull(50, 5);
	//newBull.SetBulletPosition(); //player ki position
	bulletVec.push_back(newBull);
	newBull.moving(speed);
}
int Bullet::getright() {
	return bullet.getPosition().x + bullet.getSize().x;
}
int Bullet::getleft() {
	return bullet.getPosition().x;
}
int Bullet::gettop() {
	return bullet.getPosition().y;
}
int Bullet::getbottom() {
	return bullet.getPosition().y + bullet.getSize().y;
}
void Bullet::draw(sf::RenderWindow& window) {
	window.draw(bullet);
}

void Bullet::moving(int speed) {
	bullet.move(speed, 0);
}

void Bullet::SetBulletPosition(float x,float y) {
	this->pos_x=x;
	this->pos_y = y;
}

void Bullet::SetBulletColor(sf::Color color) {
	bullet.setFillColor(color);
}

void Bullet::SetBulletSize(float x=50.f, float y=5.f) {
	bullet.setSize(sf::Vector2f(x, y));
}

sf::Vector2f Bullet::BulletPosition() {
	return bullet.getPosition();
}