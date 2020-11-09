#pragma once
#include "Biblioteki.h"

class Gracz;
class Animacja;

class Pokarm
{
	float x, y;
	bool rysujEfekt;
	Texture pokarmTekstura, efektTekstura;
	Sprite pokarmSprite, efektSprite;
	Animacja* animacja, * efektSpecjalny;
	Vector2u klatkiEfektu;

public:
	Pokarm(string sciezkaPliku, string sciezkaPlikuEfektu, Vector2u klatkiEfektu);
	~Pokarm();
	bool sprawdzCzyZjedzony(Gracz& gracz);
	void ustawPokarm(Gracz& gracz, Sprite** plansza, Sprite* przeszkody, int liczbaprzeszkod);
	void rysuj(RenderWindow& okno);
	void wyzerujAnimacje();
	int wartoscPunktow;
	int bonus;
};

