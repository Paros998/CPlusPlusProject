#pragma once
#include "Biblioteki.h"

class Menu
{
	Texture menuTekstura,logoTekstura,strzalkaTekstura,plusTekstura,minusTekstura,opcjeTekstura,ludzikiTekstura,kontrolerTekstura,dolTekstura,goraTekstura,lewoTekstura,prawoTekstura;
	Sprite menuSprite,logoSprite,strzalkaSprite,plusSprite,minusSprite,opcjeSprite,ludzikiSprite,kontrolerSprite,dolSprite,goraSprite,lewoSprite,prawoSprite;
	Text *tablicaText,*opcjeText,*wynikiText;
	std::ifstream wynikiPlik;
	std::string linia;
	Music menuMuzyka; 
	Sound menuDzwiekWybor,menuDzwiekZatwierdzMenu;
	SoundBuffer bufor,bufor2;
	Font czcionka;
	IntRect obszar;
	int kierunekTla,aktualnyWyborMenu,podstronaMenu,iloscWynikow;
	float poziomMuzyki;
public:
	Menu();
	~Menu();
	bool start(RenderWindow& okno);

private:
	void poruszajTlo();
	void rysuj(RenderWindow& okno);
	void przygotujStrone();
	void aktualizacjaMenu();
	void ruchMyszka(int,int,double,double);
	void klikMyszka(int,int,double,double, RenderWindow& okno);
	void enter(RenderWindow& okno);

};

