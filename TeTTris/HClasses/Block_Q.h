#pragma once
#include "c:\users\shakecaine\desktop\programowanie\tettris\tettris\hclasses\blocks.h"
class Block_Q :
	public Blocks
{
	//TYP BLOCZKA
	int type;
	//NA KTÓRYM I CZY W OGÓLE TWORZY SIÊ BLOK SPECJALNY
	int posX[4], posY[4];
	int opoznienie;
	sf::Clock ClockHead;
	sf::RenderWindow& okno;
	
public:
	Block_Q(sf::RenderWindow& oknoAplikacji);
	
	void Reset()
	{
		position=1;
		//Y=140 jest plansza
		int j=0;
		for(int i=0; i<2; i++)
		{
			posX[i]=130+j; posY[i]=60;
			j+=constant_twenty;
		}
		j=0;

		for(int i=2; i<4; i++)
		{
			posX[i]=130+j; posY[i]=80;
			j+=constant_twenty;
		}
	}

//METODY ODPOWADAJ¥CE ZA OBRÓT
	int returnPosition(char, int); //ZWRACANIE POZYCJI X lub Y wybranego BLOKU
	void Position1(){}//PUSTE, BO W KWADRACIE NIE POTRZEBA
	void Position2(){}
	void Position3(){}
	void Position4(){}
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
	~Block_Q();
};



