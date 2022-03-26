#pragma once

#include <SFML/Graphics.hpp>

class Player : sf::Transformable , sf::Drawable
{
private:
	sf::RectangleShape Body;
	sf::Vector2f BodySize;
	sf::Vector2f Velocity;


public:
	Player(sf::RenderWindow m_window, float DeltaTime);


};

