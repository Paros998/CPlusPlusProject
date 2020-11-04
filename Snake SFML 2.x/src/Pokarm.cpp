#include "Pokarm.h"

Pokarm::Pokarm(string sciezkaPliku)
	:Animacja::Animacja(sciezkaPliku, Vector2u(9, 1), 0.06f)
{
	x = y = 0.0f;
}

void Pokarm::ustawPokarm(Gracz& gracz, Vector2f plansza[][DLUGOSC_PLANSZY])
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
			animacjaSprite.setPosition(plansza[(int)y][(int)x].x+32.0f, plansza[(int)y][(int)x].y+32.0f);
		}
		wsk = wsk->nast;
	}
}

bool Pokarm::sprawdzCzyZjedzony(Gracz& gracz, Vector2f plansza[][DLUGOSC_PLANSZY])
{
	if (kolizja(gracz.wsk_listy->sprite, animacjaSprite))
	{
		gracz.dodajElement();
		ustawPokarm(gracz, plansza);
		return true;
	}
	return false;
}