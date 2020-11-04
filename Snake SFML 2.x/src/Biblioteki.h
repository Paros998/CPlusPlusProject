#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;using namespace std;
#define WYSOKOSC_PLANSZY 12
#define DLUGOSC_PLANSZY 24
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