#include "Biblioteki.h"

enum opis_planszy { PIERWSZA_KRATKA, DRUGA_KRATKA,RAMKA };

Gra::Gra(int liczbaprzeszkod)
{
	planszaSprite = NULL;
	odstep = 64;
	wysokoscPlanszy = 12;
	dlugoscPlanszy = 24;
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
	this->liczbaPrzeszkod = liczbaprzeszkod;
	przeszkodaSprite = new Sprite[liczbaPrzeszkod];
	tablicaX = new int[liczbaPrzeszkod];
	tablicaY = new int[liczbaPrzeszkod];
	tablicaJ = new int[liczbaPrzeszkod];
	for (int i = 0; i < liczbaPrzeszkod; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (tablicaX[j] == tablicaX[i] && tablicaY[j] == tablicaY[i])
			{
				tablicaX[j] = losuj(24);
				tablicaY[j] = losuj(12);
			}
		}
		tablicaX[i] = losuj(24);
		tablicaY[i] = losuj(12);
		tablicaJ[i] = losuj(3);
	}
	
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


void Gra::rysujPlansze(RenderWindow& okno)
{
	okno.draw(tloMapySprite);
	if (planszaSprite != NULL)
	{
		for (unsigned int i = 0; i < dlugoscPlanszy; i++)
			for (unsigned int j = 0; j < wysokoscPlanszy; j++)
			{
				float x = ((float)i * odstep) + 168.0f, y = ((float)j * odstep) + 118.0f;
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
				float x = ((float)i * odstep) + 104.0f, y = ((float)j * odstep) + 54.0f;
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