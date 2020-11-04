#pragma once
#include "Biblioteki.h"
class Punkty
{
protected:
	int wartosc;
	float kombo;
	Text wyswietlPunkty,wyswietlKombo;
	string stringPunktow,stringKombo;
	Font czcionka;
public:
	Punkty();
	~Punkty();
	void dodajPunkty(int parametr);
	void zmienKombo(float noweKombo);
};

