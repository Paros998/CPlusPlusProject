#include "Biblioteki.h"
Punkty::Punkty()
{
	wartosc = Wynik;
	kombo = 1.0f;

	stringPunktow = "Wynik: ";
	stringPunktow += std::to_string(wartosc);
	stringKombo = "Combo: x";
	stringKombo += std::to_string(kombo);

	czcionka.loadFromFile("data/Czcionki/ink-free-normal.ttf");

	wyswietlPunkty.setFont(czcionka);
	wyswietlKombo.setFont(czcionka);

	wyswietlPunkty.setCharacterSize(40);
	wyswietlKombo.setCharacterSize(40);

	wyswietlPunkty.setString(stringPunktow);
	wyswietlKombo.setString(stringKombo);

	wyswietlPunkty.setFillColor(Color::Black);
	wyswietlKombo.setFillColor(Color::Black);

	wyswietlPunkty.setOutlineColor(Color::Red);
	wyswietlKombo.setOutlineColor(Color::Red);

	wyswietlPunkty.setOutlineThickness(1.0f);
	wyswietlKombo.setOutlineThickness(1.0f);

	int znaki = 0;
	znaki = stringKombo.length();
	wyswietlPunkty.setPosition(104.0f, 920.0f);
	wyswietlKombo.setPosition(1768.0f - (znaki * 20), 920.0f);
}
Punkty::~Punkty()
{}
void Punkty::dodajPunkty(int parametr)
{
	wartosc += parametr * kombo;
	stringPunktow = "Wynik:";
	stringPunktow += std::to_string(wartosc);
	wyswietlPunkty.setString(stringPunktow);	
}
void Punkty::zmienKombo(float noweKombo)
{
	kombo += noweKombo;
	stringKombo = "Combo:x";
	stringKombo += std::to_string(kombo);
	wyswietlKombo.setString(stringKombo);
}
int Punkty::sprawdzWynik()
{
	return wartosc;
}

void Punkty::animujPunkty(int i)
{
	if (i == 0)
	{
		wyswietlPunkty.setOutlineColor(Color::Black);
		wyswietlPunkty.setFillColor(Color(ZLOTY));
	}
	if (i == 1)
	{
		wyswietlPunkty.setOutlineColor(Color::Red);
		wyswietlPunkty.setFillColor(Color::Black);
	}
}
void Punkty::animujKombo(int i)
{
	if (i == 0)
	{
		wyswietlKombo.setOutlineColor(Color::Black);
		wyswietlKombo.setFillColor(Color(ZLOTY));
	}
	if (i == 1)
	{
		wyswietlKombo.setOutlineColor(Color::Red);
		wyswietlKombo.setFillColor(Color::Black);
	}
}