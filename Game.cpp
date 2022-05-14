#include "Game.h"

void Game::SetWindow()
{
	this->Window = new sf::RenderWindow(sf::VideoMode(800, 640), "OOP-PROJECT");
	this->Window->setFramerateLimit(120);
}	
Game::Game()
{
	SetWindow();
	grids = new Grid;
	grids->SetGrids();
	player = new Player(this->grids->GetGridSize(), *Window);
}

Game::~Game()
{
	delete this->Window;
	delete this->grids;
	delete this->player;
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
	//UpdateDT();
	this->player->MovePlayer(this->DeltaTime);
}

void Game::Render()
{
	this->Window->clear(sf::Color::Black);
	// Render / Drawing
	this->grids->DrawGrids(*Window);
	this->player->Draw(*Window);
	this->Window->display();
}

void Game::Run()
{
	while (this->Window->isOpen())
	{
		this->UpdateDT();
		this->Update();
		this->Render();


	}
}
