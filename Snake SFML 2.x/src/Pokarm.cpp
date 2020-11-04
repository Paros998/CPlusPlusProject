#include "Pokarm.h"

Pokarm::Pokarm(string sciezkaPliku)
	:Animacja::Animacja(sciezkaPliku, Vector2u(9, 1), 0.06f)
{
	x = y = 0.0f;
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