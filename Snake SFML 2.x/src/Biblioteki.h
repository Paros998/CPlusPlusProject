#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;using namespace std;
// Kolejne klasy
// ...
#include "Gracz.h"
#include "Gra.h"
#include "Poziom1.h"
#include "Menu.h"
#include "Aplikacja.h"

extern float losuj();
extern bool kolizja(Sprite s1, Sprite s2);