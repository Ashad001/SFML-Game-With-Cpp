#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class Grid
{
protected:
	int MapSize;
private:
	float GridSize;
	sf::Vector2u MouseGridPos;
	sf::Vector2i MouseWindowPos;	


	sf::RectangleShape Tiles[40 * 40];
	
protected:
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

