/*! \file Aplikacja.h
*	\brief Plik zawierajacy klase Aplikacja
*/

/*! \enum dzialanie{MENU,P1,P2,P3}
*	\brief Typ wyliczeniowy do metody Aplikacja::start() okreslajacy wywolywana funkcje gry.
*/

/*!	\class Aplikacja
*	\brief Klasa odpowiadajaca za wlaczenie gry w glownej funkcji gry.
*	\var RenderWindow Aplikacja::oknoAplikacji
*	\brief Zmienna przechowujaca okno do rysowania elementow 2D
*/

/*!	\fn Aplikacja::Aplikacja()
*	\brief Konstruktor klasy Aplikacja tworzacy obiekt.
*	\n
*	Konstruktor tworzy obiekt Aplikacja wraz z tworzeniem okna glownego typu RenderWindow o rozdzielczosci 1920x1080 i ustawia limit FPS na 60
*/

/*! \fn Aplikacja::start()
*	\brief Rozdziela Gre na 4 pod programy
*	\n
*	i tworzy odpowiednie obiekty oraz wywoluje dalsze funkcje gry.
*	\return void
*/

#pragma once
#include "Biblioteki.h"
enum dzialanie{MENU,P1,P2,P3};
class Aplikacja
{	
	RenderWindow oknoAplikacji;
public:
	Aplikacja();
	void start();
};

