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
	m_Player1.setName("�÷��̾�1");
	m_Player2.setName("�÷��̾�2");
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
	std::cout << "---------------------���Ӳ�-----" << "�� " << turnCnt << "�� �Ҹ�-------------------" << std::endl;
}

void GameManager::printResult(HitResult hitResult, std::string name)
{
	std::cout << name << " ����!! >>>> ";
	switch (hitResult)
	{
	case MISS:
		std::cout << "�ȸ���-_-" << std::endl;
		break;
	case HIT:
		std::cout << "�ʾƾƾƾƾƾӾƾƾӾƤ��ƾ�" << std::endl;
		break;
	case D_DESTROY:
		std::cout << "��Ʈ���̾� �μ���" << std::endl;
		break;
	case C_DESTROY:
		std::cout << "Ŀ���� �μ���" << std::endl;
		break;
	case B_DESTROY:
		std::cout << "��Ʋ�v �μ���" << std::endl;
		break;
	case A_DESTROY:
		std::cout << "����ũ �μ���" << std::endl;
		break;
	case ERROR:
		std::cout << "����������" << std::endl;
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
