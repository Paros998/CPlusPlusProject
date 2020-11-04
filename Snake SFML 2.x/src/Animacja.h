#pragma once
#include "Biblioteki.h"

class Animacja
{
private:
	float calkowityCzas, czasZmiany;
	Vector2u aktualnyObraz, liczbaObrazow;
	Clock czasOdpoczynku;
	IntRect obszar;

protected:
	Texture animacjaTekstura;
	Sprite animacjaSprite;
	
public:
	Animacja(Vector2u liczbaObrazow, float czasZmiany);
	void aktualizuj(int wiersz, float deltaCzas);
	void rysujAnimacje(RenderWindow& okno);
	void startAnimacji(float deltaCzas);
};
