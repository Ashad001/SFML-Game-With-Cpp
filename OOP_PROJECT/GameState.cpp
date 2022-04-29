#include "GameState.h"

GameState::GameState(sf::RenderWindow* Window) : State(Window)
{
}

GameState::~GameState()
{
}




void GameState::EndState()
{
	cout << "dsjf" << endl;
}

void GameState::UpdateKeyBinds(const float& DT)
{
	this->CheckQuit();
}

void GameState::Update(const float& DT)
{
	this->UpdateKeyBinds(DT);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		cout << "A" << endl;
	}
	//cout << "Rdf" << endl;
}

void GameState::Render(sf::RenderTarget* Target)
{

}
