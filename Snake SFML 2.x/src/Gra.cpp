#include "Biblioteki.h"

enum opis_planszy { PIERWSZA_KRATKA, DRUGA_KRATKA };

Gra::Gra()
{
	planszaSprite = NULL;
	odstep = 64;
	wysokoscPlanszy = 10;
	dlugoscPlanszy = 10;
}

void Gra::rysujPlansze(RenderWindow& okno)
{
	if (planszaSprite != NULL)
	{
		for (unsigned int i = 0; i < dlugoscPlanszy; i++)
			for (unsigned int j = 0; j < wysokoscPlanszy; j++)
			{
				if(((j & 1) == 1) ^ ((i & 1) == 1)) // Szachownica
					planszaSprite[PIERWSZA_KRATKA].setPosition((float)i * odstep, (float)j * odstep);
				else
					planszaSprite[DRUGA_KRATKA].setPosition((float)i * odstep, (float)j * odstep);
				okno.draw(planszaSprite[PIERWSZA_KRATKA]);
				okno.draw(planszaSprite[DRUGA_KRATKA]);
			}
	}
}