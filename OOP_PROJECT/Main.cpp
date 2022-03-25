#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "OOP_Project");
	sf::Event evnt;

	while (window.isOpen())
	{
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.display();

	}
}