#include "Coin.h"
Coin::Coin(float GridSize, sf::Window& window, int level) : Entity(window)
{
	CoinTex.loadFromFile("Coin.png");
	CoinTex.setSmooth(true);
	this->body.setTexture(this->CoinTex);
	this->counter = 0;
}

void Coin::CheckCollision(Player &player, float location_x, float location_y)
{
	int index = 0;
	int index_x = ceil(location_x / grids->GetGridSize());
	int index_y = ceil(location_y / grids->GetGridSize());
	for (int i = 0; i < grids->GetMapSize() * grids->GetMapSize(); i++)
	{
		if (GetPlacement() == player.GetPlayerPosition())
		{
			counter += 1;
		}
	}
}

void Coin::Draw(sf::RenderWindow& i_window)
{
	i_window.draw(body);
}

sf::FloatRect Coin::SetHitBox()
{
	return sf::FloatRect(body.getGlobalBounds().left, body.getGlobalBounds().top, body.getGlobalBounds().width - 5, body.getGlobalBounds().height - 3);  // Compressing the globalbounds to be collision more effective
}

sf::Vector2f Coin::GetPlacement() {
	return sf::Vector2f(body.getPosition());
}
Coin::~Coin()
{
	delete grids;
}