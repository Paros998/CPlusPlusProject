#include "Poziom1.h"


Poziom1::Poziom1()
	:Gra::Gra{15,P1-1,50}
{
	tloMapyTekstura.loadFromFile("data/Sprity do gry/Plansza/tlo_1.jpg");
	tloMapyTekstura.setSmooth(true);
	tloMapySprite.setTexture(tloMapyTekstura);
	tloMapySprite.setPosition(0.0f, 0.0f);
	tloMapySprite.setScale(1.0f, 1.0f);
}

Poziom1::~Poziom1()
{
}

int Poziom1::start(RenderWindow& okno)
{
	return silnikPoziomu(okno,P1-1);
}