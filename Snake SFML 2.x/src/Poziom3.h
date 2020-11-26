/*!	\file Poziom3.h
*	\brief Plik ten zawiera Klase Poziom1
*/

/*!	\class Poziom3 : Gra
*	\brief Ta klasa ma za zadanie tworzyc odpowiednia wersje Gra i uruchamiac silnik gry.
*/

/*!	\fn Poziom3::Poziom3()
*	\brief Jest to konstruktor obiektu klasy Poziom3
*	Ten konstruktor laduje odpowiednie tlo menu oraz tworzy obiekt Gra wg. odpowiednich parametrow.
*/

/*!	\fn Poziom3::~Poziom3()
*	\brief Jest to dekonstruktor obiektu klasy Poziom3
*/

/*!	\fn int Poziom3::start(RenderWindow& okno)
*	\brief Ta metoda uruchamia silnikPoziomu() i zwraca odpowiednia wartosc do Aplikacja.
*/
#pragma once
#include "Biblioteki.h"

class Poziom3 : public Gra
{
public:
	Poziom3();
	~Poziom3();
	int start(RenderWindow& okno);
};
