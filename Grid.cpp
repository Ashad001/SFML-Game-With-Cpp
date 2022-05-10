#include "Grid.h"

Grid::Grid()
{
	this->GridSize = 32;
	this->MapSize = 20;
	this->tileNumber_X = 0;
	this->tileNumber_Y = 0;
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
			Tiles[i + j * MapSize].setOutlineColor(sf::Color::Blue);
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

Grid::~Grid()
{
	delete Map;
}

