#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(512, 512), "OOP_Project");
	Event evnt;

	while (window.isOpen())
	{
		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed)
			{
				window.close();
			}
		}

		window.display();

	}
}
