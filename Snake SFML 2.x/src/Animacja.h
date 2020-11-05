#pragma once
#include "Biblioteki.h"

class Gracz;

class Animacja
{
private:
	float  czasZmiany, deltaCzas;
	Vector2u aktualnyObraz, liczbaObrazow;
	float x= 0.0f, y=0.0f;
	IntRect obszar;
public:
	Clock zegar;
	float calkowityCzas;
protected:
	Texture animacjaTekstura;
	Sprite animacjaSprite;
	
public:
	Animacja(string sciezkaPliku, Vector2u liczbaObrazow, float czasZmiany, Gracz& gracz, Vector2f plansza[][DLUGOSC_PLANSZY], Sprite* przeszkody, int liczbaprzeszkod);
	void aktualizuj(int wiersz);
	void rysujAnimacje(RenderWindow& okno);
	void ustawPokarm(Gracz& gracz, Vector2f plansza[][DLUGOSC_PLANSZY], Sprite* przeszkody, int liczbaprzeszkod);
};
