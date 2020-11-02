#pragma once
#include "Biblioteki.h"
#include <vector>

class Gracz
{
	struct W¹¿ { float x, y; };
	struct W¹¿ w¹¿[100];

	int dlugoscGracza, kierunek;
	float szybkosc;
	Texture graczCialoTekstura, graczGlowaTekstura;
	Sprite* graczSprite;

public:
	Gracz();
	~Gracz();
	void ruchGracza();
	void sterowanie();
	void rysuj(RenderWindow& okno);
};

