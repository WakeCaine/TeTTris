#include "Block_Q.h"


//KONSTRUKTOR klasy ClassicSTR
Block_Q :: Block_Q(sf::RenderWindow& oknoAplikacji): okno(oknoAplikacji)
{
	position=1;
	opoznienie=0;
//	srand(unsigned(time(NULL)));
	Reset();
	for(int i=1; i<10; i++)
		generateSpecial(special);
		generateMess(special);
}

void Block_Q :: Draw()
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

int Block_Q :: returnPosition(char character, int k)
{
	if(character=='x')
		return posX[k];
	else
		return posY[k];
}

//METODA PORUSZAJ•CA KLOCEK W P£ASZCZYèNIE X
void Block_Q :: Move(GameMap* mapka)
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

Block_Q :: ~Block_Q()
{
	mess=0;
}

void Block_Q :: PositionX()
{
	int j=0;
		for(int i=0; i<2; i++)
		{
			posX[i]=535+j; posY[i]=190;
			j+=constant_twenty;
		}
		j=0;

		for(int i=2; i<4; i++)
		{
			posX[i]=535+j; posY[i]=210;
			j+=constant_twenty;
		}
}

