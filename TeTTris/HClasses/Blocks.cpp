#include "Blocks.h"

int Blocks::speed=10;
int Blocks::position=1;
///////////////////////////////////////////////////////////////////////
//KONTROLA PRÊDKOŒCI OPADANIA
void Blocks::increase(int latency, int& opoznienie)
	{
			if(speed>1)
				speed-=1;
			opoznienie=0;
		std::cout<<"SPEED UP+ OBECNA: "<<speed<<std::endl;
	}
void Blocks::decrease()
	{
		speed+=1;
		std::cout<<"SPEED DOWN-  OBECNA: "<<speed<<std::endl;
	}

//GENERACJA DODATKOWYCH BLOCZKÓW
void Blocks:: generateSpecial(int& special)
{
	for(int i=1; i<10; i++)
		mess=rand()%100+1;
	if(mess<=50)
	{
		std::cout<<"FIRST MESS::"<<mess<<std::endl;
		mess=rand()%100+1;
		mess=mess/25;	
		special=mess;
	}
	else 
		special=4;
}

void Blocks:: generateMess(int special)
{
	int messs=0;
	if(special<4)
	{
		std::cout<<"SP"<<std::endl;
		std::cout<<special<<std::endl;
		for(int i=1; i<10; i++)
			messs=rand()%100+1;
		std::cout<<"MESS "<<messs<<std::endl;
		mess=messs;
	}
}

//OBRÓT KLOCKA
void Blocks:: RotateR(Blocks* Nowy, GameMap* map)
{
			changePosition(Nowy, Nowy->checkDirection(true));
			for(int i=0; i<10; i++)
			{
				for(int j=0; j<=Blocks::constant_twenty; j++)
				{
					for(int k=0; k<4; k++)
					{
						bool check = map->CheckSpace(i,j);
						if(check==true && (Nowy->returnPosition('x',k)-90)/20==i 
							&& (Nowy->returnPosition('y',k)-140)/20==j)
						{
							Nowy->changePosition(Nowy, Nowy->checkDirection(false));

							if(Blocks::position>1)
								Blocks::position-=1;
							else if(Blocks::position-1==0)
							{
								Blocks::position+=4;
							}
						}
					}
				}
			}
}

//WYBÓR ODPOWIEDNIEJ POZYCJI DO OBROTU
void Blocks:: changePosition(Blocks* Nowy, int posit)
{
	if(posit==1)
	{
		Nowy->Position1();
		Blocks::position+=1;
		for(int i=0; i<4; i++)
		{
			if(Nowy->returnPosition('x',i)>270 || Nowy->returnPosition('x',i)<90 || Nowy->returnPosition('y',i)>540)
			{
				Nowy->Position4();
				Blocks::position=4;
			}
		}
	}
	else if(posit==2)
	{
		Nowy->Position2();
		Blocks::position+=1;
		for(int i=0; i<4; i++)
		{
			if(Nowy->returnPosition('x',i)>270 || Nowy->returnPosition('x',i)<90 || Nowy->returnPosition('y',i)>540)
			{
				Nowy->Position1();
				Blocks::position-=1;
			}
		}
	}
	else if(posit==3)
	{
		Nowy->Position3();
		Blocks::position+=1;
		for(int i=0; i<4; i++)
		{
			if(Nowy->returnPosition('x',i)>270 || Nowy->returnPosition('x',i)<90 || Nowy->returnPosition('y',i)>540)
			{
				Nowy->Position2();
				Blocks::position-=1;
			}
		}
	}
	else 
	{
		Nowy->Position4();
		Blocks::position=1;
		for(int i=0; i<4; i++)
		{
			if(Nowy->returnPosition('x',i)>270 || Nowy->returnPosition('x',i)<90 || Nowy->returnPosition('y',i)>540)
			{
				Nowy->Position3();
				Blocks::position-=1;
			}
		}
	}
}

//PORUSZANIE AUTOMATYCZNE I SPRAWDZENIE DO£U, GÓRY
bool Blocks:: Auto(Blocks* Nowy, GameMap* mapka, int& opoznienie, bool& end, int points, int gamenumbers)
{
	int spr=1;
	if(points==300)
	{
		if(speed==10)
		{
			speed-=5;
			opoznienie=0;
		}
	}
		//Sprawdzamy, czy minê³o wystarczaj¹co czasu
		if(opoznienie==0)
		{
			for(int i=0; i<4; i++)
			{
				if(Nowy->returnPosition('y', i)+20>540)
					spr=0;
			}
			if(spr==1)
				for(int i=0; i<4; i++)
				{
					AutoMove(i, true);
				}
		}
		else if(opoznienie==speed)
		{
			opoznienie=0;
			return false;
		}
		
		//Sprawdzamy, czy obiekt nie wychodzi poza planszê
		
		opoznienie+=1;

	for(int i=0; i<10; i++)
	{
		for(int j=0; j<=20; j++)
		{
			for(int k=0; k<4; k++)
			{
				bool check = mapka->CheckSpace(i,j);
				if(check==true && (Nowy->returnPosition('x',k)-90)/constant_twenty==i && (Nowy->returnPosition('y',k)-140)/constant_twenty==j)
				{
					for(int l=0; l<4; l++)
					{
						AutoMove(l, false);
					}

					for(int i=0; i<4; i++)
					{
						//std::cout<<posX<<" "<<posY<<std::endl;
						int speciall=special;
						//if(
						if(i!=special)
							speciall=4;
						mapka->AddBlocks(Nowy->returnPosition('x', i), Nowy->returnPosition('y', i), speciall, mess, gamenumbers);
					}
					for(int l=0; l<4; l++)
					{
						if(Nowy->returnPosition('y',l)+20<=140)
						end=true;
					}
					return true;
				}
			}
		}
	}

	
	return false;
}
bool Blocks:: BottomCheck(Blocks* Nowy, GameMap* mapka, int opoznienie, int gamenumbers)
{
	bool spr, spr1=false;

	for(int i=0; i<4; i++)
	{
		(Nowy->returnPosition('y',i)+20)>540 ? spr=true : spr=false;
		if(spr==true)
		{
			std::cout<<"TRUE"<<std::endl;
			break;
		}
	}

	if(opoznienie==0 && spr==true)
	{
		for(int i=0; i<4; i++)
		{
			int speciall=special;
			if(i!=special)
				speciall=4;
			mapka->AddBlocks(Nowy->returnPosition('x', i), Nowy->returnPosition('y', i), speciall, mess, gamenumbers);
		}
		return true;
	}
	else 
		return false;
}
