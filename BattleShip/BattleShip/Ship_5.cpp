#include "Ship_5.h"


Ship_5::Ship_5()
{
	m_Name = "Aircraft";
	m_Hp = 5;
	m_Size = m_Hp;

	Point p = { '0', '0' };
	for (int i = 0; i < m_Hp; i++)
	{
		m_Pos[i] = p;
	}
}


Ship_5::~Ship_5()
{
}
