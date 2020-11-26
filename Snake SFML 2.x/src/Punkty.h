/*!	\file Punkty.h
*	\brief Plik ten zawiera klase Punkty
*/

/*!	\class Punkty
*	\brief Klasa ta ma za zadanie przechowywac wynik oraz kombo i je animowac.
*/

/*!	\var int Punkty::wartosc
*	\brief Zmienna przechowujaca wynik liczbowy gracza.
*/
/*!	\var float Punkty::kombo
*	\brief Zmienna przechowujaca kombo nabijanych punktow.
*/

/*!	\var Text Punkty::wyswietlPunkty
*	\brief Obiekt typu Text do wyswietlania punktow w formie tekstu na ekranie
*/
/*!	\var Text Punkty::wyswietlKombo
*	\brief Obiekt typu Text do wyswietlania kombo w formie tekstu na ekranie
*/

/*!	\var string Punkty::stringPunktow
*	\brief Zmienna lancuchowa przechowujaca liczbe punktow w formie tekstu
*/
/*!	\var string Punkty::stringKombo
*	\brief Zmienna lancuchowa przechowujaca kombo w formie tekstu
*/

/*!	\var Font Punkty::czcionka
*	\brief Obiekt typu Font przechowujacy typ czcionki tekstu punktow i kombo
*/

/*!	\fn Punkty::Punkty()
*	\brief Jest to konstruktor obiektu klasy Punkty
*	Jego zadaniem jest inicjalizowanie zmiennych oraz pozycji obiektow.
*/

/*!	\fn Punkty::~Punkty()
*	\brief Jest to dekonstruktor obiektu klasy Punkty
*/

/*!	\fn void Punkty::dodajPunkty(int parametr)
*	\brief Ta metoda ma za zadanie dodanie punktow do wartosci przechowywanej jako wartosc
*	\param parametr
*	\brief Ta zmienna przechowuje wartosc do dodania
*	\return void
*	\brief Nic nie zwraca
*/

/*!	\fn void Punkty::zmienKombo(float noweKombo)
*	\brief Ta metoda ma za zadanie dodanie kombo do wartosci przechowywanej jako kombo
*	\param noweKombo
*	\brief Ta zmienna przechowuje wartosc do dodania
*	\return void
*	\brief Nic nie zwraca
*/

/*!	\fn int Punkty::sprawdzWynik()
*	\brief Ta metoda ma za zadanie sprawdzic aktualny wynik i go zwrocic
*	\return int
*	\brief Zwraca wartosc wyniku jako liczbe
*/

/*!	\fn void Punkty::animujPunkty(int tryb)
*	\brief Ta metoda ma za zadanie animowac wyswietlany wynik
*	\param tryb
*	\brief Metoda otrzymuje 0 lub 1 i na tej podstawie animuje odpowiednio tekst wyniku
*	\return void
*	\brief Nic nie zwraca
*/
/*!	\fn void Punkty::animujKombo(int tryb)
*	\brief Ta metoda ma za zadanie animowac wyswietlane kombo
*	\param tryb
*	\brief Metoda otrzymuje 0 lub 1 i na tej podstawie animuje odpowiednio tekst kombo
*	\return void
*	\brief Nic nie zwraca
*/

#pragma once
#include "Biblioteki.h"
class Punkty
{
protected:
	int wartosc;
	float kombo;
	Text wyswietlPunkty,wyswietlKombo;
	string stringPunktow,stringKombo;
	Font czcionka;
public:
	Punkty();
	~Punkty();
	void dodajPunkty(int parametr);
	void zmienKombo(float noweKombo);
	int sprawdzWynik();
	void animujPunkty(int tryb);
	void animujKombo(int tryb);
};

