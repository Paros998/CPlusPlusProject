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
	String tablicaStringCialoTekstura[10],tablicaKroki[3];
	Sound dzwiekTeleport, dzwiekWalnieciePrzeszkody,dzwiekWalniecieSiebie,dzwiekKroki;
	SoundBuffer buforTeleport, buforPrzeszkoda,buforWaz,buforKroki;

public:
	Clock zegar,zegar2;
	float czasomierz;
	struct Lista* wsk_listy;
	int tekstura;

public:
	Gracz(int poziom);
	~Gracz();
	void dodajElement();
	void rysuj(RenderWindow& okno);
	void obsluguj(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	bool walnijPrzeszkode(Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	bool samoUkaszenie();
	void zerujAnimacje();

private:
	void przejdzPrzezDziure(Sprite* dziuraSprite, int liczbaDziur);
	void ruchGracza(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	void sterowanie();
	void przejdzNaKoniecListy(Lista **wskaznik);
	void przejdzPrzezSciane();

};

