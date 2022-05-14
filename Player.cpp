#include "Player.h"

void Player::SetClockTime()
{
	sf::Time t = sf::milliseconds(100);
	sf::Clock c;
	while (c.getElapsedTime().asSeconds() < t.asSeconds() * 2)
	{

	}
}

Player::Player(float GridSize, sf::Window& window)  
{
	this->i_win = &window;
	grids = new Grid;
	playerTex.loadFromFile("Textures/Ghost2.png");
	playerTex.setSmooth(true);
	this->body.setTexture(this->playerTex);
	this->body.setScale(0.45f, 0.45f);
	this->playerAnimation = new Animation(&playerTex, sf::Vector2u(7, 2), 0.4);
	isRight = true;
	this->velocity = { 0.f, 0.f };
	this->PlayerMovementSpeed = 200.f;
	this->grids->SetGrids();
}

void Player::MovePlayer(const float& DT)
{
	
	body.setTextureRect(playerAnimation->uvRect);
	velocity = { 0.f , 0.f };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		velocity.y += -this->PlayerMovementSpeed * DT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		velocity.y += this->PlayerMovementSpeed * DT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		isRight = true;
		playerAnimation->Update(1, DT, isRight);
		velocity.x += this->PlayerMovementSpeed * DT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
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
	if (body.getPosition().x + body.getGlobalBounds().width > 640)
		body.setPosition(640 - body.getGlobalBounds().width, body.getPosition().y);
	if (body.getPosition().y + body.getGlobalBounds().height > 640)
		body.setPosition(body.getPosition().x, 640 - body.getGlobalBounds().height);
	
	sf::FloatRect TileBounds = this->grids->Tiles[9].getGlobalBounds();
//	cout << TileBounds.left << " " << grids->Tiles[9].getGlobalBounds().height << " " << TileBounds.top << " " << TileBounds.width << endl;
}

void Player::CheckCollision(float location_x,float location_y)
{
	int index = 0;
	int index_x = ceil(location_x / grids->GetGridSize());
	int index_y = ceil(location_y / grids->GetGridSize());
	for (int i = 0; i < grids->GetMapSize() * grids->GetMapSize(); i++)
	{
		//cout << index << endl;

		if(grids->LEVEL1[i] == 1)
		{
			sf::FloatRect TileBounds = this->grids->Tiles[i].getGlobalBounds();
			sf::FloatRect PlayerBounds = body.getGlobalBounds();
			//cout << playerNextMove.height << " " << playerNextMove.top << endl;
			//cout << PlayerBounds.left << " " << PlayerBounds.width << endl;
			if (TileBounds.intersects(playerNextMove))
			{
				//cout << (grids->CheckCollision(playerNextMove.left, playerNextMove.top));
				// Bottom Collsion
				if (PlayerBounds.top < TileBounds.top && PlayerBounds.top + PlayerBounds.height < TileBounds.top + TileBounds.height && PlayerBounds.left < TileBounds.left + TileBounds.width && PlayerBounds.left + PlayerBounds.width > TileBounds.left)
				{
					index_x = ceil(location_x / grids->GetGridSize());
					index_y = floor(location_y / grids->GetGridSize());
					velocity.y = 0.f;
					body.setPosition(PlayerBounds.left, TileBounds.top - PlayerBounds.height);
				}
				 //Top Collision
				else if (PlayerBounds.top > TileBounds.top && PlayerBounds.top + PlayerBounds.height > TileBounds.top + TileBounds.height && PlayerBounds.left < TileBounds.left + TileBounds.width && PlayerBounds.left + PlayerBounds.width > TileBounds.left)
				{
					index_x = floor(location_x / grids->GetGridSize());
					index_y = ceil(location_y / grids->GetGridSize());
					velocity.y = 0.f;
					body.setPosition(PlayerBounds.left,  TileBounds.top + TileBounds.height);
				}
				// Right Collision
				if (PlayerBounds.left < TileBounds.left && PlayerBounds.left + PlayerBounds.width < TileBounds.left + TileBounds.width && PlayerBounds.top < TileBounds.top + TileBounds.height && PlayerBounds.top + PlayerBounds.height > TileBounds.top)
				{
					index_x = ceil(location_x / grids->GetGridSize());
					index_y = ceil(location_y / grids->GetGridSize());
					velocity.x = 0.f;
					body.setPosition(TileBounds.left - PlayerBounds.width, PlayerBounds.top);
				}
				// Left Collision
				else if (PlayerBounds.left > TileBounds.left && PlayerBounds.left + PlayerBounds.width > TileBounds.left + TileBounds.width && PlayerBounds.top < TileBounds.top + TileBounds.height && PlayerBounds.top + PlayerBounds.height > TileBounds.top)
				{
					index_x = floor(location_x / grids->GetGridSize());
					index_y = floor(location_y / grids->GetGridSize());
					velocity.x = 0.f;
					cout << PlayerBounds.left << " " << PlayerBounds.width << " " << PlayerBounds.top << " " << PlayerBounds.height << TileBounds.left << " " << TileBounds.width << " " << TileBounds.top << " " << TileBounds.height << endl;
					body.setPosition(TileBounds.width + TileBounds.left, PlayerBounds.top);
				}
			}
			index = index_x + (index_y * this->grids->GetMapSize());
		}
		
	}
}

void Player::Draw(sf::RenderWindow& i_window)
{
	i_window.draw(body);
}

sf::FloatRect Player::SetHitBox()
{
	return sf::FloatRect(body.getGlobalBounds().left , body.getGlobalBounds().top  , grids->GridSize, grids->GridSize);
}


Player::~Player()
{
	delete grids;
}
