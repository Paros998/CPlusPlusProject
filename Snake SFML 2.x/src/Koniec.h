/*!	\file Koniec.h
*	\brief Plik ten zawiera definicje struktury ListaWynikow oraz klase Koniec.
*/

/*!	\struct ListaWynikow
*	\brief Lista_pomocnicza do wprowadzania danych do wyniki.txt.
*/

/*!	\fn ListaWynikow::ListaWynikow()
*	\brief Konstruktor obiektu typu ListaWynikow.
* 
*	Ustawia pseudonim na puste znaki
*	oraz wynikGracza na 0 i wskaznik na kolejna miejsce w liscie na NULL.
*/

/*!	\class Koniec
*	\brief Klasa do wprowadzania nicku gracza oraz manipulacji lista wynikow.
*/

/*!	\fn Koniec::Koniec()
*	\brief Jest to konstrukto obiektu typu Koniec
*	Ustawia wskaznik zmiennej wskaznikowej wsk_wyniki na NULL
*/

/*!	\fn string Koniec::wpiszNick(RenderWindow &okno, Font& czcionka, Sprite& tloMapySprite)
*	\brief Metoda ta odpowiada za umozliwienie graczowi wpisanie swojego nicku/pseudonimu
*	\param okno
*	\brief okno to referencja na obiekt typu RenderWindow glownego okna aplikacji
*	\param czcionka
*	\brief czcionka to referencja na obiekty typu Font przechowujacy typ czcionki dla wyswietlanego tekstu
*	\param tloMapySprite
*	\brief tloMapySprite jest to referencja na obiekt typu Sprite przechowujaca tlo danego poziomu
*	\return string
*	\brief Metoda ta zwraca pseudonim gracza
*/

/*!	\fn void Koniec::wynikiTXT(string &pseudonim)
*	\brief Metoda ta umozliwia znalezienie odpowiedniego miejsca w liscie wynikow.
*	Oraz wpisuje 5 najlepszych wynikow do pliku wynikowego gry.
*	\param pseudonim
*	\brief pseudonim jest to referencja na zmienna lancuchowo znakow 
*	odpowiadajaca za przechowywanie nicku/pseudonimu gracza.
*	\return void
*	\brief Metoda nic nie zwraca
*/

/*!	\var struct ListaWynikow* Koniec::wsk_wyniki
*	\brief Zmienna ta przechowuje wskaznik na 1 poprawnie wypelniony element w liscie wynikow
*/

/*!	\var string ListaWynikow::pseudonim
*	\brief Zmienna przechowuje w formie lancucha znakow nick/pseudonim gracza
*/
/*!	\var int ListaWynikow::wynikGracza
*	\brief Zmienna przechowuje wynik gracza
*/
/*!	\var struct ListaWynikow* ListaWynikow::next
*	\brief Zmienna przechowuje wskaznik na kolejny element listy
*/

#pragma once
#include "Biblioteki.h"

struct ListaWynikow {
	string pseudonim;
	int wynikGracza;
	struct ListaWynikow* next;
	ListaWynikow()
	{	
		pseudonim = "";
		wynikGracza = 0;
		next = NULL;
	}
};

class Koniec
{
public:
	Koniec();
	string wpiszNick(RenderWindow &okno, Font& czcionka, Sprite& tloMapySprite);
	void wynikiTXT(string &pseudonim);
	struct ListaWynikow* wsk_wyniki;
};

 