#include "Game.h"

void Game::SetWindow()
{
	this->Window = new sf::RenderWindow(sf::VideoMode(800, 640), "OOP-PROJECT");
	this->Camera = new sf::View(sf::Vector2f(0, 0), sf::Vector2f(600, 480)); // This is centre and size of the camera but will be updated later
	this->Window->setFramerateLimit(120);
}
Game::Game()
{
	this->LEVEL = 1;
	SetWindow();
	grids = new Grid;
	grids->SetGrids();
	SetEntites();
	grids->SelectLevel(LEVEL,1);
}

Game::~Game()
{
	delete this->Window;
	delete this->grids;
	delete this->player;
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies.pop_back();
	}
}

void Game::SetEntites()
{
	player = new Player(this->grids->GetGridSize(), *Window);
	
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (grids->levels.levelarr[i + j * 20] == 4)
			{
				Enemy* tempenm = new Enemy(grids->GetGridSize(), *Window, sf::Vector2f(i * grids->GetGridSize(), j * grids->GetGridSize()));
				enemies.push_back(*tempenm);
			}
		}
	}
}

void Game::UpdateEvents()
{
	while (this->Window->pollEvent(this->EVNT))
	{
		if (this->EVNT.type == sf::Event::Closed)
		{
			this->Window->close();
		}
		if (this->EVNT.type == sf::Event::Resized)
		{
			// resize my view
			sf::View view = Window->getDefaultView();
			view.setSize({
					static_cast<float>(EVNT.size.width),
					static_cast<float>(EVNT.size.height)
				});
			Window->setView(view);
		}
	}
}

void Game::UpdateDT()
{
	this->DeltaTime = DTClock.restart().asSeconds();
}

void Game::Update()
{
	UpdateEvents();
	int preLevel = player->GetPlayerCurrentLevel();
	this->player->MovePlayer(this->DeltaTime);
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].UpdateEnemy(this->DeltaTime);
	}
	cout << grids->levels.levelarr[player->GetPlayerGridPosition()] << endl;
	if (preLevel != player->GetPlayerCurrentLevel())
	{
		grids->SelectLevel(player->GetPlayerCurrentLevel(), 1);
	}
}

void Game::Render()
{
	this->Window->clear(sf::Color::Black);
	// Render / Drawing
	this->grids->DrawGrids(*Window);
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].Draw(*Window);
	}
	this->player->Draw(*Window);
	this->Window->display();
}

void Game::Run()
{
	while (this->Window->isOpen())
	{
		this->UpdateDT();
		this->Update();
		this->Camera->setCenter(player->GetPlayerPosition());
		this->player->SetView(Camera);
		//	this->Camera->setSize(Window->getSize().x, Window->getSize().y);
		this->Window->setView(*Camera);
		this->Render();


	}
}