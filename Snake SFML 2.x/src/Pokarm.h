#pragma once
#include "Biblioteki.h"

class Gracz;
class Animacja;

class Pokarm
{
	float x, y;
private:
	Texture pokarmTekstura;
	Sprite pokarmSprite;
	Animacja* animacja;

public:
	Pokarm(string sciezkaPliku);
	~Pokarm();
	bool sprawdzCzyZjedzony(Gracz& gracz, Sprite ** plansza, Sprite* przeszkody,int liczbaprzeszkod);
	void ustawPokarm(Gracz& gracz, Sprite** plansza, Sprite* przeszkody, int liczbaprzeszkod);
	void rysuj(RenderWindow& okno);
};

