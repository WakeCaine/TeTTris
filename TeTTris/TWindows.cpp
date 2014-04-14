#include "TWindows.h"

//----------------------------------------------------------------------
TWindows::TWindows()
{
	option=0;
	tribe=0;
}
//----------------------------------------------------------------------

int TWindows:: PlayMusic()
{
	bool lad=true;
	if (!musicTetris.openFromFile("Path.wav"))
	{
		std::cout<<"BRAK MUZYKI"<<std::endl;
		return -1;
	}
		musicTetris.setVolume(10);
		musicTetris.setLoop(true);
		musicTetris.play();
		return 0;
}

void TWindows :: EventsWin(sf::RenderWindow& oknoAplikacji, int& tribe, int& option, bool& skip, int variation)
{
	sf::Event zdarzenie;
	while (oknoAplikacji.pollEvent(zdarzenie))
			{
				if( zdarzenie.type == sf::Event::Closed )
					{
						oknoAplikacji.close();//zamykanie aplikacji ,,X"
					}
				//WYBORY W MENU G£ÓWNYM I W PAUSE
				else if(zdarzenie.type == sf::Event::KeyPressed && (zdarzenie.key.code == sf::Keyboard::Up || zdarzenie.key.code == sf::Keyboard::Down) && variation!=9 )
					{
						if(variation==3)
						{
							if(option==0 && zdarzenie.key.code == sf::Keyboard::Down)
								option=1;
							else if(option==0 && zdarzenie.key.code == sf::Keyboard::Up)
								option=2;
							else if(option==1 && zdarzenie.key.code == sf::Keyboard::Down)
								option=2;
							else if(option==1 && zdarzenie.key.code == sf::Keyboard::Up)
								option=0;
							else if(option==2 && zdarzenie.key.code == sf::Keyboard::Down)
								option=0;
							else if(option==2 && zdarzenie.key.code == sf::Keyboard::Up)
								option=1;
						}
						else
						{
							if(option==0)
								option=1;
							else if(option==1)
								option=0;
						}
					}
					
				//WYJŒCIE Z MENU
				else if(zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Space)
					if(variation==0)
					{
						if(option==0)
							tribe=1;
						else{
							if(Tmusic!=-1)
								{
									musicTetris.stop();
									musicTetris.~Music();
								}
							skip=true;
							
						}
					}
					else if(variation==1)
					{
						if(option==0)
							tribe=1;
						else
							skip=true;
					}
					else if(variation==2)
					{
						if(option==0)
							skip=true;
						else
							tribe=1;
					}
					else if(variation==3)
					{
						if(option==0)
							tribe=1;
						else if(option==1)
							tribe=2;
						else if(option==2)
						{
							tribe=3;
						}
					}
					else if(variation==9)
						option=0;
						
			}
}

void TWindows:: TitleMenu(sf::RenderWindow& oknoAplikacji, bool& end, int& points)
{
	Tmusic=PlayMusic();
	//tribe=0;
	points=0;
	end=false;
	while( oknoAplikacji.isOpen() )
	{
		bool fake=false;
		//CZYSZCZENIE OKNA
		oknoAplikacji.clear(sf::Color( 0, 0, 0));

		sf::Texture tlo;
			bool tlolad=tlo.loadFromFile("tlo.png");
			if(tlolad==true)
			{
				sf::Sprite sprit1;
				sprit1.setColor(sf::Color(255, 255, 255, 20));
				sprit1.setPosition(0,0);
				sprit1.setTexture(tlo);
				sprit1.setScale(10,10);
				oknoAplikacji.draw(sprit1);
			}

		EventsWin(oknoAplikacji, tribe, option, fake, 0);
		if(fake==true)
		{
			end=true;
			break;
		}
			sf::Texture text;
				bool maintext=text.loadFromFile("napis.png");
				if(maintext==true)
				{
					sf::Sprite tetris;
					tetris.setColor(sf::Color(255,255 , 255));
					tetris.setPosition(135,75);
					tetris.setTexture(text);
					tetris.setScale(5,5);
					oknoAplikacji.draw(tetris);
				}

			sf::Font czcionka;
			sf::Text costam;
			if(czcionka.loadFromFile("XG-pixo.ttf"))
			{
				costam.setFont(czcionka);

			//TEXT W MENU TYTULOWYM
				costam.setString("START");
				costam.setCharacterSize(20);
				//costam.setStyle(sf::Text::Bold);
				costam.setPosition(320, 350);
				costam.setScale(2,2);
				if(option==0)
					{
						costam.setColor(sf::Color(125,125,125)); 
					}
				else 
					{
						costam.setColor(sf::Color(255,255,255)); 
					}
				oknoAplikacji.draw(costam);

				costam.setString("EXIT");
				if(option==0)
					{
						costam.setColor(sf::Color(255,255,255)); 
					}
				else 
					{
						costam.setColor(sf::Color(125,125,125)); 
					}
				costam.setPosition(340, 400);
				oknoAplikacji.draw(costam);
			
			}
		oknoAplikacji.display();
		if(tribe==1)
			break;
		
	}
	oknoAplikacji.clear(sf::Color( 10, 10, 10 ));
	option=0;
}

void TWindows:: OptionMenu(sf::RenderWindow& oknoAplikacji, bool& end, int& points, int& options)
{
	tribe=0;
	points=0;
	end=false;
	while( oknoAplikacji.isOpen() )
	{
		bool fake=true;
		//CZYSZCZENIE OKNA
		oknoAplikacji.clear(sf::Color( 0, 0, 0));
		EventsWin(oknoAplikacji, tribe, option, fake, 3);

		sf::Texture text;
			bool maintext=text.loadFromFile("napis.png");
			if(maintext==true)
			{
				sf::Sprite tetris;
				tetris.setColor(sf::Color(255, 255, 255));
				tetris.setPosition(135,75);
				tetris.setTexture(text);
				tetris.setScale(5,5);
				oknoAplikacji.draw(tetris);
			}

			sf::Texture tlo;
			bool tlolad=tlo.loadFromFile("tlo.png");
			if(tlolad==true)
			{
				sf::Sprite sprit1;
				sprit1.setColor(sf::Color(255, 255, 255, 20));
				sprit1.setPosition(0,0);
				sprit1.setTexture(tlo);
				sprit1.setScale(10,10);
				oknoAplikacji.draw(sprit1);
			}


		sf::Font czcionka;
		sf::Text costam;
		if(czcionka.loadFromFile("XG-pixo.ttf"))
		{
			costam.setFont(czcionka);

		//NORMAL MODE
			costam.setString("NORMAL MODE");
			costam.setCharacterSize(20);
			//costam.setStyle(sf::Text::Bold);
			costam.setPosition(215, 300);
			costam.setScale(2,2);
			if(option==0)
			{
				costam.setColor(sf::Color(125,125,125)); 
			}
			else
			{
				costam.setColor(sf::Color(255,255,255)); 
			}
			oknoAplikacji.draw(costam);

			//GRAVITY MODE
			costam.setString("GRAVITY MODE");
			costam.setCharacterSize(20);
			//costam.setStyle(sf::Text::Bold);
			costam.setPosition(215, 350);
			costam.setScale(2,2);
			if(option==1)
			{
				costam.setColor(sf::Color(125,125,125)); 
			}
			else 
			{
				costam.setColor(sf::Color(255,255,255)); 
			}
			oknoAplikacji.draw(costam);

			costam.setString("EXIT");
			if(option==2)
			{
				costam.setColor(sf::Color(125,125,125)); 	
			}
			else 
			{
				costam.setColor(sf::Color(255,255,255)); 
			}
			costam.setPosition(340, 425);
			oknoAplikacji.draw(costam);
			
		}
		oknoAplikacji.display();
		if(tribe==1 || tribe==2 || tribe==3)
		{
			options=tribe;
			option=0;
			break;
		}
	}
	oknoAplikacji.clear(sf::Color( 10, 10, 10 ));
	option=0;
	if(Tmusic!=-1)
	{
		musicTetris.stop();
	}
}

void TWindows:: Tips(sf::RenderWindow& oknoAplikacji)
{
	//tribe=0;
	option=1;
	while( oknoAplikacji.isOpen() )
	{
		bool fake=false;
		//CZYSZCZENIE OKNA
		oknoAplikacji.clear(sf::Color( 0, 0, 0));

		sf::Texture tlo;
			bool tlolad=tlo.loadFromFile("tlo.png");
			if(tlolad==true)
			{
				sf::Sprite sprit1;
				sprit1.setColor(sf::Color(255, 255, 255, 20));
				sprit1.setPosition(0,0);
				sprit1.setTexture(tlo);
				sprit1.setScale(10,10);
				oknoAplikacji.draw(sprit1);
			}

			tlolad=tlo.loadFromFile("spacja.png");
			if(tlolad==true)
			{
				sf::Sprite sprit1;
				sprit1.setPosition(0,0);
				sprit1.setTexture(tlo);
				oknoAplikacji.draw(sprit1);
			}

		EventsWin(oknoAplikacji, tribe, option, fake, 9);
		if(option==0)
			break;
		oknoAplikacji.display();
	}
	oknoAplikacji.clear(sf::Color( 10, 10, 10 ));
	option=0;
}

void TWindows :: ResumeMenu(sf::RenderWindow& oknoAplikacji, bool& skip, sf::Music& Gmusic, int TGmusic)
{
	while( oknoAplikacji.isOpen() )
	{
		//CZYSZCZENIE OKNA
		EventsWin(oknoAplikacji, tribe, option, skip, 1);
		if(skip==true)
			if(TGmusic!=-1)
			{
				Gmusic.stop();
			}
		sf::Texture textur;
			bool viewtext=textur.loadFromFile("tloczarne.png");
			if(viewtext==true)
			{
				sf::Sprite blackpic;
				blackpic.setColor(sf::Color(0, 0, 0, 125));
				blackpic.setTexture(textur);
				blackpic.setScale(10,10);
				oknoAplikacji.draw(blackpic);
			}

		sf::Font czcionka;
		sf::Text costam,costam1, costam2;
		if(czcionka.loadFromFile("XG-pixo.ttf"))
		{
			costam.setFont(czcionka);
		//TEXT W MENU TYTULOWYM
			costam.setString("*PAUSE*");
			costam.setCharacterSize(60);
			//costam.setStyle(sf::Text::Bold);
			costam.setPosition(100, 50);
			costam.setScale(2,2);
			costam.setColor(sf::Color(255,255,255)); 
			oknoAplikacji.draw(costam);

			//RESUME
			costam.setString("RESUME");
			costam.setCharacterSize(20);
			//costam.setStyle(sf::Text::Bold);
			costam.setPosition(295, 300);
			costam.setScale(2,2);
			if(option==0)
			{
				costam.setColor(sf::Color(125,125,125)); 
			}
			else 
			{
				costam.setColor(sf::Color(255,255,255)); 
			}
			oknoAplikacji.draw(costam);

			//EXIT
			costam.setString("EXIT");
			if(option==0)
			{
				costam.setColor(sf::Color(255,255,255)); 
			}
			else 
			{
				costam.setColor(sf::Color(125,125,125)); 
			}
			costam.setPosition(340, 350);
			oknoAplikacji.draw(costam);
			
		}
		oknoAplikacji.display();
		if(tribe==1 || skip==true)
			break;
	}
	oknoAplikacji.clear(sf::Color( 10, 10, 10 ));
	tribe=0;
	option=0;
}

void TWindows:: EndMenu(sf::RenderWindow& oknoAplikacji, bool& skip, int points)
{
	Tmusic=PlayMusic();
	tribe=0;
	option=0;
	if(skip!=true)
	{
		while( oknoAplikacji.isOpen() )
		{
			oknoAplikacji.clear(sf::Color( 0, 0, 0));
			EventsWin(oknoAplikacji, tribe, option, skip, 2);
			sf::Font czcionka;
			sf::Text costam;
			if(czcionka.loadFromFile("XG-pixo.ttf"))
			{
				costam.setFont(czcionka);
			//TEXT W MENU TYTULOWYM
				costam.setString("THE END");
				costam.setCharacterSize(60);
				//costam.setStyle(sf::Text::Bold);
				costam.setPosition(100, 50);
				costam.setScale(2,2);
				costam.setColor(sf::Color(255,255,255)); 
				oknoAplikacji.draw(costam);

				//YOUR SCORE
				costam.setString("YOUR SCORE:");
				costam.setCharacterSize(20);
				//costam.setStyle(sf::Text::Bold);
				costam.setPosition(250, 170);
				costam.setScale(2,2);
				costam.setColor(sf::Color(255,255,255)); 
				oknoAplikacji.draw(costam);

				//POINTS
				char* literka = new char[10];
				sprintf(literka, "%d", points);
				costam.setString(literka);
				costam.setCharacterSize(20);
				//costam.setStyle(sf::Text::Bold);
				costam.setPosition(500, 230);
				costam.setScale(2,2);
				costam.setColor(sf::Color(255,255,255)); 
				oknoAplikacji.draw(costam);

				//TITLE MENU
				costam.setString("TITLE MENU");
				costam.setCharacterSize(20);
				//costam.setStyle(sf::Text::Bold);
				costam.setPosition(250, 300);
				costam.setScale(2,2);
				if(option==0)
				{
					costam.setColor(sf::Color(125,125,125)); 
				}
				else 
				{
					costam.setColor(sf::Color(255,255,255)); 
				}
				oknoAplikacji.draw(costam);

				//EXIT
				costam.setString("EXIT");
				if(option==0)
				{
					costam.setColor(sf::Color(255,255,255)); 
				}
				else 
				{
					costam.setColor(sf::Color(125,125,125)); 
				}
				costam.setPosition(340, 350);
				oknoAplikacji.draw(costam);
				
			}
			oknoAplikacji.display();
			if(tribe==1 || skip==true)
				break;
		}
		oknoAplikacji.clear(sf::Color( 10, 10, 10 ));
		tribe=0;
		option=0;
	}
}

//----------------------------------------------------------------------
TWindows::~TWindows()
{
	/*music.~Music();
	music.*/
}
