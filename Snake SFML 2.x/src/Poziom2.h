/*!	\file Poziom2.h
*	\brief Plik ten zawiera Klase Poziom2
*/

/*!	\class Poziom2 : Gra
*	\brief Ta klasa ma za zadanie tworzyc odpowiednia wersje Gra i uruchamiac silnik gry.
*/

/*!	\fn Poziom2::Poziom2()
*	\brief Jest to konstruktor obiektu klasy Poziom2
*	Ten konstruktor laduje odpowiednie tlo menu oraz tworzy obiekt Gra wg. odpowiednich parametrow.
*/

/*!	\fn Poziom2::~Poziom2()
*	\brief Jest to dekonstruktor obiektu klasy Poziom2
*/

/*!	\fn int Poziom2::start(RenderWindow& okno)
*	\brief Ta metoda uruchamia silnikPoziomu() i zwraca odpowiednia wartosc do Aplikacja.
*/
#pragma once
#include "Biblioteki.h"

class Poziom2 : public Gra
{
public:
	Poziom2();
	~Poziom2();
	int start(RenderWindow& okno);
};

