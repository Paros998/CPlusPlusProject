/*!	\file Poziom1.h
*	\brief Plik ten zawiera Klase Poziom1
*/

/*!	\class Poziom1 : Gra
*	\brief Ta klasa ma za zadanie tworzyc odpowiednia wersje Gra i uruchamiac silnik gry.
*/

/*!	\fn Poziom1::Poziom1()
*	\brief Jest to konstruktor obiektu klasy Poziom1
*	Ten konstruktor laduje odpowiednie tlo menu oraz tworzy obiekt Gra wg. odpowiednich parametrow.
*/

/*!	\fn Poziom1::~Poziom1()
*	\brief Jest to dekonstruktor obiektu klasy Poziom1
*/

/*!	\fn int Poziom1::start(RenderWindow& okno)
*	\brief Ta metoda uruchamia silnikPoziomu() i zwraca odpowiednia wartosc do Aplikacja.
*/
#pragma once
#include "Biblioteki.h"

class Poziom1 : public Gra
{
public:
	Poziom1();
	~Poziom1();
	int start(RenderWindow& okno);
};

