#pragma once

#include "Ship.h"

class Battleship:public Ship
{
public:
	Battleship();
	~Battleship();

	//bool HitCheck(Point pos); //피격여부 체크
	//void AddPosition(Point pos); //배 위치 초기화
};

