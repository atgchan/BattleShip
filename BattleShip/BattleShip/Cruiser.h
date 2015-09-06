#pragma once

#include "Ship.h"

class Cruiser:public Ship
{
public:
	Cruiser();
	~Cruiser();

	//bool HitCheck(Point pos); //피격여부 체크
	//void AddPosition(Point pos); //배 위치 초기화
};