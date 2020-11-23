#pragma once
#include "Biblioteki.h"
class Pokarm;
class Gra : public Punkty 
{
protected:
	Texture tloMapyTekstura, planszaTekstura[3], przeszkodaTekstura[3],dziuraTekstura,pucharTekstura;
	String* tablicaTekstur, tablicaTeksturPrzeszkod[3],tablicaMuzyka[3],tablicaTeskturPucharu[3],wynikString;
	Sprite tloMapySprite, ** planszaSprite,**ramkaSprite ,* przeszkodaSprite, dziuraSprite[2],pucharSprite;
	unsigned int dlugoscPlanszy, wysokoscPlanszy, odstep;
	int liczbaPrzeszkod,wyborPauza,rdzenie,POZIOM,WARUNEK;
	int *tablicaX, *tablicaY, *tablicaJ;
	Text menuPauzy[2],koniecGry[2], wynikText;
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
	int pauza(RenderWindow& okno, Gracz& gracz,Pokarm* pokarm);
	int silnikPoziomu(RenderWindow& okno,int poziom);
	void obliczPozycje();
	bool przegrana(Gracz& gracz, Clock zegar);
	int gameOver(RenderWindow& okno, Gracz& gracz,Pokarm* pokarm);
	bool wygrana(int aktualnyStan);
	void aktualizujStanGry(int aktualnyWynik);
	void pauzaPrzedGra(RenderWindow& okno, Gracz& gracz,Pokarm * pokarm);
};

