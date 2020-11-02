#pragma once
#include "Biblioteki.h"

class Menu
{
	Texture menuTekstura,logoTekstura,strzalkaTekstura,plusTekstura,minusTekstura,opcjeTekstura,ludzikiTekstura,kontrolerTekstura,dolTekstura,goraTekstura,lewoTekstura,prawoTekstura;
	Sprite menuSprite,logoSprite,strzalkaSprite,plusSprite,minusSprite,opcjeSprite,ludzikiSprite,kontrolerSprite,dolSprite,goraSprite,lewoSprite,prawoSprite;
	Text *tablicaText,*opcjeText,*wynikiText;
	std::ifstream wynikiPlik;
	std::string linia;
	Music *menuMuzyka; 
	Sound menuDzwiekWybor,menuDzwiekZatwierdzMenu;
	SoundBuffer bufor,bufor2;
	Font czcionka;
	IntRect obszar;
	int kierunekTla,aktualnyWyborMenu,podstronaMenu,iloscWynikow, numerMuzyki;
	float poziomMuzyki;
	double procX, procY;
public:
	Menu();
	~Menu();
	bool start(RenderWindow& okno);

private:
	void poruszajTlo();
	void rysuj(RenderWindow& okno);
	void przygotujStrone();
	void aktualizacjaMenu();
	void ruchMyszka(int,int);
	void klikMyszka(int,int, RenderWindow& okno);
	void enter(RenderWindow& okno);

};

