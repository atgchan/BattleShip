#include "GameManager.h"
#include <iostream>

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::Init()
{
	m_Player1.SetupShips();
	m_Player2.SetupShips();
	m_Player1.setName("플레이어1");
	m_Player2.setName("플레이어2");
}

void GameManager::Start()
{
	while (m_Player1.hasShip() && m_Player2.hasShip())
	{
		Point p1 = m_Player1.attack(m_Player1.getLastAttack());
		HitResult hitResult1 = m_Player2.hitCheck(p1);
		printResult(hitResult1, m_Player1.getName());

		if (!m_Player2.hasShip())
		{
			break;
		}

		Point p2 = m_Player2.attack(m_Player2.getLastAttack());
		HitResult hitResult2 = m_Player1.hitCheck(p2);
		printResult(hitResult2, m_Player2.getName());

		turnCnt++;
	}
	std::cout << "---------------------게임끗-----" << "총 " << turnCnt << "턴 소모-------------------" << std::endl;
}

void GameManager::printResult(HitResult hitResult, std::string name)
{
	std::cout << name << " 공격!! >>>> ";
	switch (hitResult)
	{
	case MISS:
		std::cout << "안맞음-_-" << std::endl;
		break;
	case HIT:
		std::cout << "꽈아아아아아앙아아앙아ㅏ아앙" << std::endl;
		break;
	case D_DESTROY:
		std::cout << "디스트로이어 부서짐" << std::endl;
		break;
	case C_DESTROY:
		std::cout << "커리어 부서짐" << std::endl;
		break;
	case B_DESTROY:
		std::cout << "배틀쉡 부서짐" << std::endl;
		break;
	case A_DESTROY:
		std::cout << "에어크 부서짐" << std::endl;
		break;
	case ERROR:
		std::cout << "ㄴㄴㄴㄴㄴ" << std::endl;
		break;
	}
}

void GameManager::Reset()
{
	m_Player1.Reset();
	m_Player2.Reset();
	turnCnt = 0;
}

int GameManager::getGameCnt()
{
	return turnCnt;
}
