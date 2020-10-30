#include "Menu.h"

Menu::Menu()
{
    kierunekTla = 0;
    menuTekstura.loadFromFile("data/Obrazy menu/menuSnake.png");
    menuSprite.setTexture(menuTekstura);
    menuSprite.setScale(1.35f, 1.0f);
}

void Menu::poruszajTlo()
{
    if ((menuSprite.getPosition().x <= 0) && (kierunekTla == 0))
    {
        if (menuSprite.getPosition().x <= -119) kierunekTla = 1;
            menuSprite.move(Vector2f(-0.3f, 0.0f));
    }

    if ((menuSprite.getPosition().x >= -120) && (kierunekTla == 1))
    {
        if (menuSprite.getPosition().x >= -1) kierunekTla = 0;
            menuSprite.move(Vector2f(0.3f, 0.0f));
    }
}

void Menu::rysuj(RenderWindow& okno)
{
    okno.draw(menuSprite);
}

bool Menu::start(RenderWindow& okno)
{
    while (okno.isOpen())
    {
        // Obs³uga zdarzeñ
        Event zdarzenie;
        while (okno.pollEvent(zdarzenie))
        {
            switch(zdarzenie.type)
            {
                // Case zdarzenie:
                // Obs³uga zdarzenia
            case Event::Closed:
                okno.close();
                break;
            }
        }
        poruszajTlo();
        okno.clear(Color::Green);
        // Rysowanie ...
        rysuj(okno);
        okno.display();
    }
	return false;
}