#include "Pokarm.h"
#define STALA START_Y

enum ktorybonus {Brak,Ochrona};

Pokarm::Pokarm(string sciezkaPliku, string sciezkaPlikuEfektu, Vector2u klatkiEfektu)
{	
	wartoscPunktow = 100;
	bonus = Brak;
	rysujEfekt = true;

	pokarmTekstura.loadFromFile(sciezkaPliku);
	pokarmTekstura.setSmooth(true);
	pokarmSprite.setTexture(pokarmTekstura);
	pokarmSprite.setScale(0.2f, 0.2f);

	efektTekstura.loadFromFile(sciezkaPlikuEfektu);
	efektTekstura.setSmooth(true);
	efektSprite.setTexture(efektTekstura);
	//Rect<float> obszarEfektu = efektSprite.getGlobalBounds();
	//efektSprite.setOrigin(Vector2f(obszarEfektu.width / 2.0f, obszarEfektu.height / 2.0f));

	x = 200.0f, y = 120.0f;
	pokarmSprite.setPosition(x , y);
	efektSprite.setPosition(x, y);
	Rect<float> _obszar = pokarmSprite.getGlobalBounds();
	pokarmSprite.setOrigin(Vector2f(_obszar.width / 2.0f, _obszar.width / 2.0f));

	this->klatkiEfektu = klatkiEfektu;
	animacja = new Animacja(pokarmTekstura, Vector2u(9, 1), 0.04f);
	efektSpecjalny = new Animacja(efektTekstura, klatkiEfektu, 0.04f);
}

Pokarm::~Pokarm() { 
	delete animacja; 
	delete efektSpecjalny;
}

void Pokarm::ustawPokarm(Gracz& gracz, Sprite ** plansza, Sprite* przeszkody, int liczbaprzeszkod)
{
	losuj(x, DLUGOSC_PLANSZY);
	losuj(y, WYSOKOSC_PLANSZY);
	pokarmSprite.setPosition(plansza[(int)y][(int)x].getPosition().x + 16, plansza[(int)y][(int)x].getPosition().y + 16);
	efektSprite.setPosition(plansza[(int)y][(int)x].getPosition().x - STALA, plansza[(int)y][(int)x].getPosition().y - STALA);
miejsce:
	Lista* wsk = gracz.wsk_listy;
	while (wsk != NULL)
	{
		while (kolizja(wsk->sprite, pokarmSprite))
		{
			losuj(x, DLUGOSC_PLANSZY);
			losuj(y, WYSOKOSC_PLANSZY);
			pokarmSprite.setPosition(plansza[(int)y][(int)x].getPosition().x + 16, plansza[(int)y][(int)x].getPosition().y + 16);
			efektSprite.setPosition(plansza[(int)y][(int)x].getPosition().x - STALA, plansza[(int)y][(int)x].getPosition().y - STALA);
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
			efektSprite.setPosition(plansza[(int)y][(int)x].getPosition().x - STALA, plansza[(int)y][(int)x].getPosition().y - STALA);
			goto miejsce;
		}
	}
}

bool Pokarm::sprawdzCzyZjedzony(Gracz& gracz)
{
	if (kolizja(gracz.wsk_listy->sprite, pokarmSprite))
	{
		rysujEfekt = true;
		return true;
	}
	return false;
}

void Pokarm::rysuj(RenderWindow& okno)
{
	animacja->aktualizuj(0);
	pokarmSprite.setTextureRect(animacja->obszar);
	okno.draw(pokarmSprite);

	if (rysujEfekt)
	{
		if (efektSpecjalny->aktualizuj(0) >(int)( klatkiEfektu.x - 2))
			rysujEfekt = false;
		efektSprite.setTextureRect(efektSpecjalny->obszar);
		okno.draw(efektSprite);
	}
}

void Pokarm::wyzerujAnimacje()
{
	animacja->zegar.restart();
	animacja->calkowityCzas = 0.0f;
}