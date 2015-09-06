#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
}
bool Map::CheckOutOfMap(int x, int y)
{
	return !(x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT);
}

bool Map::CheckPosition(int x, int y)
{
	if (false == CheckOutOfMap(x, y))
	{
		return false;
	}

	Tile* tile = GetTile(x, y);
	_ASSERT(tile != nullptr);
	Ship* occupiedShip = tile->GetOccupiedShip();

	if (nullptr != occupiedShip)
	{
		return false;
	}
	return true;
}

bool Map::CheckValidDirection(int x, int y, Direction dir, int size)
{
	if (false == CheckPosition(x, y))
		return false;

	int deltaX = 0;
	int deltaY = 0;
	switch (dir)
	{
	case DIR_UP:
		deltaY = 1;
		break;
	case DIR_DOWN:
		deltaY = -1;
		break;
	case DIR_LEFT:
		deltaX = -1;
		break;
	case DIR_RIGHT:
		deltaX = 1;
		break;
	}

	for (int i = 0; i < size; ++i)
	{
		if (false == CheckPosition(x, y))
			return false;

		x += deltaX;
		y += deltaY;
	}
	return true;
}

void Map::ShipOccupy(int x, int y, Direction dir, Ship* ship)
{
	int deltaX = 0;
	int deltaY = 0;
	switch (dir)
	{
	case DIR_UP:
		deltaY = 1;
		break;
	case DIR_DOWN:
		deltaY = -1;
		break;
	case DIR_LEFT:
		deltaX = -1;
		break;
	case DIR_RIGHT:
		deltaX = 1;
		break;
	}

	for (int i = 0; i < ship->GetSize(); ++i)
	{
		Tile* tile = GetTile(x, y);
		_ASSERT(tile != nullptr);
		tile->SetOccupiedShip(ship);
		x += deltaX;
		y += deltaY;
	}
}

Tile* Map::GetTile(int x, int y)
{
	if (false == CheckOutOfMap(x, y))
		return nullptr;

	return &(mTiles[x][y]);
}

void Map::Reset()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			mTiles[i][j].Reset();
		}
	}
}
