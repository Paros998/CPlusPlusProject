#pragma once
#include "Biblioteki.h"

class Menu
{
	Texture menuTekstura,logoTekstura,strzalkaTekstura;
	Sprite menuSprite,logoSprite,strzalkaSprite;
	Text *tablicaText;
	Music menuMuzyka; 
	Sound menuDzwiekWybor,menuDzwiekZatwierdzMenu;
	SoundBuffer bufor,bufor2;
	Font czcionka;
	IntRect obszar;
	int kierunekTla,aktualnyWyborMenu,podstronaMenu;
public:
	Menu();
	~Menu();
	bool start(RenderWindow& okno);

private:
	void poruszajTlo();
<<<<<<< Updated upstream
	void rysuj(RenderWindow& okno);
	void aktualizacjaMenu();
	void ruchMyszka(int,int);
	void klikMyszka(int,int);
=======
	void rysuj(RenderWindow& okno,int,int);
	void przygotujStrone(int,int);
	void aktualizacjaMenu(int);
	void ruchMyszka(int,int,int);
	void klikMyszka(int,int,int, RenderWindow& okno);
	void enter(int,int,RenderWindow& okno);
>>>>>>> Stashed changes
};

