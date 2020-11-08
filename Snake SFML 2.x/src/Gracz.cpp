#include "Gracz.h"

enum opis_gracz {GLOWA, CIALO};

void Gracz::przejdzNaKoniecListy(Lista** wsk)
{
	while ((*wsk)->nast != NULL)
		*wsk = (*wsk)->nast;
}

void Gracz::dodajElement()
{
	if (wsk_listy != NULL)
	{
		Lista* nowy_element = new Lista;
		if (nowy_element != NULL)
		{
			Lista* wsk = wsk_listy;
			przejdzNaKoniecListy(&wsk);
			graczCialoTekstura.loadFromFile(tablicaStringCialoTekstura[0][tekstura]);
			graczSprite[CIALO].setTexture(graczCialoTekstura);
			nowy_element->sprite = graczSprite[CIALO];
			nowy_element->sprite.setRotation(wsk->sprite.getRotation());
			nowy_element->y = wsk->y;
			nowy_element->x = wsk->x;
			wsk->nast = nowy_element;
			nowy_element->poprz = wsk;
		}
	}
}

Gracz::Gracz(int poziom)
{
	buforPrzeszkoda.loadFromFile("data/MuzykaDzwiekiGra/wazWkamien.ogg");
	buforTeleport.loadFromFile("data/MuzykaDzwiekiGra/teleport.wav");
	buforWaz.loadFromFile("data/MuzykaDzwiekiGra/wazWsiebie.ogg");

	tablicaKroki[0] = "data/MuzykaDzwiekiGra/stepdirt_1.wav";
	tablicaKroki[1] = "data/MuzykaDzwiekiGra/stepsnow_1.wav";
	tablicaKroki[2] = "data/MuzykaDzwiekiGra/stepstone_1.wav";

	buforKroki.loadFromFile(tablicaKroki[poziom]);

	dzwiekWalnieciePrzeszkody.setBuffer(buforPrzeszkoda);
	dzwiekTeleport.setBuffer(buforTeleport);
	dzwiekWalnieciePrzeszkody.setVolume(3.0f);
	dzwiekTeleport.setVolume(2.0f);
	dzwiekWalniecieSiebie.setBuffer(buforWaz);
	dzwiekWalniecieSiebie.setVolume(3.0f);
	dzwiekKroki.setBuffer(buforKroki);
	dzwiekKroki.setVolume(3.0f);

	tablicaStringCialoTekstura[0][0] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_green.png";
	tablicaStringCialoTekstura[0][1] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_grey.png";
	tablicaStringCialoTekstura[0][2] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_pink.png";
	tablicaStringCialoTekstura[0][3] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_cyan.png";
	tablicaStringCialoTekstura[0][4] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_blue.png";
	tablicaStringCialoTekstura[0][5] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_red.png";
	tablicaStringCialoTekstura[0][6] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_purple.png";
	tablicaStringCialoTekstura[0][7] = "data/Sprity do gry/Gracz i przedmioty/cialo/snake_cialo_yellow.png";

	tablicaStringCialoTekstura[1][0] = "data/Sprity do gry/Gracz i przedmioty/cialo80/snake_cialo_green.png";
	tablicaStringCialoTekstura[1][1] = "data/Sprity do gry/Gracz i przedmioty/cialo80/snake_cialo_grey.png";
	tablicaStringCialoTekstura[1][2] = "data/Sprity do gry/Gracz i przedmioty/cialo80/snake_cialo_pink.png";
	tablicaStringCialoTekstura[1][3] = "data/Sprity do gry/Gracz i przedmioty/cialo80/snake_cialo_cyan.png";
	tablicaStringCialoTekstura[1][4] = "data/Sprity do gry/Gracz i przedmioty/cialo80/snake_cialo_blue.png";
	tablicaStringCialoTekstura[1][5] = "data/Sprity do gry/Gracz i przedmioty/cialo80/snake_cialo_red.png";
	tablicaStringCialoTekstura[1][6] = "data/Sprity do gry/Gracz i przedmioty/cialo80/snake_cialo_purple.png";
	tablicaStringCialoTekstura[1][7] = "data/Sprity do gry/Gracz i przedmioty/cialo80/snake_cialo_yellow.png";
	
	tablicaStringCialoTekstura[2][0] = "data/Sprity do gry/Gracz i przedmioty/cialo60/snake_cialo_green.png";
	tablicaStringCialoTekstura[2][1] = "data/Sprity do gry/Gracz i przedmioty/cialo60/snake_cialo_grey.png";
	tablicaStringCialoTekstura[2][2] = "data/Sprity do gry/Gracz i przedmioty/cialo60/snake_cialo_pink.png";
	tablicaStringCialoTekstura[2][3] = "data/Sprity do gry/Gracz i przedmioty/cialo60/snake_cialo_cyan.png";
	tablicaStringCialoTekstura[2][4] = "data/Sprity do gry/Gracz i przedmioty/cialo60/snake_cialo_blue.png";
	tablicaStringCialoTekstura[2][5] = "data/Sprity do gry/Gracz i przedmioty/cialo60/snake_cialo_red.png";
	tablicaStringCialoTekstura[2][6] = "data/Sprity do gry/Gracz i przedmioty/cialo60/snake_cialo_purple.png";
	tablicaStringCialoTekstura[2][7] = "data/Sprity do gry/Gracz i przedmioty/cialo60/snake_cialo_yellow.png";
	
	tablicaStringCialoTekstura[3][0] = "data/Sprity do gry/Gracz i przedmioty/cialo40/snake_cialo_green.png";
	tablicaStringCialoTekstura[3][1] = "data/Sprity do gry/Gracz i przedmioty/cialo40/snake_cialo_grey.png";
	tablicaStringCialoTekstura[3][2] = "data/Sprity do gry/Gracz i przedmioty/cialo40/snake_cialo_pink.png";
	tablicaStringCialoTekstura[3][3] = "data/Sprity do gry/Gracz i przedmioty/cialo40/snake_cialo_cyan.png";
	tablicaStringCialoTekstura[3][4] = "data/Sprity do gry/Gracz i przedmioty/cialo40/snake_cialo_blue.png";
	tablicaStringCialoTekstura[3][5] = "data/Sprity do gry/Gracz i przedmioty/cialo40/snake_cialo_red.png";
	tablicaStringCialoTekstura[3][6] = "data/Sprity do gry/Gracz i przedmioty/cialo40/snake_cialo_purple.png";
	tablicaStringCialoTekstura[3][7] = "data/Sprity do gry/Gracz i przedmioty/cialo40/snake_cialo_yellow.png";
	
	tablicaStringCialoTekstura[4][0] = "data/Sprity do gry/Gracz i przedmioty/cialo20/snake_cialo_green.png";
	tablicaStringCialoTekstura[4][1] = "data/Sprity do gry/Gracz i przedmioty/cialo20/snake_cialo_grey.png";
	tablicaStringCialoTekstura[4][2] = "data/Sprity do gry/Gracz i przedmioty/cialo20/snake_cialo_pink.png";
	tablicaStringCialoTekstura[4][3] = "data/Sprity do gry/Gracz i przedmioty/cialo20/snake_cialo_cyan.png";
	tablicaStringCialoTekstura[4][4] = "data/Sprity do gry/Gracz i przedmioty/cialo20/snake_cialo_blue.png";
	tablicaStringCialoTekstura[4][5] = "data/Sprity do gry/Gracz i przedmioty/cialo20/snake_cialo_red.png";
	tablicaStringCialoTekstura[4][6] = "data/Sprity do gry/Gracz i przedmioty/cialo20/snake_cialo_purple.png";
	tablicaStringCialoTekstura[4][7] = "data/Sprity do gry/Gracz i przedmioty/cialo20/snake_cialo_yellow.png";

	tekstura = 0, poziomTekstury = 0;

	graczGlowaTekstura.loadFromFile("data/Sprity do gry/Gracz i przedmioty/snake_glowa12.png");
	graczCialoTekstura.loadFromFile(tablicaStringCialoTekstura[0][tekstura]);
	graczSprite = new Sprite[2];
	graczSprite[0].setTexture(graczGlowaTekstura);
	Rect<float> rozmiar = graczSprite[0].getGlobalBounds();
	graczSprite[0].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));

	graczSprite[1].setTexture(graczCialoTekstura);
	Rect<float> _rozmiar = graczSprite[1].getGlobalBounds();
	graczSprite[1].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));

	graczSprite[GLOWA].setScale(0.85f, 1.0f);
	graczSprite[CIALO].setScale(0.85f, 1.0f);

	czas = czasomierz = 0.0f;
	kierunek = 0;
	opoznienie = 0.1f;
	szybkosc = (float)graczGlowaTekstura.getSize().x;
	cout << szybkosc;

	// Tworzenie listy
	wsk_listy = new Lista;
	if (wsk_listy != NULL)
	{
		wsk_listy->sprite = graczSprite[GLOWA];
		wsk_listy->x = START_X;
		wsk_listy->y = START_Y;
		wsk_listy->nast = wsk_listy->poprz = NULL;
	}

	// Dodanie elementów listy
	for (int i = 0; i < 4; i++)
		dodajElement();
}


Gracz::~Gracz()
{
	while (wsk_listy != NULL)
	{
		Lista* nast = wsk_listy->nast;
		delete wsk_listy;
		wsk_listy = nast;
	}
	delete[] graczSprite;
}

void Gracz::przejdzPrzezSciane()
{
	if (wsk_listy->x > KONIEC_X)
	{
		wsk_listy->x = START_X;
		dzwiekTeleport.play();
	}
	if (wsk_listy->y > KONIEC_Y)
	{
		wsk_listy->y = START_Y;
		dzwiekTeleport.play();
	}
	if (wsk_listy->x < START_X)
	{
		wsk_listy->x = KONIEC_X;
		dzwiekTeleport.play();
	}
	if (wsk_listy->y < START_Y)
	{
		wsk_listy->y = KONIEC_Y;
		dzwiekTeleport.play();
	}
}

bool Gracz::walnijPrzeszkode(Sprite * przeszkodaSprite,int liczbaPrzeszkod)
{
	for (int i = 0; i < liczbaPrzeszkod; i++)
	{
		if (kolizja(wsk_listy->sprite, przeszkodaSprite[i]))
		{
			dzwiekWalnieciePrzeszkody.play();
			return true;
		}
	}
	return false;
}

void Gracz::przejdzPrzezDziure(Sprite* dziuraSprite, int liczbaDziur)
{
	for (int i = 0; i < liczbaDziur; i++)
	{
		if (kolizja(wsk_listy->sprite, dziuraSprite[i]))
		{
			dzwiekTeleport.play();
			int k;
			if (i == 0) k = 1;
			else if (i == 1) k = 0;
			if (kierunek == 0)
			{
				wsk_listy->x = dziuraSprite[k].getPosition().x;
				wsk_listy->y = dziuraSprite[k].getPosition().y + 64.0f;
			}
			if (kierunek == 1)
			{
				wsk_listy->x = dziuraSprite[k].getPosition().x - 64.0f;
				wsk_listy->y = dziuraSprite[k].getPosition().y;
			}
			if (kierunek == 2)
			{
				wsk_listy->x = dziuraSprite[k].getPosition().x + 64.0f;
				wsk_listy->y = dziuraSprite[k].getPosition().y;
			}
			if (kierunek == 3)
			{
				wsk_listy->x = dziuraSprite[k].getPosition().x;
				wsk_listy->y = dziuraSprite[k].getPosition().y - 64.0f;
			}
		}
	}
}

void Gracz::ruchGracza(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod)
{
	if (zegar2.getElapsedTime().asSeconds() >= 0.5f)
	{
		dzwiekKroki.play();
		zegar2.restart();
	}
	Lista* koniec = wsk_listy;
	przejdzNaKoniecListy(&koniec);
	while (koniec != NULL)
	{
		if (koniec->poprz != NULL)
		{
			koniec->x = koniec->poprz->x;
			koniec->y = koniec->poprz->y;

			if (koniec->sprite.getRotation() != koniec->poprz->sprite.getRotation())
				koniec->sprite.setRotation(koniec->poprz->sprite.getRotation());
		}
		koniec = koniec->poprz;
	}

	switch (kierunek)
	{
	case 0:
		wsk_listy->y += szybkosc;
		break;

	case 1:
		wsk_listy->x -= szybkosc;
		break;

	case 2:
		wsk_listy->x += szybkosc;
		break;

	case 3:
		wsk_listy->y -= szybkosc;
		break;
	}

	przejdzPrzezSciane();
	przejdzPrzezDziure(dziuraSprite, liczbaDziur);
}

void Gracz::sterowanie()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (kierunek == 2)return;
		kierunek = 1;
		wsk_listy->sprite.setRotation(90.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (kierunek == 1)return;
		kierunek = 2;
		wsk_listy->sprite.setRotation(-90.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (kierunek == 0)return;
		kierunek = 3;
		wsk_listy->sprite.setRotation(180.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		if (kierunek == 3)return;
		kierunek = 0;
		wsk_listy->sprite.setRotation(0.0f);
	}
}

void Gracz::obsluguj(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod)
{
	czas = zegar.getElapsedTime().asSeconds();
	zegar.restart();
	czasomierz += czas;
	if (czasomierz >= opoznienie)
	{
		czasomierz -= opoznienie;
		ruchGracza(dziuraSprite,liczbaDziur,przeszkodaSprite,liczbaPrzeszkod);
	}
	sterowanie();
}

bool Gracz::samoUkaszenie()
{
	dzwiekWalniecieSiebie.play();
	Lista* wsk = wsk_listy->nast;
	while (wsk != NULL)
	{
		if ((wsk_listy->x == wsk->x) && (wsk_listy->y == wsk->y))
			return true;

		wsk = wsk->nast;
	}
	return false;
}

void Gracz::rysuj(RenderWindow& okno)
{
	Lista* wsk = wsk_listy;
	while (wsk != NULL)
	{
		wsk->sprite.setPosition((float)wsk->x, (float)wsk->y);
		okno.draw(wsk->sprite);
		wsk = wsk->nast;
	}
}

void Gracz::zerujAnimacje()
{
	zegar.restart();
	czasomierz = 0.0f;
}

void Gracz::ochronaKolizji(Clock zegarAnimacji,int i,int j)
{
	float zmianaSkina = 2.0f;
	float deltaczas = zegarAnimacji.getElapsedTime().asSeconds();
	float calkowityczas = 0.0f;
	calkowityczas += deltaczas;
	if (calkowityczas >= zmianaSkina)
	{
		calkowityczas -= zmianaSkina;
		j++;
		if (j == 5) j = 0;
		graczCialoTekstura.loadFromFile(tablicaStringCialoTekstura[j][i]);
		poziomTekstury = j;
		zegarAnimacji.restart();
	}	
}

void Gracz::ustawTeksture100()
{
	poziomTekstury = 0;
	graczCialoTekstura.loadFromFile(tablicaStringCialoTekstura[poziomTekstury][tekstura]);
}