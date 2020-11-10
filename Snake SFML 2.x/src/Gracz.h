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

class Animacja;

class Gracz
{
	int kierunek,Poziom;
	float szybkosc, opoznienie, mnoznikCzasu;
	bool ustawTeksture;
	Texture graczCialoTekstura, graczGlowaTekstura;
	Sprite* graczSprite;
	String tablicaStringCialoTekstura[3][8], tablicaKroki[3];
	Sound dzwiekTeleport, dzwiekWalnieciePrzeszkody,dzwiekWalniecieSiebie,dzwiekKroki;
	SoundBuffer buforTeleport, buforPrzeszkoda,buforWaz,buforKroki;
	Animacja* animacjaCiala;
	Time czasRuchu;

public:
	Clock zegar,zegarDzwieki;
	float czasomierz;
	struct Lista* wsk_listy;
	int tekstura;

public:
	Gracz(int poziom);
	~Gracz();
	void dodajElement();
	void rysuj(RenderWindow& okno);
	void obsluguj(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	bool walnijPrzeszkode(Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	bool samoUkaszenie();
	void zerujAnimacje();
	void ochronaKolizji();
	void ustawNowaTeksture();
	void ustawTeksture100();

private:
	void sterowanie();
	void przejdzPrzezDziure(Sprite* dziuraSprite, int liczbaDziur);
	void ruchGracza(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	void przejdzNaKoniecListy(Lista **wskaznik);
	void przejdzPrzezSciane();

};

