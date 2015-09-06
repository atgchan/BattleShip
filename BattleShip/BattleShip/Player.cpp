#include "Player.h"
#include "Map.h"

Player::Player()
{
	m_Map = new Map();
	Destroyer* destroyer1 = new Destroyer();
	m_Ships.push_back(destroyer1);
	Destroyer* destroyer2 = new Destroyer();
	m_Ships.push_back(destroyer2);
	Cruiser* cruiser = new Cruiser();
	m_Ships.push_back(cruiser);
	Battleship* battleShip = new Battleship();
	m_Ships.push_back(battleShip);
	Aircraft* aircraft = new Aircraft();
	m_Ships.push_back(aircraft);
}

Player::~Player()
{
	delete m_Map;
	for (auto ship : m_Ships)
	{
		delete ship;
	}
	m_Ships.clear();
}

void Player::SetupShips()
{
	for (auto ship : m_Ships)
	{
		bool result = false;
		while (false == result)
		{
			int x = rand() % MAP_WIDTH;
			int y = rand() % MAP_HEIGHT;
			Direction dir = (Direction)(rand() % (int)DIR_MAX);
			for (int i = 0; i < Direction::DIR_MAX; ++i)
			{
				result = m_Map->CheckValidDirection(x, y, dir, ship->GetSize());
				if (result == false)
				{
					int directionInt = (int)dir;
					dir = (Direction)(++directionInt % Direction::DIR_MAX);
				}
				else
				{
					ship->SetOnMap(x, y, dir);
					m_Map->ShipOccupy(x, y, dir, ship);
					break;
				}
			}
		}
	}
}

void Player::PrintShipPosition()
{
	for (auto ship : m_Ships)
	{
		ship->printPosition();
	}
}

bool Player::hasShip()
{
	for (auto ship : m_Ships)
	{
		if (ship->GetHp() != 0)
		{
			return true;
		}
	}
	return false;
}

Point Player::attack(int lastAttack)
{
	int x = lastAttack % 8;
	int y = lastAttack / 8;

	Point p('a'+x, '1'+y);

	return p;
}

HitResult Player::hitCheck(Point p)
{
	Tile* targetTile = m_Map->GetTile(p.getX(), p.getY());
	
	if (targetTile == nullptr || targetTile->isAttacked())
	{
		return ERROR;
	}
	
	Ship* targetShip = targetTile->GetOccupiedShip();

	if ( targetShip != nullptr)
	{	
		targetShip->OnHit();
		if (targetShip->GetHp() == 0 )
		{
			switch (targetShip->GetSize())
			{
			case 2:
				return D_DESTROY;
			case 3:
				return C_DESTROY;
			case 4:
				return B_DESTROY;
			case 5:
				return A_DESTROY;
			default:
				return ERROR;
			}
		}
		targetTile->SetOccupiedShip(nullptr);
		return HIT;
	}

	return MISS;
}

int Player::getLastAttack()
{
	return lastAttack++;
}

std::string Player::getName()
{
	return mName;
}

void Player::setName(std::string name)
{
	mName = name;
}

void Player::Reset()
{
	lastAttack = 0;
	m_Map->Reset();
	for (auto ship : m_Ships)
	{
		ship->Reset();
	}
}
