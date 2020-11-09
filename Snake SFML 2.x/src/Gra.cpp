#include "Biblioteki.h"

enum opis_planszy { PIERWSZA_KRATKA, DRUGA_KRATKA,RAMKA };

Gra::Gra(int liczbaprzeszkod,int poziom)
{	
	tablicaMuzyka[0] = "data/MuzykaDzwiekiGra/muzykaPoziom1.ogg";
	tablicaMuzyka[1] = "data/MuzykaDzwiekiGra/muzykaPoziom2.ogg";
	tablicaMuzyka[2] = "data/MuzykaDzwiekiGra/muzykaPoziom3.ogg";

	muzykaGra.openFromFile(tablicaMuzyka[poziom]);
	muzykaGra.setVolume(glosnoscMuzyki);

	buforJedzenie.loadFromFile("data/MuzykaDzwiekiGra/jedzenieJablko.wav");
	dzwiekJedzenie.setBuffer(buforJedzenie);
	dzwiekJedzenie.setVolume(10.0f);

	srand(time(0));
	rdzenie = thread::hardware_concurrency();
	cout <<"\nIlosc dostepnych rdzeni: " << rdzenie <<"\n";
	planszaSprite = NULL;
	wyborPauza = 0;
	tablicaTekstur = new String[8];

	wysokoscPlanszy = WYSOKOSC_PLANSZY;
	dlugoscPlanszy = DLUGOSC_PLANSZY;
	odstep = ODSTEP;

	tablicaTekstur[0] = "data/Sprity do gry/Plansza/kamien1.png";
	tablicaTekstur[1] = "data/Sprity do gry/Plansza/trawa1.png";
	tablicaTekstur[2] = "data/Sprity do gry/Plansza/snieg1.png";
	tablicaTekstur[3] = "data/Sprity do gry/Plansza/kamien2.png";
	tablicaTekstur[4] = "data/Sprity do gry/Plansza/trawa2.png";
	tablicaTekstur[5] = "data/Sprity do gry/Plansza/kamien3.png";
	tablicaTekstur[6] = "data/Sprity do gry/Plansza/trawa3.png";
	tablicaTekstur[7] = "data/Sprity do gry/Plansza/kamien4.png";

	tablicaTeksturPrzeszkod[0] = "data/Sprity do gry/Plansza/przeszkoda.png";
	tablicaTeksturPrzeszkod[1] = "data/Sprity do gry/Plansza/przeszkoda1.png";
	tablicaTeksturPrzeszkod[2] = "data/Sprity do gry/Plansza/przeszkoda2.png";	

	dziuraTekstura.loadFromFile("data/Sprity do gry/Plansza/dziura.png");
	dziuraTekstura.setSmooth(true);

	planszaSprite = new Sprite * [wysokoscPlanszy];
	for (int i = 0; i < wysokoscPlanszy; i++)
	{
		planszaSprite[i] = new Sprite[dlugoscPlanszy];
	}

	ramkaSprite = new Sprite * [wysokoscPlanszy +2];
	for (int i = 0; i < wysokoscPlanszy +2; i++)
	{
		ramkaSprite[i] = new Sprite[dlugoscPlanszy+2];
	}

	if (poziom == 0)
	{
		planszaTekstura[PIERWSZA_KRATKA].loadFromFile(tablicaTekstur[0]);
		planszaTekstura[PIERWSZA_KRATKA].setSmooth(true);
		planszaTekstura[DRUGA_KRATKA].loadFromFile(tablicaTekstur[1]);
		planszaTekstura[DRUGA_KRATKA].setSmooth(true);
		planszaTekstura[RAMKA].loadFromFile(tablicaTekstur[4]);
		planszaTekstura[RAMKA].setSmooth(true);

	}
	else if (poziom == 1)
	{
		planszaTekstura[PIERWSZA_KRATKA].loadFromFile(tablicaTekstur[2]);
		planszaTekstura[PIERWSZA_KRATKA].setSmooth(true);
		planszaTekstura[DRUGA_KRATKA].loadFromFile(tablicaTekstur[3]);
		planszaTekstura[DRUGA_KRATKA].setSmooth(true);
		planszaTekstura[RAMKA].loadFromFile(tablicaTekstur[5]);
		planszaTekstura[RAMKA].setSmooth(true);
	}
	else if (poziom == 2)
	{
		planszaTekstura[PIERWSZA_KRATKA].loadFromFile(tablicaTekstur[5]);
		planszaTekstura[PIERWSZA_KRATKA].setSmooth(true);
		planszaTekstura[DRUGA_KRATKA].loadFromFile(tablicaTekstur[7]);
		planszaTekstura[DRUGA_KRATKA].setSmooth(true);
		planszaTekstura[RAMKA].loadFromFile(tablicaTekstur[2]);
		planszaTekstura[RAMKA].setSmooth(true);
	}

	przeszkodaTekstura[0].loadFromFile(tablicaTeksturPrzeszkod[0]);
	przeszkodaTekstura[0].setSmooth(true);

	przeszkodaTekstura[1].loadFromFile(tablicaTeksturPrzeszkod[1]);
	przeszkodaTekstura[1].setSmooth(true);

	przeszkodaTekstura[2].loadFromFile(tablicaTeksturPrzeszkod[2]);
	przeszkodaTekstura[2].setSmooth(true);


	this->liczbaPrzeszkod = liczbaprzeszkod;
	przeszkodaSprite = new Sprite[liczbaPrzeszkod];

	tablicaX = new int[liczbaPrzeszkod];
	tablicaY = new int[liczbaPrzeszkod];
	tablicaJ = new int[liczbaPrzeszkod];

	RdzenPlansza = thread([&]() {obliczPozycje(); });
	RdzenPlansza.join();

	for (int i = 0; i < 2; i++)
	{
		menuPauzy[i].setFont(czcionka);
		menuPauzy[i].setCharacterSize(100);
		menuPauzy[i].setFillColor(Color::Black);
		menuPauzy[i].setOutlineColor(Color::Red);
		menuPauzy[i].setOutlineThickness(1.0f);
		menuPauzy[i].setScale(1.0f, 1.0f);
	}
	int znaki = 0;
	string linia = "Wróc do gry";
	znaki = linia.length();
	menuPauzy[0].setString("Wróc do gry");
	menuPauzy[0].setPosition(884.0f - (znaki * 20), 350);
	linia = "Zakoñcz";
	znaki = linia.length();
	menuPauzy[1].setString("Zakoñcz");
	menuPauzy[1].setPosition(884.0f - (znaki * 20), 550);
	
	delete[] tablicaX;
	delete[] tablicaY;
	delete[] tablicaJ;
}

Gra::~Gra()
{
	delete[] tablicaTekstur;

	for (int i = 0; i < wysokoscPlanszy; i++)
	{
		delete[] planszaSprite[i];
	}
	delete[] planszaSprite;

	for (int i = 0; i < wysokoscPlanszy +2; i++)
	{
		delete[] ramkaSprite[i];
	}
	delete[] ramkaSprite;

	delete[] przeszkodaSprite;
	
}

void Gra::obliczPozycje()
{	
	srand(time(0));
	for (unsigned int i = 0; i < dlugoscPlanszy; i++)
		for (unsigned int j = 0; j < wysokoscPlanszy; j++)
		{
			float x = ((float)i * odstep) + 200.0f, y = ((float)j * odstep) + 120.0f;
			if (((j & 1) == 1) ^ ((i & 1) == 1)) // Szachownica
			{
				planszaSprite[j][i].setTexture(planszaTekstura[0]);
				planszaSprite[j][i].setScale(1.0f, 1.0f);
				planszaSprite[j][i].setPosition(x, y);
				Rect<float> rozmiar = planszaSprite[j][i].getGlobalBounds();
				planszaSprite[j][i].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));

			}
			else
			{
				planszaSprite[j][i].setTexture(planszaTekstura[1]);
				planszaSprite[j][i].setScale(1.0f, 1.0f);
				planszaSprite[j][i].setPosition(x, y);
				Rect<float> rozmiar = planszaSprite[j][i].getGlobalBounds();
				planszaSprite[j][i].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));
			}
		}

	for (unsigned int i = 0; i < dlugoscPlanszy + 2; i++)
		for (unsigned int j = 0; j < wysokoscPlanszy + 2; j++)
		{
			float x = ((float)i * odstep) + 136.0f, y = ((float)j * odstep) + 56.0f;
			if (j == 0 || j == (12 + 1))
			{
				ramkaSprite[j][i].setTexture(planszaTekstura[2]);
				ramkaSprite[j][i].setScale(1.0f, 1.0f);
				ramkaSprite[j][i].setPosition(x, y);
				Rect<float> rozmiar = ramkaSprite[j][i].getGlobalBounds();
				ramkaSprite[j][i].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));

			}
			else if (j != 0 && i == 0 || i == (24 + 1))
			{
				ramkaSprite[j][i].setTexture(planszaTekstura[2]);
				ramkaSprite[j][i].setScale(1.0f, 1.0f);
				ramkaSprite[j][i].setPosition(x, y);
				Rect<float> rozmiar = ramkaSprite[j][i].getGlobalBounds();
				ramkaSprite[j][i].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));
			}
		}

	for (int i = 0; i < 2; i++)
	{
		dziuraSprite[i].setTexture(dziuraTekstura);
		dziuraSprite[i].setScale(1.0f, 1.0f);
		float x = ((float)(i + 1) * 8 * odstep) + 168.0f, y = ((float)(i + 1) * 4 * odstep) + 88.0f;
		dziuraSprite[i].setPosition(x + 32.0f, y + 32.0f);
		Rect<float> rozmiar = dziuraSprite[i].getGlobalBounds();
		dziuraSprite[i].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));
	}
	int z;
	for (z = 0; z < liczbaPrzeszkod; z++)
	{
		tablicaX[z] = losuj(24);
		tablicaY[z] = losuj(12);
		miejsce1:
		while (tablicaX[z] == 8 && tablicaY[z] == 4)
		{
			tablicaX[z] = losuj(24);
			tablicaY[z] = losuj(12);
		}
		while (tablicaX[z] == 16 && tablicaY[z] == 8)
		{
			tablicaX[z] = losuj(24);
			tablicaY[z] = losuj(12);
			goto miejsce1;
		}
		tablicaJ[z] = losuj(3);
		for (int w = 0; w < z; w++)
		{
			if ((tablicaX[w] == tablicaX[z]) && (tablicaY[w] == tablicaY[z]))
			{
				tablicaX[z] = losuj(24);
				tablicaY[z] = losuj(12);
				goto miejsce1;
			}
		}
	}
	
	
	for (int i = 0; i < liczbaPrzeszkod; i++)
	{
		int x = tablicaX[i];
		int y = tablicaY[i];
		int j = tablicaJ[i];
		przeszkodaSprite[i].setTexture(przeszkodaTekstura[j]);
		przeszkodaSprite[i].setScale(1.0f, 1.0f);
		przeszkodaSprite[i].setPosition(planszaSprite[y][x].getPosition().x, planszaSprite[y][x].getPosition().y);
		Rect<float> rozmiar = przeszkodaSprite[i].getGlobalBounds();
		przeszkodaSprite[i].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));
	}
}

int Gra::pauza(RenderWindow& okno)
{	
	while (true)
	{
		okno.draw(menuPauzy[0]);
		okno.draw(menuPauzy[1]);
		Event zdarzenie;
		while (okno.pollEvent(zdarzenie))
		{
			for (int i = 0; i < 2; i++)
			{
				menuPauzy[i].setFillColor(Color::Black);
				menuPauzy[i].setOutlineColor(Color::Red);
			}
			menuPauzy[wyborPauza].setFillColor(Color::Red);
			menuPauzy[wyborPauza].setOutlineColor(Color::Black);

			switch (zdarzenie.type)
			{
			case Event::Closed:
				okno.close();
				break;
			case Event::KeyPressed:
				if (zdarzenie.key.code == Keyboard::Escape)
				{
					return 0;
				}
				if (zdarzenie.key.code == Keyboard::Up)
				{
					if (wyborPauza == 0) continue;
					wyborPauza = 0;
					break;
				}
				if (zdarzenie.key.code == Keyboard::Down)
				{
					if (wyborPauza == 1) continue;
					wyborPauza = 1;
					break;
				}
				if (zdarzenie.key.code == Keyboard::Enter)
				{
					if (wyborPauza == 0) return 0;
					if (wyborPauza == 1) return 1;
					break;
				}
			}
		}
		okno.display();
	}
}

void Gra::rysujPlansze(RenderWindow& okno)
{
	okno.draw(tloMapySprite);
	okno.draw(wyswietlKombo);
	okno.draw(wyswietlPunkty);

	if (planszaSprite != NULL && ramkaSprite != NULL)
	{
		for (unsigned int i = 0; i < dlugoscPlanszy; i++)
			for (unsigned int j = 0; j < wysokoscPlanszy; j++)
			{
				okno.draw(planszaSprite[j][i]);
			}
		for (unsigned int i = 0; i < dlugoscPlanszy +2; i++)
			for (unsigned int j = 0; j < wysokoscPlanszy +2; j++)
			{
				if (j == 0 || j == (wysokoscPlanszy + 1))
				{
					okno.draw(ramkaSprite[j][i]);
				}
				else if (j != 0  && i == 0 ||  i == (dlugoscPlanszy +1))
				{
					okno.draw(ramkaSprite[j][i]);
				}
			}
		for (int i = 0; i < liczbaPrzeszkod; i++)
		{	
			
			okno.draw(przeszkodaSprite[i]);
		}
		for (int i = 0; i < 2; i++)
		{
			okno.draw(dziuraSprite[i]);
		}
	}
}

bool Gra::przegrana(Gracz& gracz, Clock zegar)
{
	if (zegar.getElapsedTime().asSeconds() > 5.0f)
	{
		if (gracz.samoUkaszenie())
			return false;
		if (gracz.walnijPrzeszkode(przeszkodaSprite, liczbaPrzeszkod))
			return false;
	}
	return true;
}

bool Gra::silnikPoziomu(RenderWindow& okno,int poziom)
{	
	muzykaGra.play();
	muzykaGra.setLoop(true);

	float czasOdJedzenia = 0.0f, czasomierz = 0.0f, milisekunda = 1.0 / 60.0,czasOdAP = 0.0f,czasOdAK = 0.0f, aktualnyCzasOchrony = 0.0f,poprzedniCzasOchrony = 0.0f;
	Gracz gracz(poziom);
	Pokarm pokarm("data/Sprity do gry/Gracz i przedmioty/jablko_animacja2.png");
	Pokarm pokarmzloty("data/Sprity do gry/Gracz i przedmioty/jablko_animacja2-gold.png");
	pokarmzloty.bonus = 1;
	pokarmzloty.wartoscPunktow = 500;
	Pokarm *wskaznikNaPokarm = &pokarm;
	Punkty punkty;
	bool pauzaFlaga = false;
	int koniec = 0,iloscKombo = 0;
	Clock zegarJedzenia, zegarRysowania, zegarOchronyOdrodzenia,zegarAnimacjiPunkty,zegarAnimacjiKombo,zegarAnimacjiWeza;
	wskaznikNaPokarm->ustawPokarm(gracz,planszaSprite,przeszkodaSprite,liczbaPrzeszkod);
	while (okno.isOpen())
	{
		Event zdarzenie;
		while (okno.pollEvent(zdarzenie))
		{
			switch (zdarzenie.type)
			{
			case Event::Closed:
				okno.close();
				break;
			case Event::KeyPressed:
				if (zdarzenie.key.code == Keyboard::Escape)
				{
					koniec = 2;
					while (koniec == 2)
					{
						pauzaFlaga = true;
						koniec = pauza(okno);
						wskaznikNaPokarm->wyzerujAnimacje();
						gracz.zerujAnimacje();
					}
					if (koniec == 0)
					{
						pauzaFlaga = false;
						break;
					}
					if (koniec == 1)return false;
				}
			}
		}
		czasomierz = zegarRysowania.getElapsedTime().asMilliseconds();
		if (czasomierz >= milisekunda)
		{
			// POKARM
			if (wskaznikNaPokarm->sprawdzCzyZjedzony(gracz, planszaSprite, przeszkodaSprite, liczbaPrzeszkod) == true)
			{	
				dzwiekJedzenie.play();
				czasOdJedzenia = zegarJedzenia.getElapsedTime().asSeconds();
				if (wskaznikNaPokarm->bonus == 1) zegarOchronyOdrodzenia.restart();
				if (czasOdJedzenia <= 2.0)
				{
					zmienKombo(0.25);
					iloscKombo++;
					if (iloscKombo >= 5)
					{
						wskaznikNaPokarm = &pokarmzloty;
						wskaznikNaPokarm->ustawPokarm(gracz, planszaSprite, przeszkodaSprite, liczbaPrzeszkod);
					}
					else
					{
						wskaznikNaPokarm = &pokarm;
						wskaznikNaPokarm->ustawPokarm(gracz, planszaSprite, przeszkodaSprite, liczbaPrzeszkod);
					}
					zegarAnimacjiKombo.restart();
					animujKombo(0);
				}
				else
				{
					iloscKombo = 0;
				}
				zegarAnimacjiPunkty.restart();
				dodajPunkty(wskaznikNaPokarm->wartoscPunktow);
				animujPunkty(0);
				
				int wynik = sprawdzWynik();
				if (wynik >= 20000 && wynik <= 159999)
				{
					gracz.tekstura = (wynik / 20000);	
				}

				czasOdJedzenia = 0.0f;
				zegarJedzenia.restart();
			}

			czasOdAK = zegarAnimacjiKombo.getElapsedTime().asSeconds();
			if (czasOdAK >= 2.0f) animujKombo(1);

			czasOdAP = zegarAnimacjiPunkty.getElapsedTime().asSeconds();
			if (czasOdAP >= 2.0f) animujPunkty(1);

			// GRACZ
			gracz.obsluguj(dziuraSprite, 2, przeszkodaSprite, liczbaPrzeszkod);
			//if (!przegrana(gracz, zegarOchronyOdrodzenia))
			//	return false;
			aktualnyCzasOchrony = zegarOchronyOdrodzenia.getElapsedTime().asSeconds();
			if (aktualnyCzasOchrony <= 5.0f)
			{
				gracz.ochronaKolizji();
			}
			else
			{
				gracz.ustawTeksture100();
			}
			// RYSOWANIE
			okno.clear(Color::Blue);
			rysujPlansze(okno);
			gracz.rysuj(okno);
			wskaznikNaPokarm->rysuj(okno);
			czasomierz -= milisekunda;
		}
		okno.display();
	}
	return false;
}