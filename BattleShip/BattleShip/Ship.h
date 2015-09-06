#pragma once
#include <string>
#include "Enum.h"
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
	char x = '0';
	char y = '0';

	int getX(){ return x - 'a'; };
	int getY(){ return y - '1'; };
};

class Ship
{
public:
	Ship();
	~Ship();

	//HitResult HitCheck(Point pos); //�ǰݿ��� üũ
	void SetOnMap(int x, int y, Direction dir);
	void AddPosition(Point pos); //�� ��ġ �ʱ�ȭ
	void AddPosition(char x, char y); //�� ��ġ �ʱ�ȭ �Լ� �����ε�
	void printPosition(); //�� ��ġ ���

	int GetHp() { return m_Hp; }
	std::string GetName() { return m_Name; }
	int GetSize() { return m_Size; }

	void OnHit(){ m_Hp--; }
	void Reset();
protected:
	std::string m_Name; //�� �̸�
	int m_Hp; //ü��
	int m_Size; //�� ũ��
	Point m_Pos[5]; //���� ��ġ

};

