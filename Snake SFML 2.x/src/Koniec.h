#pragma once
#include "Biblioteki.h"

struct ListaWynikow {
	string pseudonim;
	int wynikGracza;
	struct ListaWynikow* next;
};

class Koniec
{
public:
	string wpiszNick(RenderWindow &okno, Font& czcionka, Sprite& tloMapySprite);
	void wynikiTXT(string &pseudonim);
	struct ListaWynikow* wsk_wyniki;
};

 