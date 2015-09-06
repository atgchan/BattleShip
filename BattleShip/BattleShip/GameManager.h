#pragma once

#include "Player.h"
#include "Map.h"


class GameManager 
{
public:
	GameManager();
	~GameManager();

	void Init();
	void Start();
	void printResult(HitResult hitResult, std::string name);
	void Reset();
	int getGameCnt();

private:
	Player m_Player1;
	Player m_Player2;
	int turnCnt = 0;
};