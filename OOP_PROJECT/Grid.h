#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class Grid
{
private:
	sf::Sprite White;
	sf::Sprite Black;
	vector<sf::Sprite> Blocks;
	float GridSize;
	sf::Vector2u MouseGridPos;
	sf::Vector2i MouseWindowPos;
	sf::RectangleShape SelectTile;
	sf::RectangleShape Tiles[20 * 20];
public:
	Grid(float gridSize);
	void SetGrids();
	void DrawGrids(sf::RenderWindow& i_window);
	void SelectGridTile(sf::RenderWindow& i_window);

	~Grid();
};

