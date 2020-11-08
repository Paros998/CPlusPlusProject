#pragma once
#include "Biblioteki.h"

struct Lista
{
	float x, y;
	Sprite sprite;
	struct Lista* nast, * poprz;
	Lista()
	{
		x = START_X;
		y = START_Y;
		nast = poprz = NULL;
	}
};

class Gracz
{
	int kierunek;
	float szybkosc, opoznienie,czas;
	Texture graczCialoTekstura, graczGlowaTekstura;
	Sprite* graczSprite;
	String tablicaStringCialoTekstura[5][8], tablicaKroki[3];
	Sound dzwiekTeleport, dzwiekWalnieciePrzeszkody,dzwiekWalniecieSiebie,dzwiekKroki;
	SoundBuffer buforTeleport, buforPrzeszkoda,buforWaz,buforKroki;

public:
	Clock zegar,zegar2;
	float czasomierz;
	struct Lista* wsk_listy;
	int tekstura, poziomTekstury;

public:
	Gracz(int poziom);
	~Gracz();
	void dodajElement();
	void rysuj(RenderWindow& okno);
	void obsluguj(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	bool walnijPrzeszkode(Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	bool samoUkaszenie();
	void zerujAnimacje();
	void ochronaKolizji(Clock zegarAnimacji,int i , int j);
	void ustawTeksture100();

private:
	void przejdzPrzezDziure(Sprite* dziuraSprite, int liczbaDziur);
	void ruchGracza(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	void sterowanie();
	void przejdzNaKoniecListy(Lista **wskaznik);
	void przejdzPrzezSciane();

};

