#include "Game.h"
#include "HClasses\GameMap.h"
#include "HClasses\Blocks.h"
#include "TWindows.h"
#include <iostream>
#include <string>
#include <SFML/System.hpp>
using namespace std;

Game::Game()
{
	srand(unsigned(time(NULL)));
	nowyklocek=true;
	obrazek.loadFromFile("TETTRISBLOCKS1.png");
	points=0;
	opoznienie=0;
}

int Game :: PlayGmusic()
{
	bool lad=true;
	if (!Gmusic.openFromFile("chip.wav"))
	{
		std::cout<<"BRAK MUZYKI"<<std::endl;
		return -1;
	}
		Gmusic.setVolume(20);
		Gmusic.setLoop(true);
		Gmusic.play();
		return 0;
}

Blocks* Game:: randomizeblock(sf::RenderWindow& okno, int& type)
{
	bool repeat;
	do
	{
	repeat=false;

	int randomize=rand()%100+1;
	if(randomize>=1 && randomize<20)
	{
		if(type!=1)
		{
		type=1;
		return new Block_T(okno);
		}
		else
			repeat=true;
	}
	else if(randomize>=20 && randomize<40)
	{
		if(type!=2)
		{
			type=2;
			return new Block_Z(okno);
		}
		else
			repeat=true; 
	}
	else if(randomize>=40 && randomize<60)
	{
		if(type!=3)
		{
			type=3;
			return new Block_L(okno);
		}
		else
			repeat=true;
	}
	else if(randomize>=60 && randomize<80)
	{
		if(type!=4)
		{
		type=4;
		return new Block_Q(okno);
		}
		else
			repeat=true;
	}
	else 
	{
		if(type!=5)
		{
		type=5;
		return new Block_I(okno);
		}
		else
			repeat=true;
	}
	}while(repeat==true);
}

void Game :: EventsCheck(sf::RenderWindow& oknoAplikacji, Blocks* Nowy, GameMap* mapka, int& opoznienie, bool& skip)
{
	sf::Event zdarzenie;
	obrazek.loadFromFile("TETTRISBLOCKS1.png");
	while (oknoAplikacji.pollEvent(zdarzenie))
			{
				if( zdarzenie.type == sf::Event::Closed )
					{
						if(TGmusic!=-1)
								Gmusic.stop();
						oknoAplikacji.close();//zamykanie aplikacji ,,X"
						
					}
				else if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Space)
					{
						TWindows* Resume= new TWindows();
						Resume->ResumeMenu(oknoAplikacji, skip, Gmusic, TGmusic);//zamykanie przez ,,ESC"
					}
				else if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
					{

								Gmusic.stop();
						oknoAplikacji.close(); //zamykanie przez úrodkowy przycisk myszki
					}
				else if(zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::P)
					{
						//PO£OØENIE MYSZKI WZGL DEM OKNA I CA£EJ ROèDZIELCZOåCI
						sf::Vector2i pozycja= sf::Mouse::getPosition(oknoAplikacji);
						std::cout<<"X: "<<pozycja.x<<std::endl;
						std::cout<<"Y: "<<pozycja.y<<std::endl;
					}
				else if(zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::R)
					Nowy->RotateR(Nowy, mapka);
				else if(zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::PageUp)
					{
						opoznienie=0;
						Nowy->increase(returnLatency(opoznienie), opoznienie);
					}
				else if(zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::PageDown)
					Nowy->decrease();
				else
					Nowy->Move(mapka);
			}
}

void Game :: Visualise(GameMap* mapka, sf::RenderWindow& okno, Blocks* NextNowy)
{
	NextNowy->PositionX();
	NextNowy->Draw();

	for(int i=0; i<10; i++)
	{
		for(int j=0; j<=20; j++)
		{
			bool check = mapka->CheckSpace(i,j);
			int blocktype = mapka->CheckType(i,j);
			if(check==true)
			{
				sprit[i+j].setTexture(obrazek);
				sprit[i+j].setColor(sf::Color(30,144,255));
				if(blocktype==1)
					sprit[i+j].setColor(sf::Color(30,144,255));
				else if(blocktype==2)
					sprit[i+j].setColor(sf::Color(255,255,0));
				else if(blocktype==3)
					sprit[i+j].setColor(sf::Color(25,25,112));
				sprit[i+j].setPosition((i*20)+90, ((j*20)+140));
				sprit[i+j].setScale(5,5);
				sprit[i+j].setOrigin(2,2);
				okno.draw(sprit[i+j]);
			}


		}
	}

			sf::Font czcionka;
		    sf::Text costam;
			if(czcionka.loadFromFile("arial.ttf"))
			{	
				costam.setFont(czcionka);
				//PUNKTY NA PLANSZY
				costam.setString("POINTS: ");
				costam.setCharacterSize(40);
				//costam.setStyle(sf::Text::Bold);
				costam.setPosition(375, 50);
				costam.setScale(1,1);
				costam.setColor(sf::Color(255,255,255)); 
				okno.draw(costam);

				char* literka = new char[10];
				sprintf(literka, "%d", points);
				costam.setString(literka);
				costam.setCharacterSize(45);
				//costam.setStyle(sf::Text::Bold);
				costam.setPosition(680, 45);
				costam.setScale(1,1);
				costam.setColor(sf::Color(255,255,255)); 
				okno.draw(costam);
			}

}

void Game:: Running()
{
	bool skip=true;
	int option=1;
	sf::Clock ClockHead;
	sf::RenderWindow oknoAplikacji;
	oknoAplikacji.create( sf::VideoMode( 800, 600, 32 ), "TeTTris"); //OKNO APLIKACJI
	oknoAplikacji.setVerticalSyncEnabled(false);
	oknoAplikacji.setFramerateLimit(0);
	oknoAplikacji.setMouseCursorVisible(false);
	int type, type1;
	Blocks* Nowy=randomizeblock(oknoAplikacji, type);
	Nowy->addType(type);
	Blocks* NextNowy=randomizeblock(oknoAplikacji, type);
	NextNowy->addType(type);
	//P TLA APLIKACJI
	GameMap* mapka=new GameMap();
	TWindows* Mmenus= new TWindows();
	while(skip==true){
		skip=false;
		Mmenus->TitleMenu(oknoAplikacji, end, points);
		if(end==true)
		{
			break;
		}
		Mmenus->OptionMenu(oknoAplikacji, end, points, option);

		TGmusic=PlayGmusic();		
		
		if(option==1)
		{
			Nowy->gamenumber=1;
			ActualGameI(oknoAplikacji, Nowy, NextNowy, mapka, opoznienie, skip, 1);
		}
		else if(option==2)
		{
			Nowy->gamenumber=2;
			Mmenus->Tips(oknoAplikacji);
			ActualGameII(oknoAplikacji, Nowy, NextNowy, mapka, opoznienie, skip, 2);
		}
		Mmenus->EndMenu(oknoAplikacji, skip, points);
	}
	delete Nowy;
	delete NextNowy;
}

void Game:: ActualGameI(sf::RenderWindow& oknoAplikacji, Blocks* Nowy, Blocks* NextNowy, GameMap* mapka, int& opoznienie, bool& skip, int gamenumbers)
{
	TGmusic=PlayGmusic();
	nowyklocek=true;
	while(nowyklocek==true)
	{
		Nowy->gamenumber=gamenumbers;
		NextNowy->gamenumber=gamenumbers;
		if(points>300)
		{
			if(Nowy->retrunspeed()>1)
			{
				Nowy->increase(returnLatency(opoznienie), opoznienie);
				opoznienie=0;
			}
		}
		// G£”WNA P TLA RYSUJ•CA
		while( oknoAplikacji.isOpen() )
		{
			//SPR.CZAS	
			sf::Clock Clock;
			//CZYSZCZENIE OKNA
			oknoAplikacji.clear(sf::Color( 10, 10, 10 ));
			sf::Texture tlo;
			bool tlolad=tlo.loadFromFile("tlo.png");
			if(tlolad==true)
			{
				sf::Sprite sprit1;
				sprit1.setColor(sf::Color(255, 255, 255, 25));
				sprit1.setPosition(0,0);
				sprit1.setTexture(tlo);
				sprit1.setScale(10,10);
				oknoAplikacji.draw(sprit1);
			}

			EndGame(end);
			if(end==true)
			{
				nowyklocek=false;
				mapka->Clear();
				oknoAplikacji.clear();
				break;
			}
			if(nowyklocek==true)
				{
					Nowy->Reset();
					nowyklocek=false;
				}
			
			

			mapka->CheckLine(points, nowyklocek, gamenumbers);
			Visualise(mapka, oknoAplikacji, NextNowy);
		

			//CZYSZCZENIE OKNA
			//oknoAplikacji.clear( sf::Color( 10, 10, 10 ));

			//OBSLUGA ZDARZEN- KLAWIATURA, MYSZKA ETC.
			EventsCheck(oknoAplikacji, Nowy, mapka, opoznienie, skip);

			//RYSOWANIE INTERFEJSU+KLOCKA
			sf::Texture obrazek1;
			bool ladowanie1=obrazek1.loadFromFile("interfejs3.png");
			if(ladowanie1==true)
			{
				Nowy->Draw();
				sf::Sprite sprit1;
				sprit1.setPosition(0,0);
				sprit1.setTexture(obrazek1);
				sprit1.setScale(10,10);
				oknoAplikacji.draw(sprit1);
			}

			bool sprawdz1=Nowy->Auto(Nowy, mapka, opoznienie, end, points, gamenumbers);
			//SPRAWDZENIE ELEMENTU
			bool sprawdz=Nowy->BottomCheck(Nowy, mapka, opoznienie, gamenumbers);
			if(sprawdz==true || sprawdz1==true)
			{
				nowyklocek=true;
				int typeb=Nowy->returnType();
				Nowy=NextNowy;
				NextNowy=randomizeblock(oknoAplikacji, typeb);
				NextNowy->addType(typeb);
				break;
			}
			
			//SPRAWDZENIE CZASU/FPS
			//sf::Time Time = Clock.getElapsedTime();
			//float tim=Time.asSeconds();
			Clock.restart();
			//std::cout<<"CZAS: "<<tim<<std::endl;

			//WYåWIETLANIE OKNA
			oknoAplikacji.display();
			if(skip==true)
			{
				points=0;
				nowyklocek=false;
				mapka->Clear();
				oknoAplikacji.clear();
				break;
				
			}
		}
	}
	Nowy->resetspeed();

	if(TGmusic!=-1)
	{
		Gmusic.stop();
	}
}

void Game:: ActualGameII(sf::RenderWindow& oknoAplikacji, Blocks* Nowy, Blocks* NextNowy, GameMap* mapka, int& opoznienie, bool& skip, int gamenumbers)
{
	TGmusic=PlayGmusic();
	nowyklocek=true;
	while(nowyklocek==true)
	{
		Nowy->gamenumber=gamenumbers;
		NextNowy->gamenumber=gamenumbers;
		if(points>300)
		{
			if(Nowy->retrunspeed()>1)
			{
				Nowy->increase(returnLatency(opoznienie), opoznienie);
				opoznienie=0;
			}
		}
		// G£”WNA P TLA RYSUJ•CA
		while( oknoAplikacji.isOpen() )
		{
			//SPR.CZAS	
			sf::Clock Clock;
			//CZYSZCZENIE OKNA
			oknoAplikacji.clear(sf::Color( 10, 10, 10 ));
			sf::Texture tlo;
			bool tlolad=tlo.loadFromFile("tlo.png");
			if(tlolad==true)
			{
				sf::Sprite sprit1;
				sprit1.setColor(sf::Color(255, 255, 255, 25));
				sprit1.setPosition(0,0);
				sprit1.setTexture(tlo);
				sprit1.setScale(10,10);
				oknoAplikacji.draw(sprit1);
			}

			EndGame(end);
			if(end==true)
			{
				nowyklocek=false;
				mapka->Clear();
				oknoAplikacji.clear();
				break;
			}
			if(nowyklocek==true)
				{
					Nowy->Reset();
					nowyklocek=false;
				}
			
			

			mapka->CheckLine(points, nowyklocek, gamenumbers);
			Visualise(mapka, oknoAplikacji, NextNowy);
		

			//CZYSZCZENIE OKNA
			//oknoAplikacji.clear( sf::Color( 10, 10, 10 ));

			//OBSLUGA ZDARZEN- KLAWIATURA, MYSZKA ETC.
			EventsCheck(oknoAplikacji, Nowy, mapka, opoznienie, skip);

			//RYSOWANIE INTERFEJSU+KLOCKA
			sf::Texture obrazek1;
			bool ladowanie1=obrazek1.loadFromFile("interfejs3.png");
			if(ladowanie1==true)
			{
				Nowy->Draw();
				sf::Sprite sprit1;
				sprit1.setPosition(0,0);
				sprit1.setTexture(obrazek1);
				sprit1.setScale(10,10);
				oknoAplikacji.draw(sprit1);
			}

			bool sprawdz1=Nowy->Auto(Nowy, mapka, opoznienie, end, points, gamenumbers);
			//SPRAWDZENIE ELEMENTU
			bool sprawdz=Nowy->BottomCheck(Nowy, mapka, opoznienie, gamenumbers);
			if(sprawdz==true || sprawdz1==true)
			{
				nowyklocek=true;
				int typeb=Nowy->returnType();
				Nowy=NextNowy;
				NextNowy=randomizeblock(oknoAplikacji, typeb);
				NextNowy->addType(typeb);
				break;
			}
			
			//SPRAWDZENIE CZASU/FPS
			//sf::Time Time = Clock.getElapsedTime();
			//float tim=Time.asSeconds();
			Clock.restart();
			//std::cout<<"CZAS: "<<tim<<std::endl;
			
			//if(nowyklocek==true)
				mapka->CheckGravity();

			//WYåWIETLANIE OKNA
			oknoAplikacji.display();
			if(skip==true)
			{
				points=0;
				nowyklocek=false;
				mapka->Clear();
				oknoAplikacji.clear();
				break;
				
			}
			
		}
	}
	Nowy->resetspeed();

	if(TGmusic!=-1)
	{
		Gmusic.stop();
	}
}

Game::~Game()
{
	
}

/*sf::Font czcionka;
		if(czcionka.loadFromFile("arial.ttf"))
		{
			sf::Text costam;
			costam.setFont(czcionka);
			costam.setString("WITAM");
			costam.setCharacterSize(8);
			//costam.setStyle(sf::Text::Bold | sf::Text::Underlined);
			costam.setPosition(300, 300);
			costam.setScale(6,6);
			oknoAplikacji.draw(costam);
		}*/