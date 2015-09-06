#pragma once

#include "Ship.h"

class Aircraft : public Ship
{
public:
	Aircraft();
	~Aircraft();

	//bool HitCheck(Point pos); //피격여부 체크
	//void AddPosition(Point pos); //배 위치 초기화
};

