#include "Menu.h"

enum wyborMenu  {START,POMOC,WYNIKI,TWORCY,WYJSCIE};

Menu::Menu()
{
    kierunekTla = 0,Wybor = START;
    menuTekstura.loadFromFile("data/Obrazy menu/menuSnake.png");
    menuTekstura.setSmooth(true);
    menuSprite.setTexture(menuTekstura);
    menuSprite.setScale(1.1f, 1.0f);

    logoTekstura.loadFromFile("data/Obrazy menu/logoSnake.png");
    logoTekstura.setSmooth(true);
    logoSprite.setTexture(logoTekstura);
    logoSprite.setPosition(760, 50);
    logoSprite.setScale(1.0f, 1.0f);

    strzalkaTekstura.loadFromFile("data/Obrazy menu/snake_glowa.png");
    strzalkaTekstura.setSmooth(true);
    strzalkaSprite.setTexture(strzalkaTekstura); 
    strzalkaSprite.setRotation(90);
    strzalkaSprite.setPosition(725,206);
    strzalkaSprite.setScale(1.0f, 1.0f);

    czcionka.loadFromFile("data/Czcionki/snap/snap itc.ttf");

    tablicaText = new Text[5];
   
    for (int i = 0; i < 5; i++)
    {
        tablicaText[i].setCharacterSize(40);
        tablicaText[i].setFont(czcionka);
        tablicaText[i].setFillColor(Color::Black);
    }

    tablicaText[START].setFillColor(Color::Red);
    tablicaText[START].setString("START");
    tablicaText[POMOC].setString("POMOC");
    tablicaText[WYNIKI].setString("WYNIKI");
    tablicaText[TWORCY].setString("TWORCY");
    tablicaText[WYJSCIE].setString("WYJSCIE");

    tablicaText[START].setPosition(890,250);
    tablicaText[POMOC].setPosition(885,400);
    tablicaText[WYNIKI].setPosition(875,550);
    tablicaText[TWORCY].setPosition(875,700);
    tablicaText[WYJSCIE].setPosition(860,850);
    
    menuAmbient.openFromFile("data/Muzyka/menuAmbient.ogg");
    menuAmbient.setVolume(13.0f);
    menuAmbient.play();
    menuAmbient.setLoop(true);

    bufor.loadFromFile("data/Muzyka/misc_menu.wav");
    menuWybor.setBuffer(bufor);
    menuWybor.setVolume(0.8f);

    bufor2.loadFromFile("data/Muzyka/misc_menu_2.wav");
    menuZatwierdzMenu.setBuffer(bufor2);
    menuZatwierdzMenu.setVolume(1.0f);

}

Menu::~Menu() { delete [] tablicaText; }

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
    okno.draw(logoSprite);
    okno.draw(strzalkaSprite);
    for (int i = 0; i < 5; i++)
    {
        okno.draw(tablicaText[i]);
    }
    
}

void Menu::aktualizacjaMenu()
{
    for (int i = 0; i < 5; i++)
    {
        tablicaText[i].setFillColor(Color::Black);
    }
    tablicaText[Wybor].setFillColor(Color::Red);
    switch (Wybor)
    {
        case 0: 
            strzalkaSprite.setPosition(725, 206);
            break;
        case 1: 
            strzalkaSprite.setPosition(725, 366);
            break;
        case 2: 
            strzalkaSprite.setPosition(725, 506);
            break;
        case 3: 
            strzalkaSprite.setPosition(725, 666);
            break;
        case 4: 
            strzalkaSprite.setPosition(725, 806);
            break;
    }
}

void Menu::ruchMyszka(int x,int y)
{   
    for (int i = 0; i < 5; i++)
    {
        String tekst = tablicaText[i].getString();
        int liczbaLiter = tekst.getSize();
        obszar = IntRect(tablicaText[i].getPosition().x, tablicaText[i].getPosition().y,liczbaLiter * 40 ,40);
        if (obszar.contains(x, y))
        {
            Wybor = i;
            aktualizacjaMenu();
        }
    }
}

void Menu::klikMyszka(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        String tekst = tablicaText[i].getString();
        int liczbaLiter = tekst.getSize();
        obszar = IntRect(tablicaText[i].getPosition().x, tablicaText[i].getPosition().y, liczbaLiter * 40, 40);
        if (obszar.contains(x, y))
        {
            menuZatwierdzMenu.play();
        }
    }
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
            case Event::KeyPressed:
                if (zdarzenie.key.code == Keyboard::Down)
                {
                    if (Wybor == WYJSCIE)
                        continue;
                    else 
                    {
                        Wybor++;
                        aktualizacjaMenu();
                    }
                }
                if (zdarzenie.key.code == Keyboard::Up)
                {
                    if (Wybor == START)
                        continue;
                    else
                    {
                        Wybor--;
                        aktualizacjaMenu();
                    }
                }
            case Event::MouseMoved:
            {
                int x, y;
                x = zdarzenie.mouseMove.x;
                y = zdarzenie.mouseMove.y;
                ruchMyszka(x, y);
            }
            case Event::MouseButtonPressed:
            {
                if (zdarzenie.mouseButton.button == Mouse::Left)
                {
                    int x, y;
                    x = zdarzenie.mouseButton.x;
                    y = zdarzenie.mouseButton.y;
                    klikMyszka(x, y);
                }
            }
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