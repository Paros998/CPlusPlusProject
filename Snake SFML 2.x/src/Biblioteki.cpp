#include "Biblioteki.h"

extern int skinWeza = 0, Wynik = 0;
extern float glosnoscMuzyki = 15.0f;

void losuj(float& zmienna, int parametr) { zmienna = rand() % parametr; }
int losuj(int parametr) { return rand() % parametr; }

bool kolizja(Sprite s1, Sprite s2) { return s1.getGlobalBounds().intersects(s2.getGlobalBounds()); }