#pragma once
#include "c:\users\shakecaine\desktop\programowanie\tettris\tettris\hclasses\blocks.h"
class Block_Z :
	public Blocks
{	
	//TYP BLOCZKA
	int type;
	//NA KT�RYM I CZY W OG�LE TWORZY SI� BLOK SPECJALNY
	int posX[4], posY[4];
	int opoznienie;
	sf::Clock ClockHead;
	sf::RenderWindow& okno;
	
public:
	Block_Z(sf::RenderWindow& oknoAplikacji);

//WYB�R U�O�ENIA POCZ�TKOWEGO KLOCKA
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
		for(int i=0; i<2; i++)
		{
			posX[i]=130+j; posY[i]=60;
			j+=20;
		}

		j=0;

		for(int i=2; i<4; i++)
		{
			posX[i]=150+j; posY[i]=80;
			j+=20;
		}

	}
	void Reset2()
	{
		position=2;
		//Y=140 jest plansza
		int j=0;
		for(int i=0; i<2; i++)
		{
			posX[i]=170-j; posY[i]=60;
			j+=20;
		}

		j=0;

		for(int i=2; i<4; i++)
		{
			posX[i]=130+j; posY[i]=80;
			j+=20;
		}
	}

//METODY ODPOWADAJ�CE ZA OBR�T
	int returnPosition(char, int); //ZWRACANIE POZYCJI X lub Y wybranego BLOKU
	void Position1();//ZMIANA POZYCJI (1-4)
	void Position2();
	void Position3();
	void Position4();
//METODY ODPOWIEDZIALE ZA RESZT�(opisane w bazowej)
	void Rotate();
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

	~Block_Z();
};

