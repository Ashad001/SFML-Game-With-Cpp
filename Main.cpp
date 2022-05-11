#include <SFML/Graphics.hpp>
#include "MainMenu.h"

using namespace std;

int main() {
	sf::RenderWindow MENU(sf::VideoMode(800, 600), "Main Menu",sf::Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	while (MENU.isOpen())
	{
		sf::Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type==sf::Event::Closed)
			{
				MENU.close();
			}
			if (event.type==sf::Event::KeyReleased||event.type==sf::Event::MouseButtonPressed)
			{
				if (event.key.code==sf::Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code==sf::Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code==sf::Keyboard::Return)
				{
					int x = mainMenu.MainMenuPressed();
					if (x==0)
					{
					sf::RenderWindow Play(sf::VideoMode(800, 600), "Amazer");
						while (Play.isOpen())
						{
							MENU.close(); 
							sf::Event pevent;
							while (Play.pollEvent(pevent)) {
								if (pevent.type==sf::Event::Closed)
								{
									Play.close();
								}
								if (pevent.type==sf::Event::KeyPressed)
								{
									if (pevent.key.code==sf::Keyboard::Escape) {
										MENU.create(sf::VideoMode(800, 600), "Main Menu", sf::Style::Default);
										Play.close();
									}
								}
							}
							Play.clear();
							Play.display();
						}
					}
					if (x == 1)
					{
					sf::RenderWindow Options(sf::VideoMode(800, 600), "Options");
						while (Options.isOpen())
						{
							MENU.close();
							sf::Event pevent;
							while (Options.pollEvent(pevent)) {
								if (pevent.type == sf::Event::Closed)
								{
									Options.close();
								}
								if (pevent.type == sf::Event::KeyPressed)
								{
									if (pevent.key.code == sf::Keyboard::Escape) {
										MENU.create(sf::VideoMode(800, 600), "Main Menu", sf::Style::Default);
										Options.close();
									}
								}
							}
							Options.clear();
							Options.display();
						}
					}
					if (x == 2)
					{
					sf::RenderWindow About(sf::VideoMode(800, 600), "About");
						while (About.isOpen())
						{
							MENU.close();
							sf::Event pevent;
							while (About.pollEvent(pevent)) {
								if (pevent.type == sf::Event::Closed)
								{
									About.close();
								}
								if (pevent.type == sf::Event::KeyPressed)
								{
									if (pevent.key.code == sf::Keyboard::Escape) {
										MENU.create(sf::VideoMode(800, 600), "Main Menu", sf::Style::Default);
										About.close();
									}
								}
							}
							About.clear();
							About.display();
						}
					}
					if (x == 3)
					{
						MENU.close();
					}
				}
			}
		}
		MENU.clear();
		mainMenu.draw(MENU);
		MENU.display();
	}

	return 0;
}