#pragma once
#include <iostream>

class GameMap
{
	int **tab;
public:
	GameMap();
	void AddBlocks(int, int, int, int, int);
	void CheckLine(int&, bool, int);
	bool CheckSpace(int x, int y)
	{
		if(tab[x][y+5]>0)
		{
			//std::cout<<"\nTUTAJ!";
			return true;
		}
		else 
			return false;
	}
	int CheckType(int x, int y)
	{
		if(tab[x][y+5]==1)
			return 1;
		else if(tab[x][y+5]==2)
			return 2;
		else if(tab[x][y+5]>2)
			return 3;
	}
	//SPRAWDZAM GRAWITACJÊ
	void CheckGravity();

	void Clear();

	~GameMap()
	{
		delete [] *tab;
		delete tab;
	};
};
