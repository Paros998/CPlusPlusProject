#pragma once
#include "Biblioteki.h"

class Menu
{
	Texture menuTekstura,logoTekstura,strzalkaTekstura;
	Sprite menuSprite,logoSprite,strzalkaSprite;
	Text *tablicaText;
	Music menuAmbient; 
	Sound menuWybor,menuZatwierdzMenu;
	SoundBuffer bufor,bufor2;
	Font czcionka;
	IntRect obszar;
	int kierunekTla,Wybor;
public:
	Menu();
	~Menu();
	bool start(RenderWindow& okno);

private:
	void poruszajTlo();
	void rysuj(RenderWindow& okno);
	void aktualizacjaMenu();
	void ruchMyszka(int,int);
	void klikMyszka(int,int, RenderWindow& okno);
	void enter(int,RenderWindow& okno);
};

