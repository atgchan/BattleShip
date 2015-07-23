#pragma once

#include "Player.h"
#include "Map.h"


class GameMaster 
{
public:
	GameMaster();
	~GameMaster();

private:
	Map map;
	Player currentPlayer;
};