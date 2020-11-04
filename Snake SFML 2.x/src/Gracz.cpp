#include "Gracz.h"

enum opis_gracz {GLOWA, CIALO};

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

Gracz::Gracz()
{
	graczGlowaTekstura.loadFromFile("data/Sprity do gry/Gracz i przedmioty/snake_glowa.png");
	graczCialoTekstura.loadFromFile("data/Sprity do gry/Gracz i przedmioty/snake_cialo.png");

	graczSprite = new Sprite[2];
	graczSprite[0].setTexture(graczGlowaTekstura);
	Rect<float> rozmiar = graczSprite[0].getGlobalBounds();
	graczSprite[0].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));

	graczSprite[1].setTexture(graczCialoTekstura);
	Rect<float> _rozmiar = graczSprite[1].getGlobalBounds();
	graczSprite[1].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));
	czasomierz = kierunek = 0;
	opoznienie = 0.1f,czas = 0.0f;	
	szybkosc = 0.7f;

	// Tworzenie listy
	wsk_listy = new Lista;
	if (wsk_listy != NULL)
	{
		wsk_listy->sprite = graczSprite[GLOWA];
		wsk_listy->y = 1.34375f;
		wsk_listy->x = 2.625f;
		wsk_listy->nast = wsk_listy->poprz = NULL;
	}

	// Dodanie elementów listy
	for (int i = 0; i < 10; i++)
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
}

void Gracz::ruchGracza()
{
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
		wsk_listy->y += szybkosc;
		break;

	case 1:
		wsk_listy->x -= szybkosc;
		break;

	case 2:
		wsk_listy->x += szybkosc;
		break;

	case 3:
		wsk_listy->y -= szybkosc;
		break;
	}
}

void Gracz::sterowanie()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{	
		if (kierunek == 2)return;
		kierunek = 1;
		wsk_listy->sprite.setRotation(90.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{	
		if (kierunek == 1)return;
		kierunek = 2;
		wsk_listy->sprite.setRotation(-90.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{	
		if (kierunek == 0)return;
		kierunek = 3;
		wsk_listy->sprite.setRotation(180.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{	
		if (kierunek == 3)return;
		kierunek = 0;
		wsk_listy->sprite.setRotation(0.0f);
	}
}

void Gracz::obsluguj()
{	
	czas = zegar.getElapsedTime().asSeconds();
	zegar.restart();
	czasomierz += czas;
	if (czasomierz >= opoznienie)
	{
		czasomierz -= opoznienie;
		ruchGracza();
	}
	sterowanie();
}

void Gracz::rysuj(RenderWindow& okno)
{
	Lista* wsk = wsk_listy;
	while (wsk != NULL)
	{
		wsk->sprite.setPosition((float)wsk->x * 64, (float)wsk->y * 64);
		okno.draw(wsk->sprite);
		wsk = wsk->nast;
	}
}

