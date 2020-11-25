#pragma once
#include "Biblioteki.h"

struct ListaWynikow {
	string pseudonim;
	int wynikGracza;
	struct ListaWynikow* next;
	ListaWynikow()
	{
		wynikGracza = 0;
		next = NULL;
	}
};

class Koniec
{
public:
	string wpiszNick(RenderWindow &okno, Font& czcionka, Sprite& tloMapySprite);
	void wynikiTXT(string &pseudonim);
	struct ListaWynikow* wsk_wyniki;
};

 