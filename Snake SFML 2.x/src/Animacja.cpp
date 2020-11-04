#include "Biblioteki.h"

Animacja::Animacja(string sciezkaPliku, Vector2u liczbaObrazow, float czasZmiany)
{
	animacjaTekstura.loadFromFile(sciezkaPliku);
	animacjaTekstura.setSmooth(true);
	animacjaSprite.setTexture(animacjaTekstura);
	animacjaSprite.setScale(0.2f, 0.2f);
	Rect<float> _obszar = animacjaSprite.getGlobalBounds();
	animacjaSprite.setOrigin(Vector2f(_obszar.width / 2.0f, _obszar.width / 2.0f));
	animacjaSprite.setPosition(100, 100);

	this->liczbaObrazow = liczbaObrazow;
	this->czasZmiany = czasZmiany;
	
	deltaCzas = calkowityCzas = 0.0f;
	aktualnyObraz.x = 0;
	obszar.width = animacjaTekstura.getSize().x / float(liczbaObrazow.x);
	obszar.height = animacjaTekstura.getSize().y / float(liczbaObrazow.y);
}

void Animacja::aktualizuj(int wiersz)
{
	deltaCzas = zegar.restart().asSeconds();
	aktualnyObraz.y = wiersz;
	calkowityCzas += deltaCzas;

	if (calkowityCzas >= czasZmiany)
	{
		calkowityCzas -= czasZmiany;
		aktualnyObraz.x++;

		if (aktualnyObraz.x >= liczbaObrazow.x)
		{
			aktualnyObraz.x = 0;
		}
	}

	obszar.left = aktualnyObraz.x * obszar.width;
	obszar.top = aktualnyObraz.y * obszar.height;
	animacjaSprite.setTextureRect(obszar);
}

void Animacja::rysujAnimacje(RenderWindow& okno) 
{
	okno.draw(animacjaSprite);
}