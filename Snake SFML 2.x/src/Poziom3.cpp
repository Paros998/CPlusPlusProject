/*!	\file Poziom3.cpp
*	\brief Plik ten zawiera ciala metod klasy Poziom3.
*/
#include "Poziom3.h"

Poziom3::Poziom3()
	:Gra::Gra{ 30,P3 - 1,100 }
{
	tloMapyTekstura.loadFromFile("data/Sprity do gry/Plansza/tlo_3.jpg");
	tloMapyTekstura.setSmooth(true);
	tloMapySprite.setTexture(tloMapyTekstura);
	tloMapySprite.setPosition(0.0f, 0.0f);
	tloMapySprite.setScale(1.0f, 1.0f);
}

Poziom3::~Poziom3()
{
}

int Poziom3::start(RenderWindow& okno)
{
	return silnikPoziomu(okno, P3 - 1);
}