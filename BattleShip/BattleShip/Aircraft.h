#pragma once

#include "Ship.h"

class Aircraft : public Ship
{
public:
	Aircraft();
	~Aircraft();

	//bool HitCheck(Point pos); //�ǰݿ��� üũ
	//void AddPosition(Point pos); //�� ��ġ �ʱ�ȭ
};

