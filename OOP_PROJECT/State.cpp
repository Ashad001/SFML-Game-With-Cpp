#include "State.h"

State::State(sf::RenderWindow* Window)
{
	this->Window = Window;
	this->Quit = false;
}

State::~State()
{

}

const bool& State::GetQuit() const
{
	// TODO: insert return statement here
	return this->Quit;
}

void State::CheckQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->Quit = true;
	}
}
