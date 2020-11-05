#pragma once
#include "Biblioteki.h"

class Gra : public Punkty
{
protected:
	Texture tloMapyTekstura, planszaTekstura[3], przeszkodaTekstura;
	String* tablicaTekstur, tablicaTeksturPrzeszkod[3];
	Sprite tloMapySprite, * planszaSprite, * przeszkodaSprite;
	unsigned int wysokoscPlanszy, dlugoscPlanszy, odstep;
	int liczbaPrzeszkod, liczbaDziur,wyborPauza;
	int *tablicaX, *tablicaY, *tablicaJ;
	Vector2f tablica_srodkow_planszy[12][24];
	Text menuPauzy[2];
public:
	Gra(int);
	~Gra();
protected:
	void rysujPlansze(RenderWindow& okno);
	int pauza(RenderWindow& okno);
	bool silnikPoziomu(RenderWindow& okno);
};

