#pragma once
#include "Biblioteki.h"

class Gra
{
protected:
	Texture tloMapyTekstura, planszaTekstura[3], przeszkodaTekstura;
	String* tablicaTekstur, tablicaTeksturPrzeszkod[3];
	Sprite tloMapySprite, * planszaSprite, * przeszkodaSprite;
	unsigned int wysokoscPlanszy, dlugoscPlanszy, odstep;
	int liczbaPrzeszkod, liczbaDziur;
	int *tablicaX, *tablicaY, *tablicaJ;
	Vector2f tablica_srodkow_planszy[12][24];
public:
	Gra(int);
	~Gra();
protected:
	void rysujPlansze(RenderWindow& okno);
};

