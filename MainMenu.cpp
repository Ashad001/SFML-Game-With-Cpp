#include "MainMenu.h"

MainMenu::MainMenu(float width, float height) {
	if (!font.loadFromFile("MenuFont.ttf"))
	{
		cout << "Font Not Avalaible..!";
	}

	//Play Button
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(330, 100);

	//Option Button
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(330, 200);

	//About Button
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("About");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(330, 300);

	//Exit Button
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(330, 400);

	MainMenuSelected = -1;
}

//Draw
void MainMenu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; ++i)
	{
		window.draw(mainMenu[i]);
	}
}

//MoveUp
void MainMenu::MoveUp() {
	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected--;

		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

//MoveDown

void MainMenu::MoveDown() {
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected++;

		if (MainMenuSelected == Max_main_menu)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

int MainMenu::MainMenuPressed()
{
	return MainMenuSelected;
}


void MainMenu::Update()
{
	sf::RenderWindow MENU(sf::VideoMode(800, 640), "Main Menu", sf::Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	sf::RectangleShape Background;
	Background.setSize(sf::Vector2f(800, 600));
	sf::Texture MainTexture;
	MainTexture.loadFromFile("ground.png");
	Background.setTexture(&MainTexture);
	int GameOn = 0;

	while (MENU.isOpen())
	{
		sf::Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				MENU.close();
			}
			if (event.type == sf::Event::KeyReleased || event.type == sf::Event::MouseMoved)
			{
				sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
				if (event.key.code == sf::Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						GameOn = 1;
						MENU.clear();
					}
					if (x == 1)
					{

					}
					if (x == 2)
					{
						
					}
					if (x == 3)
					{
						MENU.close();
					}
					
				}
			}
			if (GameOn == 1)
			{
				Game game;
				GameOn = 0;
				game.Run();
				if (event.key.code == sf::Keyboard::Escape) {
					MENU.clear();
					MENU.draw(Background);
					mainMenu.draw(MENU);
					MENU.display();
				}
			}
			MENU.clear();
			MENU.draw(Background);
			mainMenu.draw(MENU);
			MENU.display();
		}
	}
	

}


	