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
	float szybkosc;
	Texture graczCialoTekstura, graczGlowaTekstura;
	Sprite* graczSprite;

public:
	struct Lista* wsk_listy;

public:
	Gracz();
	~Gracz();
	void ruchGracza();
	void sterowanie();
	void dodajElement();
	void rysuj(RenderWindow& okno);

private:
	void przejdzNaKoniecListy(Lista **wskaznik);
};

