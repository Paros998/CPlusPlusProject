#pragma once
#include "Biblioteki.h"

class Gra
{
protected:
	Texture tloMapyTekstura, planszaTekstura[2];
	Sprite tloMapySprite, *planszaSprite;
	unsigned int wysokoscPlanszy, dlugoscPlanszy, odstep;

protected:
	Gra();

protected:
	void rysujPlansze(RenderWindow& okno);
};

