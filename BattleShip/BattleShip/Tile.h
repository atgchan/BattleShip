#pragma once
//#include "Ship.h"
class Ship;
class Tile
{
public:
	Tile();
	~Tile();

	void SetOccupiedShip(Ship* ship) {m_OccupiedShip = ship;}
	Ship* GetOccupiedShip();
	void Reset();
	bool isAttacked();
private:
	Ship* m_OccupiedShip;
	bool m_IsAttacked = false;
};

