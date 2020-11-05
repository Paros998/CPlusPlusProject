#include "Biblioteki.h"

enum opis_planszy { PIERWSZA_KRATKA, DRUGA_KRATKA,RAMKA };

Gra::Gra(int liczbaprzeszkod)
{

	planszaSprite = NULL;
	odstep = 64;
	wysokoscPlanszy = 12;
	dlugoscPlanszy = 24;
	wyborPauza = 0;
	tablicaTekstur = new String[8];

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

	planszaSprite = new Sprite[3];

	int jeden = 0, dwa = 0, trzy = 0;
	jeden = losuj(8);
	while (dwa == jeden)	dwa = losuj(8);
	while (trzy == dwa || trzy == jeden) trzy = losuj(8);
	planszaTekstura[PIERWSZA_KRATKA].loadFromFile(tablicaTekstur[jeden]);
	planszaTekstura[PIERWSZA_KRATKA].setSmooth(true);
	planszaTekstura[DRUGA_KRATKA].loadFromFile(tablicaTekstur[dwa]);
	planszaTekstura[DRUGA_KRATKA].setSmooth(true);
	planszaTekstura[RAMKA].loadFromFile(tablicaTekstur[trzy]);
	planszaTekstura[RAMKA].setSmooth(true);

	for (int i = 0; i < 3; i++)
	{
		planszaSprite[i].setTexture(planszaTekstura[i]);
		planszaSprite[i].setScale(1.0f, 1.0f);
	}

	this->liczbaPrzeszkod = liczbaprzeszkod;
	przeszkodaSprite = new Sprite[liczbaPrzeszkod];

	tablicaX = new int[liczbaPrzeszkod];
	tablicaY = new int[liczbaPrzeszkod];
	tablicaJ = new int[liczbaPrzeszkod];

	for (int i = 0; i < liczbaPrzeszkod; i++)
	{	
		tablicaX[i] = losuj(24);
		tablicaY[i] = losuj(12);
		tablicaJ[i] = losuj(3);
		for (int j = 0; j < i; j++)
		{
			if ((tablicaX[j] == tablicaX[i]) && (tablicaY[j] == tablicaY[i]))
			{
				tablicaX[i] = losuj(24);
				tablicaY[i] = losuj(12);
				j = 0;
			}
		}
	}
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

	
}

Gra::~Gra()
{
	delete[] tablicaTekstur;
	delete[] planszaSprite;
	delete[] przeszkodaSprite;
	delete[] tablicaX;
	delete[] tablicaY;
	delete[] tablicaJ;
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

	if (planszaSprite != NULL)
	{
		for (unsigned int i = 0; i < dlugoscPlanszy; i++)
			for (unsigned int j = 0; j < wysokoscPlanszy; j++)
			{
				float x = ((float)i * odstep) + 168.0f, y = ((float)j * odstep) + 88.0f;
				if (((j & 1) == 1) ^ ((i & 1) == 1)) // Szachownica
				{	
					planszaSprite[PIERWSZA_KRATKA].setPosition(x,y);
					tablica_srodkow_planszy[j][i].x = x;
					tablica_srodkow_planszy[j][i].y = y;
				}
				else
				{	
					
					planszaSprite[DRUGA_KRATKA].setPosition(x, y);
					tablica_srodkow_planszy[j][i].x = x;
					tablica_srodkow_planszy[j][i].y = y;
				}
				okno.draw(planszaSprite[PIERWSZA_KRATKA]);
				okno.draw(planszaSprite[DRUGA_KRATKA]);
			}
		for (unsigned int i = 0; i < dlugoscPlanszy+2; i++)
			for (unsigned int j = 0; j < wysokoscPlanszy+2; j++)
			{
				float x = ((float)i * odstep) + 104.0f, y = ((float)j * odstep) + 24.0f;
				if (j == 0 || j == wysokoscPlanszy + 1)
				{
					planszaSprite[RAMKA].setPosition(x, y);
					okno.draw(planszaSprite[RAMKA]);
				}
				else if (j != 0  && i == 0 ||  i == dlugoscPlanszy+1)
				{
					planszaSprite[RAMKA].setPosition(x,y);
					okno.draw(planszaSprite[RAMKA]);
				}
			}
		for (int i = 0; i < liczbaPrzeszkod; i++)
		{	
			int x = tablicaX[i];
			int y = tablicaY[i];
			int j = tablicaJ[i];
			przeszkodaTekstura.loadFromFile(tablicaTeksturPrzeszkod[j]);
			przeszkodaSprite[i].setTexture(przeszkodaTekstura);
			przeszkodaSprite[i].setScale(1.0f, 1.0f);
			przeszkodaSprite[i].setPosition(tablica_srodkow_planszy[y][x].x, tablica_srodkow_planszy[y][x].y);
			okno.draw(przeszkodaSprite[i]);
		} 
	}
}

bool Gra::silnikPoziomu(RenderWindow& okno)
{
	float czasOdJedzenia = 0.0f, czasomierz = 0.0f, milisekunda = 1.0 / 60.0;
	Gracz gracz;
	//Pokarm pokarm("data/Sprity do gry/Gracz i przedmioty/jablko_animacja2.png", gracz, tablica_srodkow_planszy, przeszkodaSprite, liczbaPrzeszkod);
	Punkty punkty;
	bool pauzaFlaga = false;
	int koniec = 0;
	Clock zegarJedzenia, zegarRysowania;
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
						gracz.zegar.restart();
						//pokarm.zegar.restart();
						//pokarm.calkowityCzas = 0.0f;
						gracz.czasomierz = 0.0f;
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
			//pokarm.aktualizuj(0);
			//if (pokarm.sprawdzCzyZjedzony(gracz, tablica_srodkow_planszy, przeszkodaSprite, liczbaPrzeszkod) == true)
			//{
			//	czasOdJedzenia = zegarJedzenia.getElapsedTime().asSeconds();
			//	if (czasOdJedzenia <= 2.0)
			//	{
			//		zmienKombo(0.25);
		//	}
		//		dodajPunkty(100);
			//	czasOdJedzenia = 0.0f;
		//		zegarJedzenia.restart();
		//	}
			// GRACZ
			gracz.obsluguj();
			// RYSOWANIE
			okno.clear(Color::Blue);
			rysujPlansze(okno);
			gracz.rysuj(okno);
		//	pokarm.rysujAnimacje(okno);
			czasomierz -= milisekunda;
		}
		okno.display();
	}
	return false;
}