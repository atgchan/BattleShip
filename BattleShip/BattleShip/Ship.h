#pragma once

#include <string>

struct Point
{	
	Point(){}
	Point(char ax, char ay)
	{
		x = ax;
		y = ay;
	}
	//x = 'a' ~ 'h'
	//y = '1' ~ '8'
	char x, y;
};

enum HitResult
{
	MISS,
	HIT,
	DESTROY
};

class Ship
{
public:
	Ship();
	~Ship();

	HitResult HitCheck(Point pos); //�ǰݿ��� üũ
	void AddPosition(Point pos); //�� ��ġ �ʱ�ȭ
	void AddPosition(char x, char y); //�� ��ġ �ʱ�ȭ �Լ� �����ε�
	void printPosition(); //�� ��ġ ���

	int GetHp() { return m_Hp; }
	std::string GetName() { return m_Name; }

protected:
	std::string m_Name; //�� �̸�
	int m_Hp; //ü��
	int m_Size; //�� ũ��
	Point m_Pos[5]; //���� ��ġ

};

