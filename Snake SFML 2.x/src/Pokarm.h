#pragma once
#include "Biblioteki.h"

class Gracz;

class Pokarm : public Animacja
{
	float x, y;

public:
	Pokarm(string sciezkaPliku);
	bool sprawdzCzyZjedzony(Gracz& gracz, Vector2f plansza[][DLUGOSC_PLANSZY], Sprite* przeszkody,int liczbaprzeszkod);

private:
	void ustawPokarm(Gracz& gracz, Vector2f plansza[][DLUGOSC_PLANSZY],Sprite* przeszkody,int liczbaprzeszkod);
};

