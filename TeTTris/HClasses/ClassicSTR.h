#pragma once
#include "Blocks.h"


class ClassicSTR : public Blocks
{
	char type;
	int posX, posY;
	int opoznienie;
	sf::RenderWindow& okno;
	
public:
	ClassicSTR(sf::RenderWindow& oknoAplikacji);
	
	void Reset()
	{
		//Y=140 jest plansza
		posX=90; posY=60;
	}
	bool BottomCheck(GameMap*);

	void Draw();

	void Rotate();

	void Move(GameMap*);
	
	void Auto();

	~ClassicSTR();
};
