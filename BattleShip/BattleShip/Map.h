#pragma once
#include "Player.h"
#include "Ship.h"
#include "Tile.h"
#include "Enum.h"

#define MAP_WIDTH 8
#define MAP_HEIGHT 8

class Map
{
public:
	Map();
	~Map();

	void ShipOccupy(int x, int y, Direction dir, Ship* ship);
	bool CheckPosition(int x, int y);
	bool CheckOutOfMap(int x, int y);
	bool CheckValidDirection(int x, int y, Direction dir, int size);
	Tile* GetTile(int x, int y);
	void Reset();
private:
	Tile mTiles[MAP_WIDTH][MAP_HEIGHT];
};

