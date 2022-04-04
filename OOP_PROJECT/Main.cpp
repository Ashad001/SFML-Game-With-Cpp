#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Player.h"
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "OOP-PROJECT");

	float GridSize = 30.76f;
	Player player(GridSize);

	int move = 0;

	while (window.isOpen())
	{
		if (move < 70)
		{
			move++;
		}
		else
		{
			player.MovePlayer();
			move = 0;
		}
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				window.close();
			}
			if (evnt.type == sf::Event::Resized)
			{
				sf::FloatRect viewsize(0, 0, evnt.size.width, evnt.size.height);
				window.setView(sf::View(viewsize));
			}
		}

		window.clear(sf::Color::Black);
		player.Draw(&window);
		window.display();
	}
}