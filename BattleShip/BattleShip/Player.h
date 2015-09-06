#pragma once

#include "Destroyer.h"
#include "Cruiser.h"
#include "Battleship.h"
#include "Aircraft.h"
#include <vector>
#include <string>
class Map;

class Player
{
public:
	Player();
	~Player();

	void SetupShips();
	void PrintShipPosition();
	bool hasShip();

	Point attack(int lastAttack);
	HitResult hitCheck(Point p);
	int getLastAttack();
	std::string getName();
	void setName(std::string mName);
	void Reset();
protected:
	std::vector<Ship*> m_Ships;
	Map* m_Map;

private:
	std::string mName;
	int lastAttack = 0;
};

