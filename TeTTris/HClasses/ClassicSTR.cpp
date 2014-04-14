#include "ClassicSTR.h"

//KONSTRUKTOR klasy ClassicSTR
ClassicSTR :: ClassicSTR(sf::RenderWindow& oknoAplikacji): posX(90), posY(60), okno(oknoAplikacji)
{
	opoznienie=0;
}

void ClassicSTR:: Draw()
{
	if(Blocks::l1==true)
	{
		sf::Sprite sprit;
		sprit.setTexture(obrazek);
		sprit.setPosition(posX, posY);
		sprit.setScale(5,5);
		sprit.setOrigin(2,2);
		okno.draw(sprit);
	}
}

//METODA ODWRACAJ¥CA KLOCEK
void ClassicSTR :: Rotate()
{
	//sprit.rotate(90);
}

//METODA PORUSZAJ¥CA KLOCEK W P£ASZCZYNIE X
void ClassicSTR :: Move()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			posX+=20;
			if(ClassicSTR::posX>270)
			posX-=20;
		}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			posX-=20;
			if(posX<90)
			posX+=20;
		}
}

//METODA ODPOWIADAJ¥CA ZA AUTOMATYCZNE PORUSZANIE SIÊ KLOCKA
void ClassicSTR:: Auto()
{
		//Sprawdzamy, czy minê³o wystarczaj¹co czasu
		if(opoznienie==0)
			posY+=20;
		else if(opoznienie==20)
			opoznienie=-1;
		
		//Sprawdzamy, czy obiekt nie wychodzi poza planszê
		if(posY<60)
			posY+=20;
		else if(posY>540)
			posY-=20;

		opoznienie+=1;
}

//FUNKCJA ZWRACAJ¥CA ODPOWIED CZY DOTKNIÊTO ELEMENTU OD DO£U
bool ClassicSTR:: BottomCheck(GameMap* mapka)
{
	if(opoznienie==0 && (posY+20)>540)
	{
		std::cout<<posX<<" "<<posY<<std::endl;
		mapka->AddBlocks(posX, posY);
		mapka->CheckSpace(1,20);
		std::cout<<"\n";
		return true;
	}
	else 
		return false;
}

ClassicSTR :: ~ClassicSTR()
{

}
