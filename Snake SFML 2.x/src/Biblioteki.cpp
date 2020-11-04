#include "Biblioteki.h"

void losuj(float& zmienna, int parametr) { zmienna = rand() % parametr; }
int losuj(int parametr) { return rand() % parametr; }

bool kolizja(Sprite s1, Sprite s2) { return s1.getGlobalBounds().intersects(s2.getGlobalBounds()); }