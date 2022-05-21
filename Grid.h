#pragma once
#include "TileMap.h"
#include <math.h>
#include "Level.h"

using namespace std;
class Grid
{
protected:
	int MapSize;
private:
	float GridSize;
	int tileNumber_X, tileNumber_Y;
	int Location;
	sf::RectangleShape Tiles[20 * 20];
	TileMap *Map;
	int tempLev[400] = { 0 };


	

public:

	Level levels;
	void SelectLevel(int level);
	
	Grid();
	void SetGrids();
	void DrawGrids(sf::RenderWindow& i_window);
	const float& GetGridSize() const;
	const int& GetMapSize() const;
	void LoadMap();
	int CheckCollision(float location_x, float location_y);
	friend class Player;

	~Grid();
};

