#include "Poziom1.h"

enum opis_planszy { PIERWSZA_KRATKA, DRUGA_KRATKA,RAMKA };

Poziom1::Poziom1()
	:Gra::Gra{15}
{
	int jeden= 0, dwa = 0, trzy = 0;
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
		planszaSprite[i].setScale(1.0f,1.0f);
	}

	tloMapyTekstura.loadFromFile("data/Sprity do gry/Plansza/tlo_1.jpg");
	tloMapyTekstura.setSmooth(true);
	tloMapySprite.setTexture(tloMapyTekstura);
	tloMapySprite.setPosition(0.0f, 0.0f);
	tloMapySprite.setScale(1.0f, 1.0f);

}

Poziom1::~Poziom1()
{
}

bool Poziom1::start(RenderWindow& okno)
{
	Clock zegarRuchu;
	float czasomierz = 0.0f, opoznienie = 0.1f;
	Gracz gracz;

	while (okno.isOpen())
	{
		Event zdarzenie;
		while (okno.pollEvent(zdarzenie))
		{
			switch (zdarzenie.type)
			{
			case Event::KeyPressed:
				if (zdarzenie.key.code == Keyboard::Escape)
				{
					// PAUZA
					return false;
				}
			}
		}

		float czas = zegarRuchu.getElapsedTime().asSeconds();
		zegarRuchu.restart();
		czasomierz += czas;
		if (czasomierz >= opoznienie)
		{
			czasomierz -= opoznienie;
			gracz.ruchGracza();
		}

		//gracz.sterowanie();
		okno.clear(Color::Blue);
		rysujPlansze(okno);
		//gracz.rysuj(okno);
		okno.display();
	}
	return false;
}