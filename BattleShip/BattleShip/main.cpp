#include <stdio.h>
#include "Ship_5.h"

int main()
{
	Ship_5 Ship_5;

	printf("[Ship_5] name = %s, hp = %d \n",
		Ship_5.GetName().c_str(),
		Ship_5.GetHp());

	for (int i = 0; i < 10; i++)
	{
		Ship_5.AddPosition('a','1'+i);
	}

	Ship_5.printPosition();

	for (int i = 0; i < 10; i++)
	{
		printf("%dÂ÷ °á°ú: %d \n", i+1, Ship_5.HitCheck(Point('a', '1' + i)));
	}

	getchar();
	return 0;
}