#pragma once
#include "Biblioteki.h"

struct Lista
{
	float x, y;
	Sprite sprite;
	struct Lista* nast, * poprz;
	Lista()
	{
		x = y = 0;
		nast = poprz = NULL;
	}
};

class Gracz
{
	int kierunek;
	float szybkosc, czasomierz, opoznienie;
	Texture graczCialoTekstura, graczGlowaTekstura;
	Sprite* graczSprite;
	Clock zegar;

public:
	struct Lista* wsk_listy;

public:
	Gracz();
	~Gracz();
	void dodajElement();
	void rysuj(RenderWindow& okno);
	void obsluguj();

private:
	void ruchGracza();
	void sterowanie();
	void przejdzNaKoniecListy(Lista **wskaznik);
};

