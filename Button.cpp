#include "Button.h"


Button::Button(sf::Vector2f Position, sf::Vector2f Size, sf::Font* font, string Text, sf::Color IdleColor, sf::Color HoverColor, sf::Color PressColor)
{
	this->BottonBody.setPosition(Position);
	this->BottonBody.setSize(Size);
	this->BottonBody.setFillColor(sf::Color::White);
	// buttomState: 0 for idle, 1 for hover, 2 for press
	this->ButtonState = 0;

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setCharacterSize(20);
	this->text.setString(Text);
	this->IdleColor = IdleColor;
	this->HoverColor = HoverColor;
	this->PressColor = PressColor;
	this->text.setFillColor(IdleColor);
	this->BottonBody.setFillColor(this->IdleColor);

	this->text.setPosition(this->BottonBody.getPosition().x + (this->BottonBody.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f, this->BottonBody.getPosition().y + (this->BottonBody.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f);
}


Button::~Button()
{
	delete font;
}

void Button::Check()
{
	this->ButtonState = 0;
	//if (this->BottonBody.getGlobalBounds().contains(MousePosition))
	//{
	//	this->ButtonState = 1;
	//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//	{
	//		this->ButtonState = 2;
	//	}
	//}
	switch (this->ButtonState)
	{
	case 0:
		this->BottonBody.setFillColor(this->IdleColor);
	case 1:
		this->BottonBody.setFillColor(this->HoverColor);
	case 2:
		this->BottonBody.setFillColor(this->PressColor);

	default:
		break;
	}
}



void Button::Draw(sf::RenderWindow* target)
{
	target->draw(this->BottonBody);
}

int Button::GetButtonState()
{
	return this->ButtonState;          // Will return 2 if the button is pressed..!
}