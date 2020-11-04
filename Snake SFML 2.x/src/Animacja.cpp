#include "Biblioteki.h"

Animacja::Animacja(Vector2u liczbaObrazow, float czasZmiany)
{
	this->liczbaObrazow = liczbaObrazow;
	this->czasZmiany = czasZmiany;
	calkowityCzas = 0.0f;
	aktualnyObraz.x = 0;
	obszar.width = animacjaTekstura.getSize().x / float(liczbaObrazow.x);
	obszar.height = animacjaTekstura.getSize().y / float(liczbaObrazow.y);
}

void Animacja::aktualizuj(int wiersz, float deltaCzas)
{
	aktualnyObraz.y = wiersz;
	calkowityCzas += deltaCzas;

	if (calkowityCzas >= czasZmiany)
	{
		calkowityCzas -= czasZmiany;
		aktualnyObraz.x++;

		if (aktualnyObraz.x >= liczbaObrazow.x)
		{
			aktualnyObraz.x = 0;
		}
	}

	obszar.left = aktualnyObraz.x * obszar.width;
	obszar.top = aktualnyObraz.y * obszar.height;
	
}

void Animacja::rysujAnimacje(RenderWindow& okno) 
{
	okno.draw(animacjaSprite);
}

void Animacja::startAnimacji(float deltaCzas)
{
	aktualizuj(0, deltaCzas);
	//czasOdpoczynku.restart();
	animacjaSprite.setTextureRect(obszar);
}