#pragma once

#include "Player.h"
#include "Ship.h"
class Map
{
public:
	Map();
	~Map();
	void addPlayer(Player p);
	void addShip(Ship s);
	void attackedMap(int x, int y);

private:
};

