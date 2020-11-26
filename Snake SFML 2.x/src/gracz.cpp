/*! \file Gracz.cpp
	\brief Plik zawierajacy metody klasy gracza.
*/
/*! \enum opis_gracz {GLOWA, CIALO, TRANS}
	\brief Typ wyliczeniowy do 2.
	Okresla symbole w tablicy spriteow gracza.
*/
#include "Gracz.h"

enum opis_gracz {GLOWA, CIALO, TRANS};

void Gracz::przejdzNaKoniecListy(Lista** wsk)
{
	while ((*wsk)->nast != NULL)
		*wsk = (*wsk)->nast;
}

void Gracz::dodajElement()
{
	if (wsk_listy != NULL)
	{
		Lista* nowy_element = new Lista;
		if (nowy_element != NULL)
		{
			Lista* wsk = wsk_listy;
			przejdzNaKoniecListy(&wsk);
			nowy_element->sprite = graczSprite[CIALO];
			nowy_element->sprite.setRotation(wsk->sprite.getRotation());
			nowy_element->y = wsk->y;
			nowy_element->x = wsk->x;
			wsk->nast = nowy_element;
			nowy_element->poprz = wsk;
		}
	}
}

Gracz::Gracz(int poziom)
{
	this->Poziom = poziom;
	buforPrzeszkoda.loadFromFile("data/MuzykaDzwiekiGra/wazWkamien.ogg");
	buforTeleport.loadFromFile("data/MuzykaDzwiekiGra/teleport.wav");
	buforWaz.loadFromFile("data/MuzykaDzwiekiGra/wazWsiebie.ogg");

	tablicaKroki[0] = "data/MuzykaDzwiekiGra/stepdirt_1.wav";
	tablicaKroki[1] = "data/MuzykaDzwiekiGra/stepsnow_1.wav";
	tablicaKroki[2] = "data/MuzykaDzwiekiGra/stepstone_1.wav";

	buforKroki.loadFromFile(tablicaKroki[poziom]);

	dzwiekWalnieciePrzeszkody.setBuffer(buforPrzeszkoda);
	dzwiekTeleport.setBuffer(buforTeleport);
	dzwiekWalnieciePrzeszkody.setVolume(3.0f);
	dzwiekTeleport.setVolume(2.0f);
	dzwiekWalniecieSiebie.setBuffer(buforWaz);
	dzwiekWalniecieSiebie.setVolume(3.0f);
	dzwiekKroki.setBuffer(buforKroki);
	dzwiekKroki.setVolume(3.0f);

	tablicaStringCialoTekstura[GLOWA][0] = "data/Sprity do gry/Gracz i przedmioty/glowa/snake_glowa_green.png";
	tablicaStringCialoTekstura[GLOWA][1] = "data/Sprity do gry/Gracz i przedmioty/glowa/snake_glowa_grey.png";
	tablicaStringCialoTekstura[GLOWA][2] = "data/Sprity do gry/Gracz i przedmioty/glowa/snake_glowa_pink.png";
	tablicaStringCialoTekstura[GLOWA][3] = "data/Sprity do gry/Gracz i przedmioty/glowa/snake_glowa_cyan.png";
	tablicaStringCialoTekstura[GLOWA][4] = "data/Sprity do gry/Gracz i przedmioty/glowa/snake_glowa_blue.png";
	tablicaStringCialoTekstura[GLOWA][5] = "data/Sprity do gry/Gracz i przedmioty/glowa/snake_glowa_red.png";
	tablicaStringCialoTekstura[GLOWA][6] = "data/Sprity do gry/Gracz i przedmioty/glowa/snake_glowa_purple.png";
	tablicaStringCialoTekstura[GLOWA][7] = "data/Sprity do gry/Gracz i przedmioty/glowa/snake_glowa_yellow.png";

	tablicaStringCialoTekstura[CIALO][0] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_green.png";
	tablicaStringCialoTekstura[CIALO][1] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_grey.png";
	tablicaStringCialoTekstura[CIALO][2] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_pink.png";
	tablicaStringCialoTekstura[CIALO][3] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_cyan.png";
	tablicaStringCialoTekstura[CIALO][4] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_blue.png";
	tablicaStringCialoTekstura[CIALO][5] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_red.png";
	tablicaStringCialoTekstura[CIALO][6] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_purple.png";
	tablicaStringCialoTekstura[CIALO][7] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_yellow.png";

	tablicaStringCialoTekstura[TRANS][0] = "data/Sprity do gry/Gracz i przedmioty/animacja gracz/snake_green_trans.png";
	tablicaStringCialoTekstura[TRANS][1] = "data/Sprity do gry/Gracz i przedmioty/animacja gracz/snake_grey_trans.png";
	tablicaStringCialoTekstura[TRANS][2] = "data/Sprity do gry/Gracz i przedmioty/animacja gracz/snake_pink_trans.png";
	tablicaStringCialoTekstura[TRANS][3] = "data/Sprity do gry/Gracz i przedmioty/animacja gracz/snake_cyan_trans.png";
	tablicaStringCialoTekstura[TRANS][4] = "data/Sprity do gry/Gracz i przedmioty/animacja gracz/snake_blue_trans.png";
	tablicaStringCialoTekstura[TRANS][5] = "data/Sprity do gry/Gracz i przedmioty/animacja gracz/snake_red_trans.png";
	tablicaStringCialoTekstura[TRANS][6] = "data/Sprity do gry/Gracz i przedmioty/animacja gracz/snake_purple_trans.png";
	tablicaStringCialoTekstura[TRANS][7] = "data/Sprity do gry/Gracz i przedmioty/animacja gracz/snake_yellow_trans.png";

	tekstura = skinWeza;

	graczGlowaTekstura.loadFromFile(tablicaStringCialoTekstura[GLOWA][tekstura]);
	graczCialoTekstura.loadFromFile(tablicaStringCialoTekstura[TRANS][tekstura]);
	ustawTeksture = true;

	animacjaCiala = new Animacja(graczCialoTekstura, Vector2u(4, 1), 0.2f);
	graczSprite = new Sprite[2];

	graczSprite[GLOWA].setTexture(graczGlowaTekstura);
	Rect<float> rozmiar = graczSprite[GLOWA].getGlobalBounds();
	graczSprite[GLOWA].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));

	graczSprite[CIALO].setTexture(graczCialoTekstura);
	Rect<float> _rozmiar = graczSprite[CIALO].getGlobalBounds();
	graczSprite[CIALO].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));

	for(int i = 0; i < 2; i++)
		graczSprite[i].setScale(0.85f, 1.0f);

	if (Poziom + 1 == 1)
		mnoznikCzasu = 0.6f;
	if (Poziom + 1 == 2)
		mnoznikCzasu = 0.7f;
	if (Poziom + 1 == 3)
		mnoznikCzasu = 0.8f;

	rozmiar_weza = (float)graczGlowaTekstura.getSize().x;
	czasomierz = 0.0f;
	kierunek = 0;
	opoznienie = 0.1f;

	// Tworzenie listy
	wsk_listy = new Lista;
	if (wsk_listy != NULL)
	{
		wsk_listy->sprite = graczSprite[GLOWA];
		wsk_listy->x = START_X;
		wsk_listy->y = START_Y;
		wsk_listy->nast = wsk_listy->poprz = NULL;
	}

	// Dodanie elementów listy
	for (int i = 0; i < 4; i++)
		dodajElement();
}


Gracz::~Gracz()
{
	while (wsk_listy != NULL)
	{
		Lista* nast = wsk_listy->nast;
		delete wsk_listy;
		wsk_listy = nast;
	}
	delete[] graczSprite;
	delete animacjaCiala;
}

void Gracz::przejdzPrzezSciane()
{
	if (wsk_listy->x > KONIEC_X)
	{
		wsk_listy->x = START_X;
		dzwiekTeleport.play();
	}
	if (wsk_listy->y > KONIEC_Y)
	{
		wsk_listy->y = START_Y;
		dzwiekTeleport.play();
	}
	if (wsk_listy->x < START_X)
	{
		wsk_listy->x = KONIEC_X;
		dzwiekTeleport.play();
	}
	if (wsk_listy->y < START_Y)
	{
		wsk_listy->y = KONIEC_Y;
		dzwiekTeleport.play();
	}
}

bool Gracz::walnijPrzeszkode(Sprite * przeszkodaSprite,int liczbaPrzeszkod)
{
	for (int i = 0; i < liczbaPrzeszkod; i++)
	{
		if (kolizja(wsk_listy->sprite, przeszkodaSprite[i]))
		{
			dzwiekWalnieciePrzeszkody.play();
			return true;
		}
	}
	return false;
}

void Gracz::przejdzPrzezDziure(Sprite* dziuraSprite, int liczbaDziur)
{
	for (int i = 0; i < liczbaDziur; i++)
	{
		if (kolizja(wsk_listy->sprite, dziuraSprite[i]))
		{
			dzwiekTeleport.play();
			int k;
			if (i == 0) k = 1;
			else if (i == 1) k = 0;
			if (kierunek == 0) // DOL
			{
				wsk_listy->x = dziuraSprite[k].getPosition().x;
				wsk_listy->y = dziuraSprite[k].getPosition().y + 64.0f;
			}
			if (kierunek == 1) // LEWO
			{
				wsk_listy->x = dziuraSprite[k].getPosition().x - 64.0f;
				wsk_listy->y = dziuraSprite[k].getPosition().y;
			}
			if (kierunek == 2) // PRAWO
			{
				wsk_listy->x = dziuraSprite[k].getPosition().x + 64.0f;
				wsk_listy->y = dziuraSprite[k].getPosition().y;
			}
			if (kierunek == 3) // GORA
			{
				wsk_listy->x = dziuraSprite[k].getPosition().x;
				wsk_listy->y = dziuraSprite[k].getPosition().y - 64.0f;
			}
		}
	}
}

void Gracz::ruchGracza(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod)
{
	if (zegarDzwieki.getElapsedTime().asSeconds() >= 0.5f)
	{
		dzwiekKroki.play();
		zegarDzwieki.restart();
	}
	Lista* koniec = wsk_listy;
	przejdzNaKoniecListy(&koniec);
	while (koniec != NULL)
	{
		if (koniec->poprz != NULL)
		{
			koniec->x = koniec->poprz->x;
			koniec->y = koniec->poprz->y;

			if (koniec->sprite.getRotation() != koniec->poprz->sprite.getRotation())
				koniec->sprite.setRotation(koniec->poprz->sprite.getRotation());
		}
		koniec = koniec->poprz;
	}

	switch (kierunek)
	{
	case 0:
		wsk_listy->y += rozmiar_weza;
		break;

	case 1:
		wsk_listy->x -= rozmiar_weza;
		break;

	case 2:
		wsk_listy->x += rozmiar_weza;
		break;

	case 3:
		wsk_listy->y -= rozmiar_weza;
		break;
	}

	przejdzPrzezSciane();
	przejdzPrzezDziure(dziuraSprite, liczbaDziur);
}

void Gracz::sterowanie()
{
	float czas = zegarSterowania.getElapsedTime().asSeconds();
	float opoz = 0.15f;
	
	if (Keyboard::isKeyPressed(Keyboard::Left) && czas >= opoz)
	{
		if (kierunek == 2)return;
		kierunek = 1;
		wsk_listy->sprite.setRotation(90.0f);
		zegarSterowania.restart();
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && czas >= opoz)
	{
		if (kierunek == 1)return;
		kierunek = 2;
		wsk_listy->sprite.setRotation(-90.0f);
		zegarSterowania.restart();
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) && czas >= opoz)
	{
		if (kierunek == 0)return;
		kierunek = 3;
		wsk_listy->sprite.setRotation(180.0f);
		zegarSterowania.restart();
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && czas >= opoz)
	{
		if (kierunek == 3)return;
		kierunek = 0;
		wsk_listy->sprite.setRotation(0.0f);
		zegarSterowania.restart();
	}
}

void Gracz::obsluguj(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod)
{
	float czas = zegar.getElapsedTime().asSeconds() * mnoznikCzasu;
	zegar.restart();
	czasomierz += czas;

	sterowanie();
	if (czasomierz >= opoznienie)
	{
		czasomierz = 0;
		ruchGracza(dziuraSprite,liczbaDziur,przeszkodaSprite,liczbaPrzeszkod);
	}
}

bool Gracz::samoUkaszenie()
{
	Lista* wsk = wsk_listy->nast;
	while (wsk != NULL)
	{
		if ((wsk_listy->x == wsk->x) && (wsk_listy->y == wsk->y))
		{
			dzwiekWalniecieSiebie.play();
			return true;
		}

		wsk = wsk->nast;
	}
	return false;
}

void Gracz::rysuj(RenderWindow& okno)
{
	Lista* wsk = wsk_listy;
	while (wsk != NULL)
	{
		wsk->sprite.setPosition((float)wsk->x, (float)wsk->y);
		okno.draw(wsk->sprite);
		wsk = wsk->nast;
	}
}

void Gracz::zerujAnimacje()
{
	zegar.restart();
	czasomierz = 0.0f;
}

void Gracz::ochronaKolizji()
{
	if (NULL == animacjaCiala)
	{
		graczCialoTekstura.loadFromFile(tablicaStringCialoTekstura[TRANS][tekstura]);
		animacjaCiala = new Animacja(graczCialoTekstura, Vector2u(4, 1), 0.2f);
	}
	else
	{
		ustawTeksture = true;
		animacjaCiala->aktualizuj(0);
		Lista* wsk = wsk_listy->nast;
		while (wsk != NULL)
		{
			wsk->sprite.setTextureRect(animacjaCiala->obszar);
			wsk = wsk->nast;
		}
	}
}

void Gracz::ustawNowaTeksture()
{
	graczGlowaTekstura.loadFromFile(tablicaStringCialoTekstura[GLOWA][tekstura]);
	graczSprite[GLOWA].setTexture(graczGlowaTekstura);
	float rotacja = wsk_listy->sprite.getRotation();
	wsk_listy->sprite = graczSprite[GLOWA];
	wsk_listy->sprite.setRotation(rotacja);

	if (NULL != animacjaCiala)
	{
		delete animacjaCiala;
		graczCialoTekstura.loadFromFile(tablicaStringCialoTekstura[TRANS][tekstura]);
		animacjaCiala = new Animacja(graczCialoTekstura, Vector2u(4, 1), 0.2f);
	}
	else
	{
		graczCialoTekstura.loadFromFile(tablicaStringCialoTekstura[CIALO][tekstura]);
		graczSprite[CIALO].setTexture(graczCialoTekstura);
		graczSprite[CIALO].setTextureRect(IntRect(0, 0, 64, 64));

		Lista* wsk = wsk_listy->nast;
		while (wsk != NULL)
		{
			float rotacja = wsk->sprite.getRotation();
			wsk->sprite = graczSprite[CIALO];
			wsk->sprite.setRotation(rotacja);
			wsk = wsk->nast;
		}
	}
}

void Gracz::ustawTeksture100() // Po ochronaKolizji()
{
	if (ustawTeksture)
	{
		delete animacjaCiala;
		animacjaCiala = NULL;
		graczGlowaTekstura.loadFromFile(tablicaStringCialoTekstura[GLOWA][tekstura]);
		graczSprite[GLOWA].setTexture(graczGlowaTekstura);
		graczCialoTekstura.loadFromFile(tablicaStringCialoTekstura[CIALO][tekstura]);
		graczSprite[CIALO].setTexture(graczCialoTekstura);
		graczSprite[CIALO].setTextureRect(IntRect(0, 0, 64, 64));

		Lista* wsk = wsk_listy->nast;
		while (wsk != NULL)
		{
			float rotacja = wsk->sprite.getRotation();
			wsk->sprite = graczSprite[CIALO];
			wsk->sprite.setRotation(rotacja);
			wsk = wsk->nast;
		}
		ustawTeksture = false;
	}
}