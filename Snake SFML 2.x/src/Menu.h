#pragma once
#include "Biblioteki.h"

class Menu
{
	Texture menuTekstura;
	Sprite menuSprite;
	int kierunekTla;
public:
	Menu();
	bool start(RenderWindow& okno);

private:
	void poruszajTlo();
	void rysuj(RenderWindow& okno);
};

