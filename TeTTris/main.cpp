#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include "Game.h"
#include <time.h>

int main()
{
	srand(unsigned(time(NULL)));
	Game* NewGame=new Game();
	NewGame->Running();
	_getch();
    return 0;
}