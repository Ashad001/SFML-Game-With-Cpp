#include "Coin.h"
Coin::Coin(sf::Window& window, sf::Vector2f Pos) 
{

	this->e_win = &window;
	grids = new Grid;
	CoinTex = new sf::Texture;
	CoinTex->loadFromFile("Coin.png");
	CoinTex->setSmooth(true);
	this->body.setTexture(*CoinTex);
	this->body.setPosition(Pos);
	grids->SetGrids();
	this->body.setScale(1.7f, 1.7f);
	this->coin_animation = new Animation(CoinTex, sf::Vector2u(8, 1), 0.3f);


	this->counter = 0;
}

void Coin::UpdateCoin(float DT)
{
	this->coin_animation->Update(0, DT, 1);
	this->body.setTextureRect(coin_animation->uvRect);
}

void Coin::CheckCollision(Player &player, float location_x, float location_y)
{
	int index = 0;
	int index_x = static_cast<int> (ceil(location_x / grids->GetGridSize()));
	int index_y = static_cast<int> (ceil(location_y / grids->GetGridSize()));
	for (int i = 0; i < grids->GetMapSize() * grids->GetMapSize(); i++)
	{
		if (SetHitBox().intersects(player.SetHitBox()))
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

void Coin::SetPosition(sf::Vector2f Pos)
{
	body.setPosition(Pos);
}

sf::Vector2f Coin::GetPlacement() {
	return sf::Vector2f(body.getPosition());
}
Coin::~Coin()
{
	delete grids;
	delete coin_animation;
	delete CoinTex;
}