//! \file Animacja.h
/*!	\brief Zawiera definicje klasy Animacja
*/
#pragma once
#include "Biblioteki.h"
//! \class Gracz
class Gracz;
//! Klasa Animacji Sprite
/*!	\brief Klasa odpowiadajaca za animacje sprite pokarmow i weza
*/
class Animacja
{
	float czasZmiany, deltaCzas;
	Vector2u aktualnyObraz, liczbaObrazow;
	float x = 0.0f, y = 0.0f;

public:
	IntRect obszar;
	Clock zegar;
	float calkowityCzas;
	
public:
	//! Konstruktor klasy Animacja
	Animacja(Texture& spriteTekstura, Vector2u liczbaObrazow, float czasZmiany);
	int aktualizuj(int wiersz);
};
