#include "Player.h"

void Player::SetClockTime()
{
	sf::Time t = sf::milliseconds(100);
	sf::Clock c;
	while (c.getElapsedTime().asSeconds() < t.asSeconds() * 2)
	{

	}
}

Player::Player(float GridSize, sf::Window& window) : Entity(window)
{
	this->CurrentLevel = 1;
	playerTex.loadFromFile("Textures/Ghost2.png");
	playerTex.setSmooth(true);
	this->body.setTexture(this->playerTex);
	this->body.setScale(0.305f, 0.305f);
	this->playerAnimation = new Animation(&playerTex, sf::Vector2u(7, 2), 0.3);
	isRight = true;
	this->velocity = { 0.f, 0.f };
	this->PlayerMovementSpeed = 200.f;
	this->IsDead = true;
	this->body.setOrigin(body.getGlobalBounds().width / 2, body.getGlobalBounds().height / 2);
	this->grids->SelectLevel(CurrentLevel, 0);
	this->PlayerGridIndex = 0;
	SetPlayerCurrentLevel(1);
	body.setPosition(20.f, 45.f);
	FireCollide = 0;
	this->OnCoin = 0;

}

void Player::MovePlayer(const float& DT)
{

	body.setTextureRect(playerAnimation->uvRect);
	velocity = { 0.f , 0.f };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		playerAnimation->Update(0, DT, isRight);
		velocity.y += -this->PlayerMovementSpeed * DT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerAnimation->Update(0, DT, isRight);
		velocity.y += this->PlayerMovementSpeed * DT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		isRight = true;
		playerAnimation->Update(1, DT, isRight);
		velocity.x += this->PlayerMovementSpeed * DT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		isRight = false;
		playerAnimation->Update(1, DT, isRight);
		velocity.x += -this->PlayerMovementSpeed * DT;
	}
	else
	{
		playerAnimation->Update(0, DT, isRight);
	}


	//cout << body.getPosition().x << " " << body.getPosition().y << " " <<  i_win->getSize().x << endl;

	sf::FloatRect PlayerBounds = body.getGlobalBounds();

	playerNextMove = PlayerBounds;
	playerNextMove.left += velocity.x;
	playerNextMove.top += velocity.y;

	Player::CheckCollision(playerNextMove.left, playerNextMove.top);

	body.move(velocity);

	if (body.getPosition().x < 0)
		body.setPosition(0.f, body.getPosition().y);
	if (body.getPosition().y < 0)
		body.setPosition(body.getPosition().x, 0.f);
	if (body.getPosition().x + body.getGlobalBounds().width > 670)
		body.setPosition(670 - body.getGlobalBounds().width, body.getPosition().y);
	if (body.getPosition().y + body.getGlobalBounds().height > 670)
		body.setPosition(body.getPosition().x, 670 - body.getGlobalBounds().height);

	sf::FloatRect TileBounds = this->grids->Tiles[9].getGlobalBounds();
	//	cout << TileBounds.left << " " << grids->Tiles[9].getGlobalBounds().height << " " << TileBounds.top << " " << TileBounds.width << endl;
}

void Player::CheckCollision(float location_x, float location_y)
{
	SetPlayerCurrentLevel(CurrentLevel);
	int index_x = ceil(location_x / grids->GetGridSize());
	int index_y = ceil(location_y / grids->GetGridSize());
	if (index == 220 || index == 380)   // Exit Points...!
	{
		CurrentLevel++;
		SetPlayerCurrentLevel(CurrentLevel);
		grids->SelectLevel(CurrentLevel, 1);
		body.setPosition(sf::Vector2f(0.f, 50.f));
		index = 0;
		velocity.x = 0.f;
		velocity.y = 0.f;
		return;
	}
	for (int i = 0; i < grids->GetMapSize() * grids->GetMapSize(); i++)
	{

		
		sf::FloatRect PlayerBounds = this->SetHitBox();
		sf::FloatRect TileBounds = this->grids->Tiles[i].getGlobalBounds();
		if (grids->levels.levelarr[i] == 1)
		{
			body.setColor(sf::Color::White);
			if (TileBounds.intersects(playerNextMove))
			{
				FireCollide = 0;

				// Bottom Collsion
				if (PlayerBounds.top < TileBounds.top && PlayerBounds.top + PlayerBounds.height < TileBounds.top + TileBounds.height && PlayerBounds.left < TileBounds.left + TileBounds.width && PlayerBounds.left + PlayerBounds.width > TileBounds.left)
				{
					index_x = ceil(location_x / grids->GetGridSize());
					index_y = floor(location_y / grids->GetGridSize());
					velocity.y = 0.f;
				}
				//Top Collision
				else if (PlayerBounds.top > TileBounds.top && PlayerBounds.top + PlayerBounds.height > TileBounds.top + TileBounds.height && PlayerBounds.left < TileBounds.left + TileBounds.width && PlayerBounds.left + PlayerBounds.width > TileBounds.left)
				{
					index_x = floor(location_x / grids->GetGridSize());
					index_y = ceil(location_y / grids->GetGridSize());
					velocity.y = 0.f;
					//.setPosition(PlayerBounds.left,  TileBounds.top + TileBounds.height);
				}
				// Right Collision
				if (PlayerBounds.left < TileBounds.left && PlayerBounds.left + PlayerBounds.width < TileBounds.left + TileBounds.width && PlayerBounds.top < TileBounds.top + TileBounds.height && PlayerBounds.top + PlayerBounds.height > TileBounds.top)
				{
					index_x = ceil(location_x / grids->GetGridSize());
					index_y = ceil(location_y / grids->GetGridSize());
					velocity.x = 0.f;
					//body.setPosition(TileBounds.left - PlayerBounds.width, PlayerBounds.top);
				}
				// Left Collision
				else if (PlayerBounds.left > TileBounds.left && PlayerBounds.left + PlayerBounds.width > TileBounds.left + TileBounds.width && PlayerBounds.top < TileBounds.top + TileBounds.height && PlayerBounds.top + PlayerBounds.height > TileBounds.top)
				{
					index_x = floor(location_x / grids->GetGridSize());
					index_y = floor(location_y / grids->GetGridSize());
					velocity.x = 0.f;
				}
			}
			index = index_x + (index_y * this->grids->GetMapSize());
			SetPlayerGridPosition(index);
		}
		else if (grids->levels.levelarr[i] == 4 && !IsDead)
		{
			if (TileBounds.intersects(playerNextMove))
			{
				if (PlayerBounds.top < TileBounds.top && PlayerBounds.top + PlayerBounds.height < TileBounds.top + TileBounds.height && PlayerBounds.left < TileBounds.left + TileBounds.width && PlayerBounds.left + PlayerBounds.width > TileBounds.left)
				{
					index_x = ceil(location_x / grids->GetGridSize());
					index_y = floor(location_y / grids->GetGridSize());
					body.setPosition(20.f, 45.f);
					FireCollide = 1;
				}
				//Top Collision
				else if (PlayerBounds.top > TileBounds.top && PlayerBounds.top + PlayerBounds.height > TileBounds.top + TileBounds.height && PlayerBounds.left < TileBounds.left + TileBounds.width && PlayerBounds.left + PlayerBounds.width > TileBounds.left)
				{
					index_x = floor(location_x / grids->GetGridSize());
					index_y = ceil(location_y / grids->GetGridSize());
					body.setPosition(20.f, 45.f);
					FireCollide = 1;
				}
				// Right Collision
				if (PlayerBounds.left < TileBounds.left && PlayerBounds.left + PlayerBounds.width < TileBounds.left + TileBounds.width && PlayerBounds.top < TileBounds.top + TileBounds.height && PlayerBounds.top + PlayerBounds.height > TileBounds.top)
				{
					index_x = ceil(location_x / grids->GetGridSize());
					index_y = ceil(location_y / grids->GetGridSize());
					body.setPosition(20.f, 45.f);
					FireCollide = 1;
					
				}
				// Left Collision
				else if (PlayerBounds.left > TileBounds.left && PlayerBounds.left + PlayerBounds.width > TileBounds.left + TileBounds.width && PlayerBounds.top < TileBounds.top + TileBounds.height && PlayerBounds.top + PlayerBounds.height > TileBounds.top)
				{
					index_x = floor(location_x / grids->GetGridSize());
					index_y = floor(location_y / grids->GetGridSize());
					FireCollide = 1;
					body.setPosition(20.f, 45.f);
				}
				
			}
		}
		else if (grids->levels.levelarr[i] == 2)
		{
			if (TileBounds.intersects(playerNextMove))
			{
				FireCollide = 0;

				if (PlayerBounds.top < TileBounds.top && PlayerBounds.top + PlayerBounds.height < TileBounds.top + TileBounds.height && PlayerBounds.left < TileBounds.left + TileBounds.width && PlayerBounds.left + PlayerBounds.width > TileBounds.left)
				{
					index_x = ceil(location_x / grids->GetGridSize());
					index_y = floor(location_y / grids->GetGridSize());
					velocity.y = 0.f;
					body.setPosition(20.f, 45.f);
				}
				//Top Collision
				else if (PlayerBounds.top > TileBounds.top && PlayerBounds.top + PlayerBounds.height > TileBounds.top + TileBounds.height && PlayerBounds.left < TileBounds.left + TileBounds.width && PlayerBounds.left + PlayerBounds.width > TileBounds.left)
				{
					index_x = floor(location_x / grids->GetGridSize());
					index_y = ceil(location_y / grids->GetGridSize());
					velocity.y = 0.f;
					body.setPosition(20.f, 45.f);
				}
				// Right Collision
				if (PlayerBounds.left < TileBounds.left && PlayerBounds.left + PlayerBounds.width < TileBounds.left + TileBounds.width && PlayerBounds.top < TileBounds.top + TileBounds.height && PlayerBounds.top + PlayerBounds.height > TileBounds.top)
				{
					index_x = ceil(location_x / grids->GetGridSize());
					index_y = ceil(location_y / grids->GetGridSize());
					velocity.x = 0.f;
					body.setPosition(20.f, 45.f);
				}
				// Left Collision
				else if (PlayerBounds.left > TileBounds.left && PlayerBounds.left + PlayerBounds.width > TileBounds.left + TileBounds.width && PlayerBounds.top < TileBounds.top + TileBounds.height && PlayerBounds.top + PlayerBounds.height > TileBounds.top)
				{
					index_x = floor(location_x / grids->GetGridSize());
					index_y = floor(location_y / grids->GetGridSize());
					velocity.x = 0.f;
					//cout << PlayerBounds.left << " " << PlayerBounds.width << " " << PlayerBounds.top << " " << PlayerBounds.height << TileBounds.left << " " << TileBounds.width << " " << TileBounds.top << " " << TileBounds.height << endl;
					body.setPosition(20.f, 45.f);
				}
			}
		}
		else if (grids->levels.levelarr[i] == 5)
		{
		OnCoin = 0;
			if (TileBounds.intersects(playerNextMove))
			{
				if (PlayerBounds.top < TileBounds.top && PlayerBounds.top + PlayerBounds.height < TileBounds.top + TileBounds.height && PlayerBounds.left < TileBounds.left + TileBounds.width && PlayerBounds.left + PlayerBounds.width > TileBounds.left)
				{
					OnCoin = 1;
					index_x = ceil(location_x / grids->GetGridSize());
					index_y = floor(location_y / grids->GetGridSize());

				}
				//Top Collision
				else if (PlayerBounds.top > TileBounds.top && PlayerBounds.top + PlayerBounds.height > TileBounds.top + TileBounds.height && PlayerBounds.left < TileBounds.left + TileBounds.width && PlayerBounds.left + PlayerBounds.width > TileBounds.left)
				{
					OnCoin = 1;
					index_x = floor(location_x / grids->GetGridSize());
					index_y = ceil(location_y / grids->GetGridSize());
				}
				// Right Collision
				if (PlayerBounds.left < TileBounds.left && PlayerBounds.left + PlayerBounds.width < TileBounds.left + TileBounds.width && PlayerBounds.top < TileBounds.top + TileBounds.height && PlayerBounds.top + PlayerBounds.height > TileBounds.top)
				{
					OnCoin = 1;
					index_x = ceil(location_x / grids->GetGridSize());
					index_y = ceil(location_y / grids->GetGridSize());

				}
				// Left Collision
				else if (PlayerBounds.left > TileBounds.left && PlayerBounds.left + PlayerBounds.width > TileBounds.left + TileBounds.width && PlayerBounds.top < TileBounds.top + TileBounds.height && PlayerBounds.top + PlayerBounds.height > TileBounds.top)
				{
					OnCoin = 1;
					index_x = floor(location_x / grids->GetGridSize());
					index_y = floor(location_y / grids->GetGridSize());
				}
			}

		}

	}
}

void Player::Draw(sf::RenderWindow& i_window)
{
	i_window.draw(body);
}

sf::Vector2f Player::GetPlayerPosition()
{
	return sf::Vector2f(body.getPosition());
}

sf::FloatRect Player::SetHitBox()
{
	return sf::FloatRect(body.getGlobalBounds().left, body.getGlobalBounds().top, body.getGlobalBounds().width , body.getGlobalBounds().height - 3);  // Compressing the globalbounds to be collision more effective
}

void Player::SetView(sf::View* view)
{
	if (body.getPosition().x < view->getCenter().x - view->getSize().x / 2.f && body.getPosition().x < grids->Tiles->getGlobalBounds().left)
	{
		body.setPosition(sf::Vector2f(view->getCenter().x - view->getSize().x / 2.f, body.getPosition().y));
	}
}

void Player::SetPlayerGridPosition(int index)
{
	PlayerGridIndex = index;
}

const int& Player::GetPlayerGridPosition() const
{
	// TODO: insert return statement here
	return PlayerGridIndex;
}

void Player::SetPlayerCurrentLevel(int lev)
{
	this->CurrentLevel = lev;
}

void Player::SetPlayerPosition(sf::Vector2f pos)
{
	this->body.setPosition(pos);
}



const int& Player::GetPlayerCurrentLevel() const
{
	return CurrentLevel;
	// TODO: insert return statement here
}

const sf::FloatRect& Player::GetPlayerGlobalBounds() const
{
	return body.getGlobalBounds();
	// TODO: insert return statement here
}


Player::~Player()
{
	delete grids;
}