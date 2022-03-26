#include <SFML/Graphics.hpp>
#include "Grid.h"
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "OOP-PROJECT");

	float GridSize = 50.f;
	Grid grids(GridSize);
	grids.SetGrids();

	
	while (window.isOpen())
	{
		grids.SelectGridTile(window);
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
		grids.DrawGrids(window);
		window.display();


	}
}