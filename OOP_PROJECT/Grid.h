#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class Grid
{
private:
	float GridSize;
	sf::Vector2u MouseGridPos;
	sf::Vector2i MouseWindowPos;
	sf::RectangleShape SelectTile;
	sf::RectangleShape Tiles[20 * 20];
protected:
	int MapSize;
	int tileNumber_X;
	int tileNumber_Y;
public:
	Grid(float gridSize);
protected:
	void SetGrids();
	void DrawGrids(sf::RenderWindow& i_window);
public:
	float GetGridSize() const;

	~Grid();
};

