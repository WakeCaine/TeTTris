#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <string>
#include "GameMap.h"
#include <time.h>

//G��WNA KLASA TRZYMAJ�CA METODY WIRTUALNE- do edycji
class Blocks
{
protected:
	bool l1,l2;
	int typeblock;
	sf::Texture obrazek;
	Blocks()
	{
		srand(unsigned(time(NULL)));
		l1=obrazek.loadFromFile("TETTRISBLOCKS1.png");
	}
public:
	static const int constant_twenty=20;
	static int speed;
	static int position;
	int special;
	int mess;
	int temposition;
	
//////////////////////////////////////////////////////////////////////
public:
	//TYP KLOCKA
	int returnType()
	{
		return typeblock;
	}

	void addType(int type)
	{
		typeblock=type;
	}

	//NUMER TRYBU- musi by� edytowalny
	 int gamenumber;

	//SPRAWDZAM TYP BLOCZKA do Ramki
	virtual void PositionX()=0;

	//SPRAWDZENIE ETAPU(1-4) OBR�CENIA KLOCKA
	int checkDirection(bool kier)
	{
		if(kier==true)
			return Blocks::position;
		else
		{
			if(Blocks::position-2==0)
				return 4;
			else if(Blocks::position-2<0)
			{
				return 3;
			}
			else
			{
				return Blocks::position-2;
			}
		}
	}

	//ZWI�KSZENIE/ZMNIEJSZENIE/RESET/ZWROT SZYBKO�CI OPADANIA
	void increase(int, int&);
	void decrease();
	int retrunspeed()
	{
		return speed;
	}
	void resetspeed()
	{
		speed=10;
	}

	//GENERACJA DODATKOWYCH BLOCZK�W
	void generateSpecial(int& special);
	void generateMess(int special);
	//OBR�T
	void RotateR(Blocks*, GameMap*);
	///////////////////////////////////////////////////////////////////
	//METODY POMOCNE PRZY OBROCIE
	void changePosition(Blocks*, int);
	virtual int returnPosition(char, int)=0;
	virtual void Position1()=0;
	virtual void Position2()=0;
	virtual void Position3()=0;
	virtual void Position4()=0;
	///////////////////////////////////////////////////////////////////
	virtual void Reset()=0;
	virtual void Draw()=0;
	virtual void Move(GameMap*)=0;
	virtual void AutoMove(int, bool)=0;
	//METODA ODPOWIADAJ�CA ZA AUTOMATYCZNE PORUSZANIE SI� KLOCKA
	bool Auto(Blocks*, GameMap*, int&, bool&, int, int);
	//FUNKCJA ZWRACAJ�CA ODPOWIED� CZY DOTKNI�TO ELEMENTU OD DO�U
	bool BottomCheck(Blocks*, GameMap*, int, int);

//---------------------------------------------------------------------------
	virtual ~Blocks()
	{

	}
};