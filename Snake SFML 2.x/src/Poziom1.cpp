#include "Poziom1.h"

enum opis_planszy { PIERWSZA_KRATKA, DRUGA_KRATKA };

Poziom1::Poziom1()
{
	planszaTekstura[PIERWSZA_KRATKA].loadFromFile("data/Sprity do gry/Plansza/trawa_jasna.png");
	planszaTekstura[DRUGA_KRATKA].loadFromFile("data/Sprity do gry/Plansza/trawa_ciemna.png");

	planszaSprite = new Sprite[2];
	for (int i = 0; i < 2; i++)
		planszaSprite[i].setTexture(planszaTekstura[i]);

}

Poziom1::~Poziom1()
{
	delete[] planszaSprite;
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
		if (czasomierz > opoznienie)
		{
			czasomierz = 0;
			gracz.ruchGracza();
		}

		gracz.sterowanie();
		okno.clear(Color::Blue);
		rysujPlansze(okno);
		gracz.rysuj(okno);
		okno.display();
	}
	return false;
}