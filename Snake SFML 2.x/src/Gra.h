#pragma once
#include "Biblioteki.h"

struct ListaWynikow {
	string pseudonim;
	int wynikGracza;
	struct ListaWynikow* next;
};

class Gra : public Punkty
{
protected:
	Texture tloMapyTekstura, planszaTekstura[3], przeszkodaTekstura[3],dziuraTekstura;
	String* tablicaTekstur, tablicaTeksturPrzeszkod[3],tablicaMuzyka[3];
	Sprite tloMapySprite, ** planszaSprite,**ramkaSprite ,* przeszkodaSprite, dziuraSprite[2];
	unsigned int dlugoscPlanszy, wysokoscPlanszy, odstep;
	int liczbaPrzeszkod,wyborPauza,rdzenie,POZIOM,WARUNEK;
	int *tablicaX, *tablicaY, *tablicaJ;
	Text menuPauzy[2],koniecGry[2];
	Music muzykaGra;
	SoundBuffer buforJedzenie;
	Sound dzwiekJedzenie;
public:
	Gra(int iloscprzeszkod,int poziom,int warunek);
	~Gra();
	double procX, procY;
	float czasZloteJablko;
	struct ListaWynikow* wsk_wyniki;
public:
	thread RdzenPlansza;
protected:
	void rysujPlansze(RenderWindow& okno);
	int pauza(RenderWindow& okno);
	int silnikPoziomu(RenderWindow& okno,int poziom);
	void obliczPozycje();
	bool przegrana(Gracz& gracz, Clock zegar);
	int gameOver(RenderWindow& okno);
	bool wygrana(int aktualnyStan);
	string wpiszNick(RenderWindow& okno);
	void wynikiTXT(string pseudonimGracza);
};

