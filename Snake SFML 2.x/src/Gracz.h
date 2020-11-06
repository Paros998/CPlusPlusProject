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

public:
	Clock zegar;
	float czasomierz;
	struct Lista* wsk_listy;

public:
	Gracz();
	~Gracz();
	void dodajElement();
	void rysuj(RenderWindow& okno);
	void obsluguj(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod);

private:
	bool walnijPrzeszkode(Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	void przejdzPrzezDziure(Sprite* dziuraSprite, int liczbaDziur);
	void ruchGracza(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	void sterowanie();
	void przejdzNaKoniecListy(Lista **wskaznik);
	void przejdzPrzezSciane();

};

