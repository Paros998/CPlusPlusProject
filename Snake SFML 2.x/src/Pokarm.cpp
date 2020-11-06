#include "Pokarm.h"

Pokarm::Pokarm(string sciezkaPliku)
{
	pokarmTekstura.loadFromFile(sciezkaPliku); // NA POTEM
	pokarmTekstura.setSmooth(true);
	pokarmSprite.setTexture(pokarmTekstura);
	pokarmSprite.setScale(0.2f, 0.2f);
	x = 200.0f, y = 120.0f;
	pokarmSprite.setPosition(x , y);
	Rect<float> _obszar = pokarmSprite.getGlobalBounds();
	pokarmSprite.setOrigin(Vector2f(_obszar.width / 2.0f, _obszar.width / 2.0f));

	animacja = new Animacja(pokarmTekstura, Vector2u(9, 1), 0.02f);
}

Pokarm::~Pokarm() { delete animacja; }

void Pokarm::ustawPokarm(Gracz& gracz, Sprite ** plansza, Sprite* przeszkody, int liczbaprzeszkod)
{
	losuj(x, DLUGOSC_PLANSZY);
	losuj(y, WYSOKOSC_PLANSZY);
	pokarmSprite.setPosition(plansza[(int)y][(int)x].getPosition().x + 16, plansza[(int)y][(int)x].getPosition().y + 16);
miejsce:
	Lista* wsk = gracz.wsk_listy;
	while (wsk != NULL)
	{
		while (kolizja(wsk->sprite, pokarmSprite))
		{
			losuj(x, DLUGOSC_PLANSZY);
			losuj(y, WYSOKOSC_PLANSZY);
			pokarmSprite.setPosition(plansza[(int)y][(int)x].getPosition().x + 16, plansza[(int)y][(int)x].getPosition().y + 16);
			wsk = gracz.wsk_listy;
		}
		wsk = wsk->nast;
	}
	for (int i = 0; i < liczbaprzeszkod; i++)
	{
		while (kolizja(pokarmSprite, przeszkody[i]))
		{
			losuj(x, DLUGOSC_PLANSZY);
			losuj(y, WYSOKOSC_PLANSZY);
			pokarmSprite.setPosition(plansza[(int)y][(int)x].getPosition().x + 16 , plansza[(int)y][(int)x].getPosition().y + 16);
			goto miejsce;
		}
	}
}

bool Pokarm::sprawdzCzyZjedzony(Gracz& gracz, Sprite** plansza,Sprite* przeszkody,int liczbaprzeszkod)
{
	if (kolizja(gracz.wsk_listy->sprite, pokarmSprite))
	{
		gracz.dodajElement();
		ustawPokarm(gracz, plansza,przeszkody,liczbaprzeszkod);
		return true;
	}
	return false;
}

void Pokarm::rysuj(RenderWindow& okno)
{
	animacja->aktualizuj(0);
	pokarmSprite.setTextureRect(animacja->obszar);
	okno.draw(pokarmSprite);
}
