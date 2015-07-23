#include "Practice.h"
#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#include <iostream>
#include <string>
#include <vector>


Practice::Practice()
{
}


Practice::~Practice()
{
}

void main() {
	std::vector<std::string> ships;
	ships.push_back("aircraft");
	ships.push_back("battleShip");
	ships.push_back("cruiser");
	ships.push_back("destroyer");
	ships.push_back("destroyer");

	srand(unsigned int(time(NULL)));

	std::string str;

	while (!ships.empty())
	{
		std::cin >> str;

		if (str.size() == 2 && (str[0] >= 'A' && str[0] <= 'H')
			&& (str[1] >= '1' && str[1] <= '8'))
		{

			switch (rand() % 3)
			{
			case 0:
				std::cout << "Hit!!!! " << str << std::endl;
				break;
			case 1:
			{
				int point = rand() % ships.size();
				std::cout << "Destroy!!!! " << str << std::endl << ships[point] << std::endl;
				ships.erase(ships.begin() + point);

				for (int i = 0; i < ships.size(); i++)
				{
					std::cout << "<" << ships.at(i) << "> ";
				}
				std::cout << std::endl;
	
				break;
			}
			case 2:
				std::cout << "Miss!!!! " << str << std::endl;
				break;
			default:
				break;
			}
		}
	}

	std::cout << "Game OVer!!" << std::endl;
	getchar();

}