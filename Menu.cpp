#include "Menu.h"

enum wyborMenu  {START,POMOC,WYNIKI,TWORCY,WYJSCIE};
enum wyborPodstronyMenu {GLOWNA,POSTART,POPOMOC,POWYNIKI,POTWORCY};
enum wyborPoStart {POZIOM1,POZIOM2,POZIOM3,WSTECZ};
enum wyborPoWynikiPoTworcy {POWROT};
enum opcjeTekst {STEROWANIE,GORA,DOL,PRAWO,LEWO,OPCJE,MUZYKA,EKRAN,PELNY,RAMKA,WSTEC};

Menu::Menu()
{
    poziomMuzyki = 15.0f;
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

    plusTekstura.loadFromFile("data/Klawisze/free_button_31.png");
    plusTekstura.setSmooth(true);
    plusSprite.setTexture(plusTekstura);
    plusSprite.setScale(0.1f, 0.1f);
    
    minusTekstura.loadFromFile("data/Klawisze/free_button_32.png");
    minusTekstura.setSmooth(true);
    minusSprite.setTexture(minusTekstura);
    minusSprite.setScale(0.1f, 0.1f);

    opcjeTekstura.loadFromFile("data/Klawisze/free_button_34.png");
    opcjeTekstura.setSmooth(true);
    opcjeSprite.setTexture(opcjeTekstura);
    opcjeSprite.setScale(0.1f, 0.1f);

    ludzikiTekstura.loadFromFile("data/Klawisze/free_button_27.png");
    ludzikiTekstura.setSmooth(true);
    ludzikiSprite.setTexture(ludzikiTekstura);
    ludzikiSprite.setScale(0.1f, 0.1f);

    kontrolerTekstura.loadFromFile("data/Klawisze/free_button_12.png");
    kontrolerTekstura.setSmooth(true);
    kontrolerSprite.setTexture(kontrolerTekstura);
    kontrolerSprite.setScale(0.1f, 0.1f);

    dolTekstura.loadFromFile("data/Klawisze/free_button_11.png");
    dolTekstura.setSmooth(true);
    dolSprite.setTexture(dolTekstura);
    dolSprite.setScale(0.1f, 0.1f);

    goraTekstura.loadFromFile("data/Klawisze/free_button_10.png");
    goraTekstura.setSmooth(true);
    goraSprite.setTexture(goraTekstura);
    goraSprite.setScale(0.1f, 0.1f);

    lewoTekstura.loadFromFile("data/Klawisze/free_button_09.png");
    lewoTekstura.setSmooth(true);
    lewoSprite.setTexture(lewoTekstura);
    lewoSprite.setScale(0.1f, 0.1f);

    prawoTekstura.loadFromFile("data/Klawisze/free_button_08.png");
    prawoTekstura.setSmooth(true);
    prawoSprite.setTexture(prawoTekstura);
    prawoSprite.setScale(0.1f, 0.1f);

    czcionka.loadFromFile("data/Czcionki/snap/snap itc.ttf");

    tablicaText = new Text[5];
    opcjeText = new Text[11];

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
    menuMuzyka.setVolume(poziomMuzyki);
    menuMuzyka.play();
    menuMuzyka.setLoop(true);

    bufor.loadFromFile("data/Muzyka/misc_menu.wav");
    menuDzwiekWybor.setBuffer(bufor);
    menuDzwiekWybor.setVolume(0.8f);

    bufor2.loadFromFile("data/Muzyka/misc_menu_2.wav");

    menuDzwiekZatwierdzMenu.setBuffer(bufor2);
    menuDzwiekZatwierdzMenu.setVolume(2.0f);
}

Menu::~Menu() { delete [] tablicaText,opcjeText; }

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

void Menu::przygotujStrone()
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

        tablicaText[POZIOM1].setPosition(855, 250);
        tablicaText[POZIOM2].setPosition(855, 400);
        tablicaText[POZIOM3].setPosition(855, 550);
        tablicaText[WSTECZ].setPosition(875, 700);
        break;
    case POPOMOC:
        for (int i = 0; i < 11; i++)
        {
            opcjeText[i].setCharacterSize(40);
            opcjeText[i].setFont(czcionka);
            opcjeText[i].setFillColor(Color::Black);
        }
        opcjeText[STEROWANIE].setString("STEROWANIE");
        opcjeText[STEROWANIE].setPosition(710,250);
        kontrolerSprite.setPosition(1210, 245);

        goraSprite.setPosition(830, 300);
        opcjeText[GORA].setString("GORA");
        opcjeText[GORA].setPosition(1090,295);
        
        dolSprite.setPosition(855,345);
        opcjeText[DOL].setString("DOL");
        opcjeText[DOL].setPosition(1065,350);

        prawoSprite.setPosition(810,395);
        opcjeText[PRAWO].setString("PRAWO");
        opcjeText[PRAWO].setPosition(1110, 400);

        lewoSprite.setPosition(830, 445);
        opcjeText[LEWO].setString("LEWO");
        opcjeText[LEWO].setPosition(1090, 450);

        opcjeSprite.setPosition(1110, 495);
        opcjeText[OPCJE].setString("OPCJE");
        opcjeText[OPCJE].setPosition(810, 500);

        opcjeText[MUZYKA].setString("MUZYKA");
        opcjeText[MUZYKA].setPosition(750,550);
        plusSprite.setPosition(1030,545);
        minusSprite.setPosition(1120, 545);

        opcjeText[EKRAN].setString("EKRAN");
        opcjeText[EKRAN].setPosition(620, 600);
        opcjeText[PELNY].setString("PELNY");
        opcjeText[PELNY].setPosition(960, 600);
        opcjeText[RAMKA].setString("RAMKA");
        opcjeText[RAMKA].setPosition(1200, 600);

        opcjeText[WSTEC].setFillColor(Color::Red);
        opcjeText[WSTEC].setString("WSTECZ");
        opcjeText[WSTEC].setPosition(875, 700);
        break;
    case POWYNIKI:
        break;
    case POTWORCY:
        break;
    }
}

void Menu::rysuj(RenderWindow& okno)
{
    okno.draw(menuSprite);
    okno.draw(logoSprite);
    switch (podstronaMenu)
    {
    case GLOWNA:
        okno.draw(strzalkaSprite);
        przygotujStrone();
        for (int i = 0; i < 5; i++)
        {
            okno.draw(tablicaText[i]);
        }
        break;
    case POSTART:
        okno.draw(strzalkaSprite);
        przygotujStrone();
        for (int i = 0; i < 4; i++)
        {   
            okno.draw(tablicaText[i]);
        }
        break;
    case POPOMOC:
        przygotujStrone();
        okno.draw(kontrolerSprite);
        okno.draw(goraSprite);
        okno.draw(dolSprite);
        okno.draw(prawoSprite);
        okno.draw(lewoSprite);
        okno.draw(opcjeSprite);
        okno.draw(plusSprite);
        okno.draw(minusSprite);
        for (int i = 0; i < 11; i++)
        {
            okno.draw(opcjeText[i]);
        }
        break;
    case POWYNIKI:
        break;
    case POTWORCY:
        break;
    }
}

void Menu::aktualizacjaMenu()
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
        for (int i = 0; i < 4; i++)
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
        opcjeText[aktualnyWyborMenu].setFillColor(Color::Red);
        break;
    case POWYNIKI:
        break;
    case POTWORCY:
        break;
    }
}

void Menu::ruchMyszka(int x,int y)
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
                aktualizacjaMenu();
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
                aktualizacjaMenu();
            }
        }
        break;
    case POPOMOC:
        for (int i = 8; i < 11; i++)
        {
            String tekst = opcjeText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect(opcjeText[i].getPosition().x, opcjeText[i].getPosition().y, liczbaLiter * 40, 40);
            if (obszar.contains(x, y))
            {
                opcjeText[i].setFillColor(Color::Red);
                aktualizacjaMenu();
            }
        }
        break;
    case POWYNIKI:
        break;
    case POTWORCY:
        break;
    }
}

void Menu::klikMyszka(int x, int y, RenderWindow& okno)
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
                aktualnyWyborMenu = i;
                enter(okno);
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
                enter(okno);
            }
        }
        break;
    case POPOMOC:
        for (int i = 8; i < 11; i++)
        {
            String tekst = opcjeText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect(opcjeText[i].getPosition().x, opcjeText[i].getPosition().y, liczbaLiter * 40, 40);
            if (obszar.contains(x, y))
            {
                switch (i)
                {
                case 8:
                    okno.create(VideoMode(1920, 1080), "Snake", Style::Fullscreen | Style::Close);
                    okno.setFramerateLimit(60);
                    break;
                case 9:
                    okno.create(VideoMode(1920, 1080), "Snake", Style::Titlebar | Style::Close | Style::Resize);
                    okno.setFramerateLimit(60);
                    break;
                case 10:
                    aktualnyWyborMenu = WSTEC;
                    enter(okno);
                }
            }
        }

        obszar = IntRect(plusSprite.getPosition().x, plusSprite.getPosition().y,51,51);
        if (obszar.contains(x, y))
        {   
            if (poziomMuzyki == 15.0f){}
            else
            {
                poziomMuzyki += 3.0f;
                menuMuzyka.setVolume(poziomMuzyki);
                break;
            }
        } 

        obszar = IntRect(minusSprite.getPosition().x, minusSprite.getPosition().y,51,51);
        if (obszar.contains(x, y))
        {   
            if (poziomMuzyki == 0.0f){}
            else
            {
                poziomMuzyki -= 3.0f;
                menuMuzyka.setVolume(poziomMuzyki);
                break;
            }
        }
        break;
    case POWYNIKI:
        break;
    case POTWORCY:
        break;
    }
}

void Menu::enter( RenderWindow& okno)
{   
    menuDzwiekZatwierdzMenu.play();
    switch (podstronaMenu)
    {
    case GLOWNA:
        switch (aktualnyWyborMenu)
        {
        case START:
            podstronaMenu = POSTART;
            aktualnyWyborMenu = 0;
            aktualizacjaMenu();
            break;
        case POMOC:
            podstronaMenu = POPOMOC;
            aktualnyWyborMenu = WSTEC;
            aktualizacjaMenu();
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
        switch (aktualnyWyborMenu)
        {
        case POZIOM1:
            break;
        case POZIOM2:
            break;
        case POZIOM3:
            break;
        case WSTECZ:
            aktualnyWyborMenu = 0;
            podstronaMenu = GLOWNA;
            aktualizacjaMenu();
            break;
        }
    case POPOMOC:
        switch (aktualnyWyborMenu)
        {
        case WSTEC:
            aktualnyWyborMenu = 0;
            podstronaMenu = GLOWNA;
            aktualizacjaMenu();
            break;
        }
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
                            aktualizacjaMenu();
                        }
                        break;
                    case POSTART:
                        if (aktualnyWyborMenu == WSTECZ)
                            continue;
                        else
                        {
                            aktualnyWyborMenu++;
                            aktualizacjaMenu();
                        }
                        break;
                    case POPOMOC:
                        aktualnyWyborMenu = WSTEC;
                        aktualizacjaMenu();
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
                            aktualizacjaMenu();
                        }
                        break;
                    case POSTART:
                        if (aktualnyWyborMenu == POZIOM1)
                            continue;
                        else
                        {
                            aktualnyWyborMenu--;
                            aktualizacjaMenu();
                        }
                        break;
                    case POPOMOC:
                        aktualnyWyborMenu = WSTEC;
                        aktualizacjaMenu();
                        break;
                    case POWYNIKI:
                        break;
                    case POTWORCY:
                        break;
                    }
                }
                if (zdarzenie.key.code == Keyboard::Escape)
                {   
                    if (podstronaMenu != GLOWNA)
                    {
                        podstronaMenu = GLOWNA;
                        aktualizacjaMenu();
                    }
                    else
                    {
                        okno.close();
                        break;
                    }
                }
                if (zdarzenie.key.code == Keyboard::Enter)
                {
                    enter(okno);
                    break;
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
                    klikMyszka(x, y,okno);
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