#include "Gracz.h"

Gracz::Gracz()
{
	graczGlowaTekstura.loadFromFile("data/Sprity do gry/Gracz i przedmioty/snake_glowa.png");
	graczCialoTekstura.loadFromFile("data/Sprity do gry/Gracz i przedmioty/snake_cialo.png");
	graczSprite = new Sprite[2];
	graczSprite[0].setTexture(graczGlowaTekstura);
	graczSprite[1].setTexture(graczCialoTekstura);
	kierunek = 0;
	dlugoscGracza = 4;
	szybkosc = 0.7f;
}


Gracz::~Gracz()
{ 
	delete[] graczSprite; 
}

void Gracz::ruchGracza()
{
	for (int i = dlugoscGracza; i > 0; i--)
	{
		w��[i].x = w��[i - 1].x;
		w��[i].y = w��[i - 1].y;
	}

	switch (kierunek)
	{
	case 0:
		w��[0].y += szybkosc;
		graczSprite[0].setRotation(0.0f);
		break;
		
	case 1:
		w��[0].x -= szybkosc;
		graczSprite[0].setRotation(90.0f);
		break;

	case 2:
		w��[0].x += szybkosc;
		graczSprite[0].setRotation(-90.0f);
		break;

	case 3:
		w��[0].y -= szybkosc;
		graczSprite[0].setRotation(180.0f);
		break;
	}
}

void Gracz::sterowanie()
{
	if (Keyboard::isKeyPressed(Keyboard::Left)) kierunek = 1;
	if (Keyboard::isKeyPressed(Keyboard::Right)) kierunek = 2;
	if (Keyboard::isKeyPressed(Keyboard::Up)) kierunek = 3;
	if (Keyboard::isKeyPressed(Keyboard::Down)) kierunek = 0;
}

void Gracz::rysuj(RenderWindow& okno)
{
	for (int i = 1; i < dlugoscGracza; i++)
	{
		graczSprite[0].setPosition((float)w��[0].x * 60, (float)w��[0].y * 60);
		graczSprite[1].setPosition((float)w��[i].x * 60, (float)w��[i].y * 60);
		for (int j = 0; j < 2; j++)
			okno.draw(graczSprite[j]);
	}
}

