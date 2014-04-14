#pragma once
#include "Blocks.h"
#include <time.h>

class Block_I :
	public Blocks
{
	//TYP BLOCZKA
	int type;
	//NA KTÓRYM I CZY W OGÓLE TWORZY SIÊ BLOK SPECJALNY
	int posX[4], posY[4];
	int opoznienie; //WYLICZANIE ILOŒCI PÊTLI, czyt. CZASU PO KTÓRYM KLOCEK SIÊ RUSZY AUTOMATYCZNIE
	sf::Clock ClockHead;
	sf::RenderWindow& okno;
	
public:
	Block_I(sf::RenderWindow& oknoAplikacji);

//WYBÓR U£O¯ENIA POCZ¥TKOWEGO KLOCKA
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
		temposition=1;
		//Y=140 jest plansza
		int j=0;
		for(int i=0; i<4; i++)
		{
			posX[i]=130+j; posY[i]=60;
			j+=constant_twenty;
		}
	}
	void Reset2()
	{
		position=2;
		temposition=2;
		//Y=140 jest plansza
		int j=0;
		for(int i=0; i<4; i++)
		{
			posX[i]=130; posY[i]=60+j;
			j+=constant_twenty;
		}
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
//POZYCJA NASTÊPNEGO WYGENEROWANEGO BLOCZKA WIDOCZNA W OKIENKU
	void PositionX();

	~Block_I();
};

