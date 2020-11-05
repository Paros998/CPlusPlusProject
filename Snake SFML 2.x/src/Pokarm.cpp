#include "Pokarm.h"

Pokarm::Pokarm(string sciezkaPliku, Gracz& gracz, Vector2f plansza[][DLUGOSC_PLANSZY], Sprite* przeszkody, int liczbaprzeszkod)
	:Animacja::Animacja(sciezkaPliku, Vector2u(9, 1), 0.06f, gracz, plansza, przeszkody,liczbaprzeszkod)
{

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
