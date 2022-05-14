#include "Grid.h"

Grid::Grid()
{
	this->GridSize = 32;
	this->MapSize = 20;
	this->tileNumber_X = 0;
	this->tileNumber_Y = 0;
	this->Location = 0;
	//Tile
	Map = new TileMap;
	Map->load("Block.png", sf::Vector2u(32, 32), LEVEL1, 20, 20);
}


void Grid::SetGrids()
{
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++)
		{
			Tiles[i + j * MapSize].setPosition(i * GridSize, j * GridSize);
			Tiles[i + j * MapSize].setSize(sf::Vector2f(GridSize, GridSize));
			Tiles[i + j * MapSize].setFillColor(sf::Color::Transparent);
			Tiles[i + j * MapSize].setOutlineThickness(1.f);
			Tiles[i + j * MapSize].setOutlineColor(sf::Color::Green);
		//	cout << Tiles[i + j * MapSize].getGlobalBounds().left << " " << Tiles[i + j * MapSize].getGlobalBounds().top << " " << Tiles[i + j * MapSize].getGlobalBounds().width << " " << Tiles[i + j * MapSize].getGlobalBounds().height << endl;
		}
	}
}



void Grid::DrawGrids(sf::RenderWindow& i_window)
{
	i_window.draw(*Map);
	for (int i = 0; i < MapSize * MapSize; i++)
	{
		i_window.draw(Tiles[i]);
	}
}


const float& Grid::GetGridSize() const
{
	return GridSize;
}

const int& Grid::GetMapSize() const
{
	return MapSize;
}


int Grid::CheckCollision(float location_x, float location_y)
{
//	cout << Tiles->getGlobalBounds().height << " " << Tiles->getGlobalBounds().left << endl;
	int index_x = floor(location_x / GridSize);
	int index_y = floor(location_y / GridSize);
	//cout << index_x << "   " << index_y << "  " << index_x + (index_y * this->MapSize) + 1  << endl;
	if (LEVEL1[index_x + (index_y * this->MapSize)] == 1)
	{
		return index_x + (index_y * this->MapSize);
	}
	return 0;

	
}



Grid::~Grid()
{
	delete Map;
}

