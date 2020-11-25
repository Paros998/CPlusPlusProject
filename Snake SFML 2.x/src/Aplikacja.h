/*! \file Aplikacja.h
*	\brief Plik zawierajacy klase Aplikacja
*/
#pragma once
#include "Biblioteki.h"
enum dzialanie{MENU,P1,P2,P3};
//! Klasa aplikacji.
/*!
	\brief Klasa odpowiadajaca za wlaczenie gry w glownej funkcji gry.
*/
class Aplikacja
{
	RenderWindow oknoAplikacji;
public:
	//! Konstruktor klasy Aplikacja
	/*!
		\brief Konstruktor tworzacy obiekt.
		\n
		Konstruktor tworzy obiekt Aplikacja wraz z tworzeniem okna glownego typu RenderWindow o rozdzielczosci 1920x1080 i ustawia limit FPS na 60
	*/
	Aplikacja();
	//! Metoda start 
	/*! \brief Rozdziela Gre na 4 pod programy
	*	\n
		i tworzy odpowiednie obiekty oraz wywoluje dalsze funkcje gry.
	*	\return void
		\n
		Nic nie zwraca
	*/
	void start();
};

