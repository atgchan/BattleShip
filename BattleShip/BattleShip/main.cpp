#include <stdio.h>
#include "Aircraft.h"
#include "Player.h"
#include <time.h>
#include "GameManager.h"
int main()
{
	srand(unsigned(time(NULL)));
	GameManager gm;
	
	int total = 0;

	for (int i = 0; i < 10; i++)
	{
		gm.Init();
		gm.Start();
		total += gm.getGameCnt();
		gm.Reset();
	}

	printf("평균 턴 진행 수 : %d \n", total / 10);

	getchar();
	return 0;
}