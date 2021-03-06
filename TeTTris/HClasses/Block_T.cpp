#include "Block_T.h"


//KONSTRUKTOR klasy
Block_T :: Block_T(sf::RenderWindow& oknoAplikacji): okno(oknoAplikacji)
{
	position=1;
	opoznienie=0;
//	srand(unsigned(time(NULL)));
	int pozycja;
	for(int i=0; i<10; i++)
	pozycja=rand()%100+1;
	type=pozycja;
	Reset();
	for(int i=1; i<10; i++)
		generateSpecial(special);
		generateMess(special);
}

void Block_T :: Draw()
{
	if(Blocks::l1==true)
	{
		sf::Sprite sprit[4];
		for(int i=0; i<=3; i++)
		{
			//std::cout<<posX[i]<<" "<<posY[i]<<std::endl;
			sprit[i].setTexture(obrazek);
			sprit[i].setColor(sf::Color(30,144,255));
			if(gamenumber==2 && i==special)
			{				
				if(mess<=20)
					sprit[special].setColor(sf::Color(255,255,0));
				else if(mess>20)
				{
					sprit[special].setColor(sf::Color(25,25,112));
				}
			}
			sprit[i].setPosition(posX[i], posY[i]);
			sprit[i].setScale(5,5);
			sprit[i].setOrigin(2,2);
			okno.draw(sprit[i]);
		}
	}
}

void Block_T :: Position1()
{
	posX[0]=posX[1]; 
	posY[0]=posY[1]-constant_twenty; 
	posX[2]=posX[1]; 
	posY[2]=posY[1]+constant_twenty; 
	posX[3]=posX[1]-constant_twenty; 
	posY[3]=posY[1];
}
void Block_T :: Position2()
{
	posX[0]=posX[1]+constant_twenty;
	posY[0]=posY[1];
	posX[2]=posX[1]-constant_twenty;
	posY[2]=posY[1];
	posX[3]=posX[1];
	posY[3]=posY[1]-constant_twenty;
}
void Block_T :: Position3()
{
	posX[0]=posX[1];
	posY[0]=posY[1]+constant_twenty;
	posX[2]=posX[1];
	posY[2]=posY[1]-constant_twenty;
	posX[3]=posX[1]+constant_twenty;
	posY[3]=posY[1];
}
void Block_T :: Position4()
{
	posX[0]=posX[1]-constant_twenty;
	posY[0]=posY[1];
	posX[2]=posX[1]+constant_twenty;
	posY[2]=posY[1];
	posX[3]=posX[1];
	posY[3]=posY[1]+constant_twenty;
}

int Block_T :: returnPosition(char character, int k)
{
	if(character=='x')
		return posX[k];
	else
		return posY[k];
}
//METODA PORUSZAJ�CA KLOCEK W P�ASZCZY�NIE X
void Block_T :: Move(GameMap* mapka)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			std::cout<<"RIGHT"<<std::endl;
			for(int i=0; i<4; i++)
			{
				posX[i]+=constant_twenty;
				if(posX[i]>270)
					for(int i=0; i<4; i++)
						posX[i]-=constant_twenty;
			}

			for(int i=0; i<10; i++)
			{
				for(int j=0; j<=constant_twenty; j++)
				{
					for(int k=0; k<4; k++)
					{
						bool check = mapka->CheckSpace(i,j);
						if(check==true && (posX[k]-90)/constant_twenty==i && (posY[k]-140)/constant_twenty==j)
						{
							for(int l=0; l<4; l++)
							{
								posX[l]-=constant_twenty;
							}
						}
					}
				}
			}

		}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			std::cout<<"LEFT"<<std::endl;
			for(int i=0; i<4; i++)
			{
				posX[i]-=constant_twenty;
				if(posX[i]<90)
					for(int i=0; i<4; i++)
						posX[i]+=constant_twenty;
			}

			for(int i=0; i<10; i++)
			{
				for(int j=0; j<=constant_twenty; j++)
				{
					for(int k=0; k<4; k++)
					{
						bool check = mapka->CheckSpace(i,j);
						if(check==true && (posX[k]-90)/constant_twenty==i && (posY[k]-140)/constant_twenty==j)
						{
							for(int l=0; l<4; l++)
							{
								posX[l]+=constant_twenty;
							}
						}
					}
				}
			}

		}
	//sprit.rotate(90);
}

void Block_T :: PositionX()
{
	if(type==1)
	{
		int j=0;
		for(int i=0; i<3; i++)
		{
			posX[i]=525+j; posY[i]=190;
			j+=constant_twenty;
		}
		posX[3]=545;
		posY[3]=210;
	}
	else
	{
		int j=0;
		for(int i=0; i<4; i++)
		{
			posX[i]=525+j; posY[i]=210;
			j+=constant_twenty;
		}
		posX[3]=545;
		posY[3]=190;
	}
}
