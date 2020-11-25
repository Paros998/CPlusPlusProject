/*!	\file Biblioteki.h
*	\brief Plik zawierajacy wszystkie potrzebne stale , pliki naglowkowe oraz globalne zmienne i funkcje .
*/

/*!	\def WYSOKOSC_PLANSZY 
	\brief Stala przechowujaca wysokosc planszy w kwadratach.
*/
/*!	\def DLUGOSC_PLANSZY 
*	\brief Stala przechowujaca dlugosc planszy w kwadratach.
*/

/*!	\def START_X 
*	\brief Stala przechowujaca pozycje x poczatku mapy w pixelach.
*/
/*!	\def START_Y 
*	\brief Stala przechowujaca pozycje y poczatku mapy w pixelach.
*/
/*!	\def KONIEC_X 
*	\brief Stala przechowujaca pozycje x konca mapy w pixelach.
*/
/*!	\def KONIEC_Y 
*	\brief Stala przechowujaca pozycje y konca mapy w pixelach.
*/

/*!	\def ODSTEP 
*	\brief Stala przechowujaca odstep miedzy kwadratami mapy w pixelach.
*/
/*!	\def ZLOTY 
*	\brief Stala przechowujaca kolor zloty w formie RGB i A.
*/	

/*!	\fn extern void losuj(float& zmienna, int parametr)
*	\brief Funkcja do losowania.
*	\param zmienna
*	\brief Zmienna do ktorej przypisywany jest wynik losowania.
*	\param parametr
*	\brief Zmienna ustalajaca zakres losowania.
*	\return void
*/

/*!	\fn extern bool kolizja(Sprite s1, Sprite s2)
*	\brief Funkcja sprawdzajaca kolizje obiektow
*	\param s1 
*	\brief Obiekt 1 do sprawdzenia kolizji miedzy obiektami.
*	\param s2 
*	\brief Obiekt 2 do sprawdzenia kolizji miedzy obiektami.
*	\return bool
*	\brief Zwraca true jesli wystapi kolizja, false jesli nie.
*/

/*!	\fn extern int losuj(int parametr)
*	\brief Funkcja do losowania.
*	\param parametr
*	\brief Zmienna ustalajaca zakres losowania.
*	\return int
*	\brief Zwraca wylosowana liczbe typu integer
*/
#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>
#include <time.h>
using namespace sf;using namespace std;

// STA£E
#define WYSOKOSC_PLANSZY 12
#define DLUGOSC_PLANSZY 24
#define START_X 200
#define START_Y 120
#define KONIEC_X START_X + (64 * (DLUGOSC_PLANSZY - 1))
#define KONIEC_Y START_Y + (64 * (WYSOKOSC_PLANSZY - 1))
#define ODSTEP 64.0

#define ZLOTY 255, 215, 0, 255
// Kolejne klasy
// ...
#include "Punkty.h"
#include "Koniec.h"
#include "Animacja.h"
#include "Gracz.h"
#include "Pokarm.h"
#include "Gra.h"
#include "Poziom3.h"
#include "Poziom2.h"
#include "Poziom1.h"
#include "Menu.h"
#include "Aplikacja.h"

/**
*	\brief Zmienna przechowujaca numer tekstury weza.
*/
extern int skinWeza;
/**
*	\brief Zmienna przechowujaca wynik gracza.
*/
extern int Wynik;
/**
*	\brief Zmienna przechowujaca poziom muzyki.
*/
extern float glosnoscMuzyki;
extern void losuj(float& zmienna, int parametr);
extern bool kolizja(Sprite s1, Sprite s2);
extern int losuj(int parametr);