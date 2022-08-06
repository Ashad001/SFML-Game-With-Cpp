#include "Cannon.h"
void Cannon::UpdateCannon(float DT)
{
	this->cannon_animation->Update(0, DT, 1);
	this->body.setTextureRect(cannon_animation->uvRect);
}



sf::FloatRect Cannon::SetHitBox()
{
	return sf::FloatRect(body.getGlobalBounds().left, body.getGlobalBounds().top, grids->GetGridSize(), grids->GetGridSize());
}
int Cannon::CheckRadius(int checkrad) {
	this->c_rad == checkrad;
	return c_rad;
	//check if player is within cannon radius and return boolean value, 1 if player is within shooting range
}
void Cannon::ShootCannon(int if_rad) {
	if (CheckRadius(c_rad) == 1) {
		Bullet shoot;
		this->speeed == shoot.getspeed(speeed);
		shoot.fire(speeed);
	}
}
Cannon::~Cannon()
{
	delete grids;
}