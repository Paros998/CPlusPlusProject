#include "Biblioteki.h"

float losuj()
{
	return 0.0f;
}

bool kolizja(Sprite s1, Sprite s2) { return s1.getGlobalBounds().intersects(s2.getGlobalBounds()); }