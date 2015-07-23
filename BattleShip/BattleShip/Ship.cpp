#include "Ship.h"


Ship::Ship()
{
}


Ship::~Ship()
{
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
		printf("�׸ճʾ� \n");
		return;
	}
	printf("��ȿ�������� \n");
}

void Ship::AddPosition(char x, char y)
{
	Point p(x, y);
	AddPosition(p);
}

void Ship::printPosition()
{
	for (int i = 0; i < m_Size; i++)
	{
		printf("%dth - x: %c, y: %c \n", i+1, m_Pos[i].x, m_Pos[i].y);
	}
}

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