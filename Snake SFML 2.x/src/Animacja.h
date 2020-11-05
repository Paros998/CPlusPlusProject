#pragma once
#include "Biblioteki.h"

class Animacja
{
private:
	float  czasZmiany, deltaCzas;
	Vector2u aktualnyObraz, liczbaObrazow;

	IntRect obszar;
public:
	Clock zegar;
	float calkowityCzas;
protected:
	Texture animacjaTekstura;
	Sprite animacjaSprite;
	
public:
	Animacja(string sciezkaPliku, Vector2u liczbaObrazow, float czasZmiany);
	void aktualizuj(int wiersz);
	void rysujAnimacje(RenderWindow& okno);
};
