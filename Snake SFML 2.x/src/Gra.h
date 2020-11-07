#pragma once
#include "Biblioteki.h"

class Gra : public Punkty
{
protected:
	Texture tloMapyTekstura, planszaTekstura[3], przeszkodaTekstura[3],dziuraTekstura;
	String* tablicaTekstur, tablicaTeksturPrzeszkod[3];
	Sprite tloMapySprite, ** planszaSprite,**ramkaSprite ,* przeszkodaSprite, dziuraSprite[2];
	unsigned int dlugoscPlanszy, wysokoscPlanszy, odstep;
	int liczbaPrzeszkod,wyborPauza,rdzenie;
	int *tablicaX, *tablicaY, *tablicaJ;
	Text menuPauzy[2],koniecGry[2];
public:
	Gra(int);
	~Gra();
public:
	thread RdzenPlansza;
protected:
	void rysujPlansze(RenderWindow& okno);
	int pauza(RenderWindow& okno);
	bool silnikPoziomu(RenderWindow& okno);
	void obliczPozycje();
	bool przegrana(Gracz& gracz, Clock zegar);
};

