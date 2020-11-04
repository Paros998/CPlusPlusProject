#include "Pokarm.h"

Pokarm::Pokarm(string sciezkaPliku)
	:Animacja::Animacja(sciezkaPliku, Vector2u(9, 1), 0.06f)
{
	x = y = 0.0f;
}

void Pokarm::ustawPokarm(Gracz& gracz, Vector2f plansza[][DLUGOSC_PLANSZY],Sprite* przeszkody,int liczbaprzeszkod)
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
			animacjaSprite.setPosition(plansza[(int)y][(int)x].x + 48.0f, plansza[(int)y][(int)x].y + 48.0f);
			for (int i = 0; i < liczbaprzeszkod; i++)
			{
				while(kolizja(animacjaSprite, przeszkody[i]))
				{
					losuj(x, DLUGOSC_PLANSZY);
					losuj(y, WYSOKOSC_PLANSZY);
					animacjaSprite.setPosition(plansza[(int)y][(int)x].x + 48.0f, plansza[(int)y][(int)x].y + 48.0f);
					wsk = gracz.wsk_listy;
				}
			}
		}
		
		wsk = wsk->nast;
	}
	
}

bool Pokarm::sprawdzCzyZjedzony(Gracz& gracz, Vector2f plansza[][DLUGOSC_PLANSZY],Sprite* przeszkody,int liczbaprzeszkod)
{
	if (kolizja(gracz.wsk_listy->sprite, animacjaSprite))
	{
		gracz.dodajElement();
		ustawPokarm(gracz, plansza,przeszkody,liczbaprzeszkod);
		return true;
	}
	return false;
}