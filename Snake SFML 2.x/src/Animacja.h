/*! \file Animacja.h
*	\brief Zawiera definicje klasy Animacja
*/

//! \class Gracz
/*!	\class Animacja
*	\brief Klasa Animacji Sprite odpowiadajaca za animacje sprite pokarmow i weza
*/

/*!	\fn Animacja::Animacja(Texture& spriteTekstura, Vector2u liczbaObrazow, float czasZmiany)
*	\brief Konstruktor obiektu klasy Animacja
*	\param spriteTekstura
*	\brief Zmienna przechowujaca teksture do animacji.
*	\param liczbaObrazow
*	\brief Zmienna przechowujaca ilosc obrazkow animacji.
*	\param czasZmiany
*	\brief Zmienna przechowujaca czas w sekundach zmianu obrazkow animacji.
*/

/*!	\fn int Animacja::aktualizuj(int wiersz)
*	\brief Metoda klasy Animacja aktualizujaca animacje
*	\param wiersz
*	\brief Zmienna przechowujaca numer obrazku animacji w poziomie
*	\return int
*	\brief Zwraca pierwszy obrazek animacji
*/

/*!	\var IntRect Animacja::obszar
*	\brief Obiekt przechowujacy aktualny obrazek animacji
*/

/*!	\var Clock Animacja::zegar
*	\brief Zegar do pilnowania czasu miedzy animacjami
*/

/*!	\var float Animacja::calkowityCzas
*	\brief Zmienna pomocnicza przy animowaniu obrazkow
*/

/*!	\var float Animacja::czasZmiany
*	\brief Zmienna przechowujaca czas do zmiany obrazkow animacji
*/

/*!	\var float Animacja::deltaCzas
*	\brief Zmienna przechowujaca uplyniety czas zegara
*/

/*!	\var Vector2u Animacja::aktualnyObraz
*	\brief Zmienna przechowujaca wpolrzedne x , y aktualnego obrazku animacji
*/

/*!	\var Vector2u Animacja::liczbaObrazow
*	\brief Zmienna przechowujaca ilosc obrazkow animacji
*/

#pragma once
#include "Biblioteki.h"
class Gracz;
class Animacja
{
	float czasZmiany, deltaCzas;
	Vector2u aktualnyObraz, liczbaObrazow;

public:
	IntRect obszar;
	Clock zegar;
	float calkowityCzas;
public:
	Animacja(Texture& spriteTekstura, Vector2u liczbaObrazow, float czasZmiany);
	int aktualizuj(int wiersz);
};
