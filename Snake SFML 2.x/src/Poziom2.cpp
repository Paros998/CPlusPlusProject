#include "Poziom2.h"


Poziom2::Poziom2()
	:Gra::Gra{ 20,P2 - 1,50 }
{
	tloMapyTekstura.loadFromFile("data/Sprity do gry/Plansza/tlo_2.jpg");
	tloMapyTekstura.setSmooth(true);
	tloMapySprite.setTexture(tloMapyTekstura);
	tloMapySprite.setPosition(0.0f, 0.0f);
	tloMapySprite.setScale(1.0f, 1.0f);
}

Poziom2::~Poziom2()
{
}

int Poziom2::start(RenderWindow& okno)
{
	return silnikPoziomu(okno, P2 - 1);
}