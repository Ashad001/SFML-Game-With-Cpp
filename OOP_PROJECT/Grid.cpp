#include "Grid.h"

Grid::Grid(float gridSize)
{
	this->GridSize = gridSize;

	//Tile
	this->SelectTile.setFillColor(sf::Color::White);
	this->SelectTile.setOutlineColor(sf::Color::Red);
	this->SelectTile.setOutlineThickness(1.f);
	this->SelectTile.setSize(sf::Vector2f(GridSize, GridSize));
	SetGrids();

}

void Grid::SetGrids()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			Tiles[i + j * 16].setPosition(i * GridSize, j * GridSize);
			Tiles[i + j * 16].setSize(sf::Vector2f(GridSize, GridSize));
			Tiles[i + j * 16].setFillColor(sf::Color::Transparent);
			Tiles[i + j * 16].setOutlineThickness(1.f);
			Tiles[i + j * 16].setOutlineColor(sf::Color::Green);
		}
	}
}


void Grid::DrawGrids(sf::RenderWindow& i_window)
{
	i_window.draw(SelectTile);
	for (int i = 0; i < 16 * 16; i++)
	{
		i_window.draw(Tiles[i]);
	}
}

void Grid::SelectGridTile(sf::RenderWindow& i_window)
{
	MouseWindowPos = sf::Mouse::getPosition(i_window);
	if (MouseWindowPos.x >= 0.f)
		MouseGridPos.x = MouseWindowPos.x / (unsigned)GridSize;
	if (MouseWindowPos.y >= 0.f)
		MouseGridPos.y = MouseWindowPos.y / (unsigned)GridSize;
	SelectTile.setPosition(MouseGridPos.x * GridSize, MouseGridPos.y * GridSize);
}

Grid::~Grid()
{

}

