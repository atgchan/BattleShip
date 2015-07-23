#pragma once

#include "Ship.h"

class Ship_1:public Ship
{
public:
	Ship_1();
	~Ship_1();

	bool HitCheck(Point pos); //피격여부 체크
	void AddPosition(Point pos); //배 위치 초기화

private:
	std::string m_Name = ""; //배 이름
	int m_Hp; //체력
	Point m_Pos[5]; //배의 위치
};

