#pragma once
#include "Biblioteki.h"
#include <vector>

class Gracz
{
	struct W�� { float x, y; };
	struct W�� w��[100];

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

