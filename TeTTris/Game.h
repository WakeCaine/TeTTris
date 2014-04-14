#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio\Music.hpp>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include "HClasses\Blocks.h"
#include "HClasses\ClassicSTR.h"
#include "HClasses\Block_I.h"
#include "HClasses\Block_Z.h"
#include "HClasses\Block_Q.h"
#include "HClasses\Block_L.h"
#include "HClasses\Block_T.h"


class Game
{
	sf::Sprite sprit[31];
	sf::Texture obrazek;
	int points, opoznienie;
	bool nowyklocek;
	bool end;
	sf::Font czcionka;
	sf::Text costam;
	
public:
	int TGmusic;
	sf::Music Gmusic;
	Game();
	int PlayGmusic();
	Blocks* randomizeblock(sf::RenderWindow&, int&);
	int returnLatency(int latency)
	{
		return latency;
	}
	void Visualise(GameMap* mapka, sf::RenderWindow& okno, Blocks* NextNowy);
	void Running();
	void ActualGameI(sf::RenderWindow&, Blocks*, Blocks*, GameMap*, int&, bool&, int);
	void ActualGameII(sf::RenderWindow&, Blocks*, Blocks*, GameMap*, int&, bool&, int);
	void EventsCheck(sf::RenderWindow& oknoAplikacji, Blocks* Nowy, GameMap*, int&, bool&);
	void EndGame(bool end)
	{
		if(end==true)
		{
			std::cout<<"END";
		}
	}
	~Game();
};

