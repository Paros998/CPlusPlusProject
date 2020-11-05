#pragma once
#include "Biblioteki.h"

class Gracz;

class Pokarm : public Animacja
{

public:
	Pokarm(string sciezkaPliku, Gracz& gracz, Vector2f plansza[][DLUGOSC_PLANSZY], Sprite* przeszkody, int liczbaprzeszkod);
	bool sprawdzCzyZjedzony(Gracz& gracz, Vector2f plansza[][DLUGOSC_PLANSZY], Sprite* przeszkody,int liczbaprzeszkod);
};

