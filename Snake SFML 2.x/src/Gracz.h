#pragma once
#include "Biblioteki.h"

class Gracz
{
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

	struct Lista *wsk_listy;
	int dlugoscGracza, kierunek;
	float szybkosc;
	Texture graczCialoTekstura, graczGlowaTekstura;
	Sprite* graczSprite;

public:
	Gracz();
	~Gracz();
	void ruchGracza();
	void sterowanie();
	void rysuj(RenderWindow& okno);

private:
	void dodajElement();
	void przejdzNaKoniecListy(Lista **wskaznik);
};

