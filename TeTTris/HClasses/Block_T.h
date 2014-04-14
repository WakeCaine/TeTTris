#pragma once
#include "Blocks.h"
#include <time.h>

class Block_T :
	public Blocks
{
	//TYP BLOCZKA
	int type;
	//NA KT�RYM I CZY W OG�LE TWORZY SI� BLOK SPECJALNY
	int posX[4], posY[4];
	int opoznienie; //WYLICZANIE ILO�CI P�TLI, czyt. CZASU PO KT�RYM KLOCEK SI� RUSZY AUTOMATYCZNIE
	sf::Clock ClockHead;
	sf::RenderWindow& okno;
	
public:
	Block_T(sf::RenderWindow& oknoAplikacji);

//WYB�R U�O�ENIA POCZ�TKOWEGO KLOCKA
	void Reset()
	{
		
		if(type<50)
		{
			Reset1();
		}
		else
		{
			Reset2();
		}
	}
	void Reset1()
	{
		position=1;
		//Y=140 jest plansza
		int j=0;
		for(int i=0; i<3; i++)
		{
			posX[i]=130+j; posY[i]=60;
			j+=constant_twenty;
		}
		posX[3]=150;
		posY[3]=80;
	}
	void Reset2()
	{
		position=3;
		//Y=140 jest plansza
		int j=0;
		for(int i=0; i<4; i++)
		{
			posX[i]=130+j; posY[i]=80;
			j+=constant_twenty;
		}
		posX[3]=150;
		posY[3]=60;
	}

//METODY ODPOWADAJ�CE ZA OBR�T
	int returnPosition(char, int); //ZWRACANIE POZYCJI X lub Y wybranego BLOKU
	void Position1();//ZMIANA POZYCJI (1-4)
	void Position2();
	void Position3();
	void Position4();
//METODY ODPOWIEDZIALE ZA RESZT�(opisane w bazowej)
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

	~Block_T()
	{
		mess=0;
	}
};

