#pragma once

#include "Ship.h"

class Ship_1:public Ship
{
public:
	Ship_1();
	~Ship_1();

	bool HitCheck(Point pos); //�ǰݿ��� üũ
	void AddPosition(Point pos); //�� ��ġ �ʱ�ȭ

private:
	std::string m_Name = ""; //�� �̸�
	int m_Hp; //ü��
	Point m_Pos[5]; //���� ��ġ
};

