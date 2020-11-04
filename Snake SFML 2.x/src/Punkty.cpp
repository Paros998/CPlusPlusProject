#include "Biblioteki.h"
Punkty::Punkty()
{
	wartosc = 0;
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
}
void Punkty::zmienKombo(float noweKombo)
{
	kombo = noweKombo;
	stringKombo = "Combo:x";
	stringKombo += std::to_string(kombo);
}