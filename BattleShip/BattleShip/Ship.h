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

	HitResult HitCheck(Point pos); //피격여부 체크
	void AddPosition(Point pos); //배 위치 초기화
	void AddPosition(char x, char y); //배 위치 초기화 함수 오버로딩
	void printPosition(); //배 위치 출력

	int GetHp() { return m_Hp; }
	std::string GetName() { return m_Name; }

protected:
	std::string m_Name; //배 이름
	int m_Hp; //체력
	int m_Size; //배 크기
	Point m_Pos[5]; //배의 위치

};

