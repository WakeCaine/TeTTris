#pragma once
#include "c:\users\shakecaine\desktop\programowanie\tettris\tettris\hclasses\blocks.h"
class Block_L :
	public Blocks
{
	//TYP BLOCZKA
	int type;
	int posX[4], posY[4];
	int opoznienie;
	sf::Clock ClockHead;
	sf::RenderWindow& okno;
	
public:
	Block_L(sf::RenderWindow& oknoAplikacji);

//WYBÓR U£O¯ENIA POCZ¥TKOWEGO KLOCKA
	void Reset()
	{
		
		if(type<50)
		{
			Reset1();
			type=1;
		}
		else
		{
			Reset2();
			type=0;
		}
	}
	void Reset1()
	{
		position=1;
		//Y=140 jest plansza
		int j=0;
		for(int i=0; i<3; i++)
		{
			posX[i]=130; posY[i]=60+j;
			j+=constant_twenty;
		}

		posX[3]=150; 
		posY[3]=posY[2];

	}
	void Reset2()
	{
		position=1;
		//Y=140 jest plansza
		int j=0;
		for(int i=0; i<3; i++)
		{
			posX[i]=130; posY[i]=60+j;
			j+=constant_twenty;
		}

		posX[3]=110; 
		posY[3]=posY[2];
	}

//METODY ODPOWADAJ¥CE ZA OBRÓT
	int returnPosition(char, int); //ZWRACANIE POZYCJI X lub Y wybranego BLOKU
	void Position1();//ZMIANA POZYCJI (1-4)
	void Position2();
	void Position3();
	void Position4();
//METODY ODPOWIEDZIALE ZA RESZTÊ(opisane w bazowej)
	void Draw();
	void Move(GameMap*);
	void AutoMove(int i, bool aim)
	{
		if(aim==true)
			posY[i]+=constant_twenty;
		else
			posY[i]-=constant_twenty;
	}

	void PositionX();
	~Block_L();
};



