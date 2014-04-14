#pragma once
#include "game.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
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


class TWindows :
	public Game
{
	int tribe, option, Tmusic;
public:
	sf::Music musicTetris;
	int PlayMusic();
	void TitleMenu(sf::RenderWindow&, bool&, int&);
	void OptionMenu(sf::RenderWindow&, bool&, int&, int&);
	void Tips(sf::RenderWindow&);
	void ResumeMenu(sf::RenderWindow&, bool&, sf::Music&, int);
	void EventsWin(sf::RenderWindow&, int&, int&, bool&, int);
	void EndMenu(sf::RenderWindow&, bool&, int);

	TWindows(void);
	~TWindows(void);
};

