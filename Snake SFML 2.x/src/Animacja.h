#pragma once
#include "Biblioteki.h"

class Animacja
{
private:
	float calkowityCzas, czasZmiany, deltaCzas;
	Vector2u aktualnyObraz, liczbaObrazow;
	Clock zegar;
	IntRect obszar;

protected:
	Texture animacjaTekstura;
	Sprite animacjaSprite;
	
public:
	Animacja(string sciezkaPliku, Vector2u liczbaObrazow, float czasZmiany);
	void aktualizuj(int wiersz);
	void rysujAnimacje(RenderWindow& okno);
};
