#pragma once
#include "Biblioteki.h"

class Gracz;

class Animacja
{
	float czasZmiany, deltaCzas;
	Vector2u aktualnyObraz, liczbaObrazow;
	float x = 0.0f, y = 0.0f;

public:
	IntRect obszar;
	Clock zegar;
	float calkowityCzas;
	
public:
	Animacja(Texture& spriteTekstura, Vector2u liczbaObrazow, float czasZmiany);
	void aktualizuj(int wiersz);
};
