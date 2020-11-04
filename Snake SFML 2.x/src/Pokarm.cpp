#include "Pokarm.h"

Pokarm::Pokarm()
	:Animacja(Vector2u(6,1), 0.12f)
{
	animacjaTekstura.loadFromFile("data/Sprity do gry/Gracz i przedmioty/jablko_animacja.png");
	animacjaSprite.setTexture(animacjaTekstura);
	animacjaSprite.setScale(0.1f, 0.1f);
	Rect<float> obszar = animacjaSprite.getGlobalBounds();
	animacjaSprite.setOrigin(Vector2f(obszar.width / 2.0f, obszar.width / 2.0f));
	x = y = 200.0f;
}

void Pokarm::ustawPokarm(Gracz& gracz)
{
	losuj(x, DLUGOSC_PLANSZY);
	losuj(y, WYSOKOSC_PLANSZY);
	Lista* wsk = gracz.wsk_listy;

	while (wsk != NULL)
	{
		while(kolizja(wsk->sprite, animacjaSprite))
		{
			losuj(x, DLUGOSC_PLANSZY);
			losuj(y, WYSOKOSC_PLANSZY);
			animacjaSprite.setPosition(x * 60, y * 60);
		}
		wsk = wsk->nast;
	}
}

bool Pokarm::sprawdzCzyZjedzony(Gracz& gracz)
{
	if (kolizja(gracz.wsk_listy->sprite, animacjaSprite))
	{
		gracz.dodajElement();
		ustawPokarm(gracz);
		return true;
	}
	return false;
}