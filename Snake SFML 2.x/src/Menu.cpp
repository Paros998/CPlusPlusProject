#include "Menu.h"

enum wyborMenu  {START,POMOC,WYNIKI,TWORCY,WYJSCIE};
enum wyborPodstronyMenu {GLOWNA,POSTART,POPOMOC,POWYNIKI,POTWORCY};
enum wyborPoStart {POZIOM1,POZIOM2,POZIOM3,WSTECZ};
enum wyborPoPomocPoWynikiPoTworcy {POWROT};

Menu::Menu()
{
    kierunekTla = 0, aktualnyWyborMenu = START,podstronaMenu = GLOWNA;
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
    
    menuMuzyka.openFromFile("data/Muzyka/menuAmbient.ogg");
    menuMuzyka.setVolume(15.0f);
    menuMuzyka.play();
    menuMuzyka.setLoop(true);

    bufor.loadFromFile("data/Muzyka/misc_menu.wav");
    menuDzwiekWybor.setBuffer(bufor);
    menuDzwiekWybor.setVolume(0.8f);

    bufor2.loadFromFile("data/Muzyka/misc_menu_2.wav");

    menuDzwiekZatwierdzMenu.setBuffer(bufor2);
    menuDzwiekZatwierdzMenu.setVolume(2.0f);
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

void Menu::przygotujStrone(int podstronaMenu,int aktualnyWyborMenu)
{
    for (int i = 0; i < 5; i++) tablicaText[i].setFillColor(Color::Black);
    switch (podstronaMenu)
    {
    case GLOWNA:
        tablicaText[aktualnyWyborMenu].setFillColor(Color::Red);

        tablicaText[START].setString("START");
        tablicaText[POMOC].setString("POMOC");
        tablicaText[WYNIKI].setString("WYNIKI");
        tablicaText[TWORCY].setString("TWORCY");
        tablicaText[WYJSCIE].setString("WYJSCIE");

        tablicaText[START].setPosition(890, 250);
        tablicaText[POMOC].setPosition(885, 400);
        tablicaText[WYNIKI].setPosition(875, 550);
        tablicaText[TWORCY].setPosition(875, 700);
        tablicaText[WYJSCIE].setPosition(860, 850);
        break;
    case POSTART:
        tablicaText[aktualnyWyborMenu].setFillColor(Color::Red);
        tablicaText[POZIOM1].setString("POZIOM 1");
        tablicaText[POZIOM2].setString("POZIOM 2");
        tablicaText[POZIOM3].setString("POZIOM 3");
        tablicaText[WSTECZ].setString("WSTECZ");

        tablicaText[POZIOM1].setPosition(890, 250);
        tablicaText[POZIOM2].setPosition(885, 400);
        tablicaText[POZIOM3].setPosition(875, 550);
        tablicaText[WSTECZ].setPosition(875, 700);
        break;
    case POPOMOC:
        break;
    case POWYNIKI:
        break;
    case POTWORCY:
        break;
    }
}

void Menu::rysuj(RenderWindow& okno,int podstronaMenu,int aktualnyWyborMenu)
{
    okno.draw(menuSprite);
    okno.draw(logoSprite);
    switch (podstronaMenu)
    {
    case GLOWNA:
        okno.draw(strzalkaSprite);
        przygotujStrone(podstronaMenu, aktualnyWyborMenu);
        for (int i = 0; i < 5; i++)
        {
            okno.draw(tablicaText[i]);
        }
        break;
    case POSTART:
        okno.draw(strzalkaSprite);
        przygotujStrone(podstronaMenu, aktualnyWyborMenu);
        for (int i = 0; i < 4; i++)
        {
            okno.draw(tablicaText[i]);
        }
        break;
    case POPOMOC:
        break;
    case POWYNIKI:
        break;
    case POTWORCY:
        break;
    }
}

void Menu::aktualizacjaMenu(int podstronaMenu)
{
    switch (podstronaMenu)
    {
    case GLOWNA:
        for (int i = 0; i < 5; i++)
        {
            tablicaText[i].setFillColor(Color::Black);
        }
        tablicaText[aktualnyWyborMenu].setFillColor(Color::Red);
        switch (aktualnyWyborMenu)
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
        break;
    case POSTART:
        for (int i = 0; i < 5; i++)
        {
            tablicaText[i].setFillColor(Color::Black);
        }
        tablicaText[aktualnyWyborMenu].setFillColor(Color::Red);
        switch (aktualnyWyborMenu)
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
        }
        break;
    case POPOMOC:
        break;
    case POWYNIKI:
        break;
    case POTWORCY:
        break;
    }
}

void Menu::ruchMyszka(int x,int y,int podstronaMenu)
{   
    switch (podstronaMenu)
    {
    case GLOWNA:
        for (int i = 0; i < 5; i++)
        {
            String tekst = tablicaText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect(tablicaText[i].getPosition().x, tablicaText[i].getPosition().y,liczbaLiter * 40 ,40);
            if (obszar.contains(x, y))
            {
                aktualnyWyborMenu = i;
                aktualizacjaMenu(podstronaMenu);
            }
        }
        break;
    case POSTART:
        for (int i = 0; i < 4; i++)
        {
            String tekst = tablicaText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect(tablicaText[i].getPosition().x, tablicaText[i].getPosition().y, liczbaLiter * 40, 40);
            if (obszar.contains(x, y))
            {
                aktualnyWyborMenu = i;
                aktualizacjaMenu(podstronaMenu);
            }
        }
        break;
    case POPOMOC:
        break;
    case POWYNIKI:
        break;
    case POTWORCY:
        break;
    }
}


void Menu::klikMyszka(int x, int y, int podstronaMenu, RenderWindow& okno)
{   
    switch (podstronaMenu)
    {
    case GLOWNA:
        for (int i = 0; i < 5; i++)
        {
            String tekst = tablicaText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect(tablicaText[i].getPosition().x, tablicaText[i].getPosition().y, liczbaLiter * 40, 40);
            if (obszar.contains(x, y))
            {
                enter(i,podstronaMenu,okno);
            }
        }
        break;
    case POSTART:
        for (int i = 0; i < 4; i++)
        {
            menuDzwiekZatwierdzMenu.play();

            String tekst = tablicaText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect(tablicaText[i].getPosition().x, tablicaText[i].getPosition().y, liczbaLiter * 40, 40);
            if (obszar.contains(x, y))
            {
                enter(i, podstronaMenu, okno);
            }

        }
        break;
    case POPOMOC:
        break;
    case POWYNIKI:
        break;
    case POTWORCY:
        break;
    }
}

void Menu::enter(int aktualnyWyborMenu,int podstronaMenu, RenderWindow& okno)
{   
    menuDzwiekZatwierdzMenu.play();
    switch (podstronaMenu)
    {
    case GLOWNA:
        switch (aktualnyWyborMenu)
        {
        case START:
            aktualnyWyborMenu = 0;
            podstronaMenu = POSTART;
            rysuj(okno, podstronaMenu, aktualnyWyborMenu);
            break;
        case POMOC:
            break;
        case WYNIKI:
            break;
        case TWORCY:
            break;
        case WYJSCIE:
            okno.close();
            break;
        }
        break;
    case POSTART:
        break;
    case POPOMOC:
        break;
    case POWYNIKI:
        break;
    case POTWORCY:
        break;
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
                    switch (podstronaMenu)
                    {
                    case GLOWNA:
                        if (aktualnyWyborMenu == WYJSCIE)
                            continue;
                        else 
                        {
                            aktualnyWyborMenu++;
                            aktualizacjaMenu(podstronaMenu);
                        }
                        break;
                    case POSTART:
                        if (aktualnyWyborMenu == WSTECZ)
                            continue;
                        else
                        {
                            aktualnyWyborMenu++;
                            aktualizacjaMenu(podstronaMenu);
                        }
                        break;
                    case POPOMOC:
                        break;
                    case POWYNIKI:
                        break;
                    case POTWORCY:
                        break;
                    }
                }
                if (zdarzenie.key.code == Keyboard::Up)
                {
                    switch (podstronaMenu)
                    {
                    case GLOWNA:
                        if (aktualnyWyborMenu == START)
                            continue;
                        else
                        {
                            aktualnyWyborMenu--;
                            aktualizacjaMenu(podstronaMenu);
                        }
                    case POSTART:
                        if (aktualnyWyborMenu == POZIOM1)
                            continue;
                        else
                        {
                            aktualnyWyborMenu--;
                            aktualizacjaMenu(podstronaMenu);
                        }
                        break;
                    case POPOMOC:
                        break;
                    case POWYNIKI:
                        break;
                    case POTWORCY:
                        break;
                    }
                }
                if (zdarzenie.key.code == Keyboard::Escape)
                {   
                    if(podstronaMenu != GLOWNA) aktualizacjaMenu(podstronaMenu = GLOWNA);
                    else
                    {
                        okno.close();
                        break;
                    }
                }
                if (zdarzenie.key.code == Keyboard::Enter)
                {
                    enter(aktualnyWyborMenu,podstronaMenu,okno);
                    break;
                }
            case Event::MouseMoved:
            {
                int x, y;
                x = zdarzenie.mouseMove.x;
                y = zdarzenie.mouseMove.y;
                ruchMyszka(x, y,podstronaMenu);
            }
            case Event::MouseButtonPressed:
            {
                if (zdarzenie.mouseButton.button == Mouse::Left)
                {
                    int x, y;
                    x = zdarzenie.mouseButton.x;
                    y = zdarzenie.mouseButton.y;
                    klikMyszka(x, y,podstronaMenu,okno);
                }
            }
            }
        }
        poruszajTlo();
        okno.clear(Color::Green);
        // Rysowanie ...
        rysuj(okno,podstronaMenu,aktualnyWyborMenu);
        okno.display();
    }
	return false;
}