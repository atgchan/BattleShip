#include "Ship.h"


Ship::Ship()
{
}


Ship::~Ship()
{
}

void Ship::SetOnMap(int x, int y, Direction dir)
{
	int deltaX = 0;
	int deltaY = 0;
	switch (dir)
	{
	case DIR_UP:
		deltaY = 1;
		break;
	case DIR_DOWN:
		deltaY = -1;
		break;
	case DIR_LEFT:
		deltaX = -1;
		break;
	case DIR_RIGHT:
		deltaX = 1;
		break;
	}

	for (int i = 0; i < m_Size; ++i)
	{
		char cx = 'a' + x;
		char cy = '1' + y;
		AddPosition(cx, cy);
		x += deltaX;
		y += deltaY;
	}
}

void Ship::AddPosition(Point pos)
{
	if (pos.x <= 'h' && pos.x >= 'a' && pos.y <= '8' && pos.y >= '1')
	{
		for (int i = 0; i < m_Size; i++)
		{
			if (m_Pos[i].x == '0' && m_Pos[i].y == '0')
			{
				m_Pos[i].x = pos.x;
				m_Pos[i].y = pos.y;
				return;
			}
		}
		printf("그먼너어 \n");
		return;
	}
	printf("유효하지않음 \n");
}

void Ship::AddPosition(char x, char y)
{
	Point p(x, y);
	AddPosition(p);
}

void Ship::printPosition()
{
	printf("====Ship name %s====\n", m_Name.c_str());
	for (int i = 0; i < m_Size; i++)
	{
		printf("%dth - x: %c, y: %c \n", i+1, m_Pos[i].x, m_Pos[i].y);
	}
}

void Ship::Reset()
{
	m_Hp = m_Size;
	for (int i = 0; i < m_Size; i++)
	{
		m_Pos[i].x = '0';
		m_Pos[i].y = '0';
	}
}

/*
HitResult Ship::HitCheck(Point pos)
{
	for (int i = 0; i < m_Size; i++){
		if (m_Pos[i].x == pos.x && m_Pos[i].y == pos.y)
		{
			if (m_Hp == 0)
			{
				return DESTROY;
			}

			if (--m_Hp == 0)
			{
				return DESTROY;
			}
			return HIT;
		}
	}

	return MISS;
}
*/