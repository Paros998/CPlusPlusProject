#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>
using namespace sf;using namespace std;

// STA£E
#define WYSOKOSC_PLANSZY 12
#define DLUGOSC_PLANSZY 24
#define START_X 200
#define START_Y 120
#define KONIEC_X START_X + (64 * (DLUGOSC_PLANSZY - 1))
#define KONIEC_Y START_Y + (64 * (WYSOKOSC_PLANSZY - 1))
#define ODSTEP 64.0
// Kolejne klasy
// ...
#include "Punkty.h"
#include "Animacja.h"
#include "Gracz.h"
#include "Pokarm.h"
#include "Gra.h"
#include "Poziom1.h"
#include "Menu.h"
#include "Aplikacja.h"

extern void losuj(float& zmienna, int parametr);
extern bool kolizja(Sprite s1, Sprite s2);
extern int losuj(int parametr);