#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(float gridSize)
{
	this->GridSize = gridSize;
	this->MapSize = 16;
	//Tile

	this->tileNumber_X = 0;
	this->tileNumber_Y = 0;
	SetGrids();


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
		}
	}
}


void Grid::DrawGrids(sf::RenderWindow& i_window)
{
	for (int i = 0; i < MapSize * MapSize; i++)
	{
		i_window.draw(Tiles[i]);
	}
}


float Grid::GetGridSize() const
{
	return GridSize;
}

Grid::~Grid()
{

}

