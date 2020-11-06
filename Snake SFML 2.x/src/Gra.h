#pragma once
#include "Biblioteki.h"

class Gra : public Punkty
{
protected:
	Texture tloMapyTekstura, planszaTekstura[3], przeszkodaTekstura,dziuraTekstura;
	String* tablicaTekstur, tablicaTeksturPrzeszkod[3];
	Sprite tloMapySprite, * planszaSprite, * przeszkodaSprite, dziuraSprite[2];
	unsigned int wysokoscPlanszy, dlugoscPlanszy, odstep;
	int liczbaPrzeszkod,wyborPauza,rdzenie;
	int *tablicaX, *tablicaY, *tablicaJ;
	Vector2f tablica_srodkow_planszy[12][24];
	Text menuPauzy[2],koniecGry[2];
public:
	Gra(int);
	~Gra();
public:
	thread RdzenGracz,RdzenPlansza;
protected:
	void rysujPlansze(RenderWindow& okno);
	int pauza(RenderWindow& okno);
	bool silnikPoziomu(RenderWindow& okno);
	void obliczPozycje();
};

