#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

class Button
{
private:
	int ButtonState; // 0 for idle, 1 for hover, 2 for press
	sf::RectangleShape BottonBody;

	sf::Color IdleColor;
	sf::Color HoverColor;
	sf::Color PressColor;

	sf::Font* font;
	sf::Text text;

public:
	Button(sf::Vector2f Position, sf::Vector2f Size, sf::Font* font, string Text, sf::Color IdleColor, sf::Color HoverColor, sf::Color PressColor);
	Button();
	~Button();

	void Check(sf::Vector2f MousePosition);
	void Draw(sf::RenderTarget* target);
	int GetButtonState();
};