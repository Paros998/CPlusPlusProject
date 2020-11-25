/*! \file Animacja.cpp
*   \brief Zawiera ciala konstruktorow ,destruktorow i metod klasy Aplikacja
*/
#include "Animacja.h"

Animacja::Animacja(Texture& spriteTekstura, Vector2u liczbaObrazow, float czasZmiany)
{
	this->liczbaObrazow = liczbaObrazow;
	this->czasZmiany = czasZmiany;
	
	deltaCzas = calkowityCzas = 0.0f;
	aktualnyObraz.x = 0;
	obszar.width = spriteTekstura.getSize().x / float(liczbaObrazow.x);
	obszar.height = spriteTekstura.getSize().y / float(liczbaObrazow.y);
}

int Animacja::aktualizuj(int wiersz)
{
	deltaCzas = zegar.restart().asSeconds();
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

	return aktualnyObraz.x;
}