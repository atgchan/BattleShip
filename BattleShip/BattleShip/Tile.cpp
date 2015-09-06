#include "Tile.h"


Tile::Tile()
	:m_OccupiedShip(nullptr)
{
}


Tile::~Tile()
{
}

void Tile::Reset()
{
	m_OccupiedShip = nullptr;
	m_IsAttacked = false;
}

bool Tile::isAttacked()
{
	return m_IsAttacked;
}

Ship* Tile::GetOccupiedShip()
{
	return m_OccupiedShip;
}