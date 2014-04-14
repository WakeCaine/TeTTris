#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>

int main()
{
	
	//rÛøne sposoby wywo≥ania okna w SFML
    //(1)->>>   sf::Window oknoAplikacji( sf::VideoMode( 800, 600, 32 ), "Okienko" );
	//(2)->>>   sf::Window oknoAplikacji;
	//			oknoAplikacji.create( sf::VideoMode( 800, 600, 32 ), "Kurs SFML 2.0 - http://cpp0x.pl" );
	//(3)->>> (PE£EN EKRAN) sf::Window oknoAplikacji( sf::VideoMode( 800, 600, 32 ), "Kurs SFML 2.0 - http://cpp0x.pl", sf::Style::Fullscreen );

	//TWORZENIE G£”WNEGO OKNA
	//sf::Window oknoAplikacji; --> NORMALNE OKIENKO
	sf::RenderWindow oknoAplikacji; //--->OKNO DO RENDEROWANIA 2D
	oknoAplikacji.create( sf::VideoMode( 800, 600, 32 ), "TeTTris");
	oknoAplikacji.setFramerateLimit(1000);
	oknoAplikacji.setVerticalSyncEnabled(true);
	sf::Clock Clock;
	while( oknoAplikacji.isOpen() )
	{
		
		oknoAplikacji.clear( sf::Color( 255, 50, 255 ) );
		//OBSLUGA ZDARZEN- KLAWIATURA, MYSZKA ETC.
		sf::Event zdarzenie;
		while (oknoAplikacji.pollEvent(zdarzenie))
		{
			if( zdarzenie.type == sf::Event::Closed )
			{
				oknoAplikacji.close();
			}
			//PRZYK£ADY DOT. ZAMYKANIA OKNA APLIKACJI
			if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
			{
				oknoAplikacji.close();
			}

			if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
			{
				oknoAplikacji.close();
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				//PO£OØENIE MYSZKI WZGL DEM OKNA I CA£EJ ROèDZIELCZOåCI
				sf::Vector2i pozycja= sf::Mouse::getPosition(oknoAplikacji);
				std::cout<<"X: "<<pozycja.x<<std::endl;
				std::cout<<"Y: "<<pozycja.y<<std::endl;
			}
		}

		sf::Texture obrazek,obrazek1;
		bool ladowanie=obrazek.loadFromFile("not.png");
		bool lad1=obrazek1.loadFromFile("block.png");
		if(ladowanie==true)
		{
			sf::Sprite sprit,sprit2;
			//obrazek.setRepeated(true);---->>> POWTARZANIE TEKSTURY
			sprit.setTexture(obrazek);
			sprit2.setTexture(obrazek);
			sprit.setPosition(50, 50);
			sprit2.setPosition(50, 150);
			//sprit.setTextureRect(sf::IntRect( 0, 0, 800, 600)); -->> USTAWIANIE PRZESTRZENI, KT”RA B DZIE WYPE£NIONA POWTARZAJ•C• SI  TEKSTUR•
			//sprit.move(50,50); --->PRZESUNIECIE Z AKTUALNEJ POZYCJI
			//sprit.setRotation(100); --> ROTACJA SPRITE
			//sprit.rotate(180); -->ROTACJA Z OBECNEGO POLOØENIA
			//sprit.setScale(2,2);
			//sprit.getScale();
			sprit2.scale(2,2);
			sprit.setOrigin(50, 50);
			sprit2.setOrigin(50, 50);
			sprit2.setColor(sf::Color(0, 255, 0, 100)); //---> MOØNA ZMIENIA KOLOR SPRITE
			//sprit.setRotation(180);

			oknoAplikacji.draw(sprit);
			oknoAplikacji.draw(sprit2);
			
		}

		sf::Font czcionka;
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
		}
		
		sf::Time Time = Clock.getElapsedTime();
		float tim=Time.asMilliseconds();
		Clock.restart();
		std::cout<<"CZAS: "<<tim<<std::endl;
		oknoAplikacji.display();
	}
	_getch();
    return 0;
}