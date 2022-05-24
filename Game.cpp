#include "Game.h"

void Game::SetWindow()
{
	this->Window = new sf::RenderWindow(sf::VideoMode(800, 640), "OOP-PROJECT");
	this->Camera = new sf::View(sf::Vector2f(0, 0), sf::Vector2f(400, 320)); // This is centre and size of the camera but will be updated later
	this->Window->setFramerateLimit(120);
}
Game::Game() 
{
	this->LEVEL = 1;
	SetWindow();
	grids = new Grid;
	grids->SetGrids();
	grids->SelectLevel(LEVEL,1);
	this->CoinsCollected = 0;
	if (!font.loadFromFile("MenuFont.ttf"))
	{
		cout << "Font Not Avalaible..!";
	}
	
	if (!CoinBuffer.loadFromFile("CoinSound.wav"))
	{
		cout << "Sound Not Loaded" << endl;
	}
	if (!Intro.openFromFile("Background.ogg"));
	{
		cout << "Music Not Loaded" << endl;
	}
	CoinSound.setBuffer(CoinBuffer);

	Intro.play();
	Intro.setLoop(1);

	if (!EnemyKill.loadFromFile("EnemyKill.wav"))
	{
		cout << "Enemy Sound Not Loaded" << endl;
	}
	EnemySound.setBuffer(EnemyKill);

	SetEntites(1);
}

Game::~Game()
{
	delete this->Window;
	delete this->grids;
	delete this->player;
	DeleteEntities();
}

void Game::SetEntites(bool PlayerGenerate)
{
	if(PlayerGenerate)
		player = new Player(this->grids->GetGridSize(), *Window);
		
	tempenm = new Enemy(grids->GetGridSize(), *Window, sf::Vector2f(0.f, 0.f));
	tempCoin = new Coin(*Window, sf::Vector2f(0.f, 0.f));
	this->player->IsDead = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (grids->levels.levelarr[i + j * 20] == 4)
			{
				tempenm->SetPosition(i * grids->GetGridSize(), j * grids->GetGridSize());
				enemies.push_back(std::make_shared <Enemy>(*tempenm));
			}
			else if (grids->levels.levelarr[i + j * 20] == 5)
			{
				tempCoin->SetPosition(sf::Vector2f(i * grids->GetGridSize(), j * grids->GetGridSize()));
				coins.push_back(std::make_shared <Coin>(*tempCoin));
			}
		}

	}
	this->text.setFont(font);
	this->text.setFillColor(sf::Color::White);
	this->text.setString("Level" + to_string(player->GetPlayerCurrentLevel()));
	this->text.setCharacterSize(70);
	this->text.setLetterSpacing(14.f);
	this->text.setOutlineColor(sf::Color::Red);
	this->text.setPosition(100.f, 10.f);
}

void Game::UpdateEvents()
{
	while (this->Window->pollEvent(this->EVNT))
	{
		if (this->EVNT.type == sf::Event::Closed)
		{
			this->Window->close();
		}
		if (this->EVNT.type == sf::Event::Resized)
		{
			// resize my view
			sf::View view = Window->getDefaultView();
			view.setSize({
					static_cast<float>(EVNT.size.width),
					static_cast<float>(EVNT.size.height)
				});
			Window->setView(view);
		}
	}
}

void Game::UpdateDT()
{
	this->DeltaTime = DTClock.restart().asSeconds();
}

void Game::Update()
{
	UpdateEvents();

	int preLevel = player->GetPlayerCurrentLevel();
	this->player->MovePlayer(this->DeltaTime);
	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->UpdateEnemy(this->DeltaTime);
	}
	for (unsigned int i = 0; i < coins.size(); i++)
	{
		coins[i]->UpdateCoin(this->DeltaTime);
	}
	if (preLevel != player->GetPlayerCurrentLevel())
	{
		grids->SelectLevel(player->GetPlayerCurrentLevel(), 1);
		DeleteEntities();
		SetEntites(0);
	}
	for (unsigned short i = 0; i < enemies.size(); i++)
	{
		if (player->FireCollide == 1)
		{
			EnemySound.play();
			this->player->IsDead = 1;
			enemies.erase(enemies.begin() + i);
			break;
		}
	}
	for (unsigned short i = 0; i < coins.size(); i++)
	{
		if (player->OnCoin == true)
		{
			CoinSound.play();
			player->OnCoin = 0;
			CoinsCollected++;
			coins.erase(coins.begin() + i);
			break;
		}
	}

	
}

void Game::Render()
{
	this->Window->clear(sf::Color::Black);
	// Render / Drawing
	this->grids->DrawGrids(*Window);
	for (unsigned int i = 0; i < coins.size(); i++)
	{
		coins[i]->Draw(*this->Window);
	}
	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->Draw(*Window);
	}
	this->player->Draw(*Window);

	
}

void Game::Run()
{
	while (this->Window->isOpen())
	{
		this->UpdateDT();
		this->Update();
		this->Camera->setCenter(player->GetPlayerPosition());
		this->player->SetView(Camera);
		this->Camera->setSize(Window->getSize().x, Window->getSize().y);
		this->Window->setView(*Camera);
		this->Render();
		this->Window->getDefaultView();
		this->Window->draw(text);
		this->Window->display();

	}
}

void Game::DeleteEntities()
{
	
	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		enemies.erase(enemies.begin() + i);
	}
	for (unsigned int i = 0; i < coins.size(); i++)
	{
		coins.pop_back();
	}
	

}
