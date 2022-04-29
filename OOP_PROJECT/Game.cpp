#include "Game.h"

void Game::SetWindow()
{
	this->Window = new sf::RenderWindow(sf::VideoMode(750, 750), "OOP-PROJECT");
}

void Game::SetStates()
{
	this->states.push(new GameState(Window));
}

Game::Game()
{
	SetWindow();
	SetStates();
}

Game::~Game()
{
	delete this->Window;

	while (!this->states.empty())
	{
		delete this->states.top();  // DELETE THE DATA
		this->states.pop();         // DELETE THE POINTER.. Memory Freed.. OPTIMIZATION!!!!!
	}
}

void Game::EndGame()
{
	cout << "End" << endl;
}

void Game::UpdateEvents()
{
	while (this->Window->pollEvent(this->EVNT))
	{
		if (this->EVNT.type == sf::Event::Closed)
		{
			this->Window->close();
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

	if (!this->states.empty())
	{
		this->states.top()->Update(this->DeltaTime);
		if (this->states.top()->GetQuit())
		{
			this->states.top()->EndState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else // Close the game COMPLETELY
	{
		this->EndGame();
		this->Window->close();
	}
}

void Game::Render()
{
	this->Window->clear(sf::Color::Black);

	// Render / Drawing

	if (!this->states.empty())
	{
		this->states.top()->Render(this->Window);
	}



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
