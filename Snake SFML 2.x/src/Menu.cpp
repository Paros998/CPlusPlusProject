#include "Menu.h"

enum wyborMenu  {START,OPCJE,WYNIKI,TWORCY,WYJSCIE};
enum wyborPodstronyMenu {GLOWNA,POSTART,POOPCJE,POWYNIKI,POTWORCY};
enum wyborPoStart {POZIOM1,POZIOM2,POZIOM3,WSTECZ};
enum wyborPoWynikiPoTworcy {POWROT};
enum opcjeTekst {STEROWANIE,GORA,DOL,PRAWO,LEWO,USTAWIENIA,MUZYKA,EKRAN,PELNY,RAMKA,WSTEC};

Menu::Menu()
{
    poziomMuzyki = 15.0f;
    kierunekTla = 0, aktualnyWyborMenu = START, podstronaMenu = GLOWNA, iloscWynikow = 0, numerMuzyki = 0;
    procX = 1.0, procY = 1.0;
    menuTekstura.loadFromFile("data/Obrazy menu/menuSnake.png");
    menuTekstura.setSmooth(true);
    menuSprite.setTexture(menuTekstura);
    menuSprite.setScale(1.1f, 1.0f);

    logoTekstura.loadFromFile("data/Obrazy menu/logoSnake2.png");
    logoTekstura.setSmooth(true);
    logoSprite.setTexture(logoTekstura);
    logoSprite.setPosition(560, 0);
    logoSprite.setScale(1.0f, 0.5f);

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
    wynikiText = new Text[5];

    for (int i = 0; i < 5; i++)
    {
        wynikiText[i].setCharacterSize(40);
        wynikiText[i].setFont(czcionka);
        wynikiText[i].setFillColor(Color::Black);
        wynikiText[i].setOutlineThickness(1.0f);
        wynikiText[i].setOutlineColor(Color::Red);
    }

    wynikiPlik.open("data/wyniki.txt");
    linia ;

    if (wynikiPlik.is_open())
    {
        int i = 0;
        while (getline(wynikiPlik, linia) && i<5)
        {
            wynikiText[i].setString(linia);
            i++; iloscWynikow++;
        }
    }
    wynikiPlik.close();


    for (int i = 0; i < 5; i++)
    {
        tablicaText[i].setCharacterSize(40);
        tablicaText[i].setFont(czcionka);
        tablicaText[i].setFillColor(Color::Black);
        tablicaText[i].setOutlineThickness(1.0f);
        tablicaText[i].setOutlineColor(Color::Red);
    }

    tablicaText[START].setFillColor(Color::Red);
    tablicaText[START].setOutlineColor(Color::Black);
    tablicaText[START].setString("START");
    tablicaText[OPCJE].setString("OPCJE");
    tablicaText[WYNIKI].setString("WYNIKI");
    tablicaText[TWORCY].setString("TWORCY");
    tablicaText[WYJSCIE].setString("WYJSCIE");

    tablicaText[START].setPosition(890,250);
    tablicaText[OPCJE].setPosition(885,400);
    tablicaText[WYNIKI].setPosition(875,550);
    tablicaText[TWORCY].setPosition(875,700);
    tablicaText[WYJSCIE].setPosition(860,850);
    
    menuMuzyka = new Music[4];

    menuMuzyka[0].openFromFile("data/Muzyka/mainMenu.wav");
    menuMuzyka[1].openFromFile("data/Muzyka/No More Magic.ogg");
    menuMuzyka[2].openFromFile("data/Muzyka/Winds Of Stories.ogg");
    menuMuzyka[3].openFromFile("data/Muzyka/Path to Lake Land.ogg");
    
    for (int i = 0; i < 4; i++)
    {
    menuMuzyka[i].setVolume(poziomMuzyki);
    }

    bufor.loadFromFile("data/Muzyka/misc_menu.wav");
    menuDzwiekWybor.setBuffer(bufor);
    menuDzwiekWybor.setVolume(0.8f);

    bufor2.loadFromFile("data/Muzyka/misc_menu_2.wav");

    menuDzwiekZatwierdzMenu.setBuffer(bufor2);
    menuDzwiekZatwierdzMenu.setVolume(2.0f);
}

Menu::~Menu() {
    delete[] tablicaText;
    delete [] opcjeText;
    delete [] wynikiText;
    delete[] menuMuzyka;
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

void Menu::przygotujStrone()
{
    for (int i = 0; i < 5; i++) tablicaText[i].setFillColor(Color::Black);
    switch (podstronaMenu)
    {
    case GLOWNA:
        tablicaText[aktualnyWyborMenu].setFillColor(Color::Red);
        tablicaText[aktualnyWyborMenu].setOutlineColor(Color::Black);

        tablicaText[START].setString("START");
        tablicaText[OPCJE].setString("OPCJE");
        tablicaText[WYNIKI].setString("WYNIKI");
        tablicaText[TWORCY].setString("TWORCY");
        tablicaText[WYJSCIE].setString("WYJSCIE");

        tablicaText[START].setPosition(890, 250);
        tablicaText[OPCJE].setPosition(885, 400);
        tablicaText[WYNIKI].setPosition(875, 550);
        tablicaText[TWORCY].setPosition(875, 700);
        tablicaText[WYJSCIE].setPosition(860, 850);
        break;
    case POSTART:
        tablicaText[aktualnyWyborMenu].setFillColor(Color::Red);
        tablicaText[aktualnyWyborMenu].setOutlineColor(Color::Black);
        tablicaText[POZIOM1].setString("POZIOM 1");
        tablicaText[POZIOM2].setString("POZIOM 2");
        tablicaText[POZIOM3].setString("POZIOM 3");
        tablicaText[WSTECZ].setString("WSTECZ");

        tablicaText[POZIOM1].setPosition(855, 250);
        tablicaText[POZIOM2].setPosition(855, 400);
        tablicaText[POZIOM3].setPosition(855, 550);
        tablicaText[WSTECZ].setPosition(875, 700);
        break;
    case POOPCJE:
        for (int i = 0; i < 11; i++)
        {
            opcjeText[i].setCharacterSize(40);
            opcjeText[i].setFont(czcionka);
            opcjeText[i].setFillColor(Color::Black);
            opcjeText[i].setOutlineThickness(1.0f);
            opcjeText[i].setOutlineColor(Color::Red);
        }
        opcjeText[STEROWANIE].setString("STEROWANIE");
        opcjeText[STEROWANIE].setPosition(620,200);
        kontrolerSprite.setPosition(1140, 200);

        goraSprite.setPosition(1140, 300);
        opcjeText[GORA].setString("GORA");
        opcjeText[GORA].setPosition(620,300);
        
        dolSprite.setPosition(1140,350);
        opcjeText[DOL].setString("DOL");
        opcjeText[DOL].setPosition(620,350);

        prawoSprite.setPosition(1140,400);
        opcjeText[PRAWO].setString("PRAWO");
        opcjeText[PRAWO].setPosition(620, 400);

        lewoSprite.setPosition(1140, 450);
        opcjeText[LEWO].setString("LEWO");
        opcjeText[LEWO].setPosition(620, 450);

        opcjeSprite.setPosition(1140, 550);
        opcjeText[USTAWIENIA].setString("OPCJE");
        opcjeText[USTAWIENIA].setPosition(620, 550);

        opcjeText[MUZYKA].setString("MUZYKA");
        opcjeText[MUZYKA].setPosition(620,700);
        plusSprite.setPosition(1010,700);
        minusSprite.setPosition(1270, 700);

        int procent;
        procent =( poziomMuzyki / 30.0 )*100;
        unsigned int znaki;
        
        linia = "";
        linia += std::to_string(procent);
        linia += "%";
       
        znaki = linia.length();
        tablicaText[0].setString(linia);
        
        tablicaText[0].setPosition(1180 - ((znaki/2.0 )* 40.0),700);

        opcjeText[EKRAN].setString("EKRAN");
        opcjeText[EKRAN].setPosition(620, 800);
        opcjeText[PELNY].setString("PELNY");
        opcjeText[PELNY].setPosition(960, 800);
        opcjeText[RAMKA].setString("RAMKA");
        opcjeText[RAMKA].setPosition(1200, 800);

        opcjeText[WSTEC].setString("WSTECZ");
        opcjeText[WSTEC].setPosition(875, 900);

        opcjeText[aktualnyWyborMenu].setFillColor(Color::Red);
        opcjeText[aktualnyWyborMenu].setOutlineColor(Color::Black);
        break;
    case POWYNIKI:
        
        opcjeText[WSTEC].setCharacterSize(40);
        opcjeText[WSTEC].setFont(czcionka);
        opcjeText[WSTEC].setFillColor(Color::Red);
        opcjeText[WSTEC].setOutlineThickness(1.0f);
        opcjeText[WSTEC].setOutlineColor(Color::Black);
        opcjeText[WSTEC].setString("WSTECZ");
        opcjeText[WSTEC].setPosition(875, 900);

        opcjeText[aktualnyWyborMenu].setFillColor(Color::Red);
        opcjeText[aktualnyWyborMenu].setOutlineColor(Color::Black);
        break;
    case POTWORCY:
        opcjeText[0].setString("Dominik Grudzieñ");
        opcjeText[0].setPosition(760, 300);
        opcjeText[1].setString("Patryk Grzywacz");
        opcjeText[1].setPosition(760, 400);
        opcjeText[2].setString("Adrian Pelka");
        opcjeText[2].setPosition(810, 500);

        for (int i = 0; i < 11; i++)
        {
        opcjeText[i].setCharacterSize(40);
        opcjeText[i].setFont(czcionka);
        opcjeText[i].setFillColor(Color::Black);
        opcjeText[i].setOutlineThickness(1.0f);
        opcjeText[i].setOutlineColor(Color::Red);
        }

        opcjeText[WSTEC].setFillColor(Color::Red);
        opcjeText[WSTEC].setOutlineColor(Color::Black);
        opcjeText[WSTEC].setString("WSTECZ");
        opcjeText[WSTEC].setPosition(875, 900);

        opcjeText[aktualnyWyborMenu].setFillColor(Color::Red);
        opcjeText[aktualnyWyborMenu].setOutlineColor(Color::Black);
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
    case POOPCJE:
        przygotujStrone();
        okno.draw(strzalkaSprite);
        okno.draw(kontrolerSprite);
        okno.draw(goraSprite);
        okno.draw(dolSprite);
        okno.draw(prawoSprite);
        okno.draw(lewoSprite);
        okno.draw(opcjeSprite);
        okno.draw(plusSprite);
        okno.draw(minusSprite);
        okno.draw(tablicaText[0]);
        for (int i = 0; i < 11; i++)
        {
            okno.draw(opcjeText[i]);
        }
        break;
    case POWYNIKI:
        przygotujStrone();
        okno.draw(strzalkaSprite);
        okno.draw(opcjeText[WSTEC]);
        for (int i = 0; i < iloscWynikow; i++)
        {
            wynikiText[i].setPosition(660,100+((i+1)*100));
            okno.draw(wynikiText[i]);
        }
        break;
    case POTWORCY:
        przygotujStrone();
        okno.draw(strzalkaSprite);
        for(int i = 0; i < 3 ; i++)  okno.draw(opcjeText[i]);
        okno.draw(opcjeText[WSTEC]);
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
            tablicaText[i].setOutlineColor(Color::Red);
        }
        tablicaText[aktualnyWyborMenu].setFillColor(Color::Red);
        tablicaText[aktualnyWyborMenu].setOutlineColor(Color::Black);
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
            tablicaText[i].setOutlineColor(Color::Red);
        }
        tablicaText[aktualnyWyborMenu].setFillColor(Color::Red);
        tablicaText[aktualnyWyborMenu].setOutlineColor(Color::Black);
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
    case POOPCJE:
        for (int i = 8; i < 11; i++)
        {
            opcjeText[i].setFillColor(Color::Black);
            opcjeText[i].setOutlineColor(Color::Red);
        }
        opcjeText[aktualnyWyborMenu].setFillColor(Color::Red);
        opcjeText[aktualnyWyborMenu].setOutlineColor(Color::Black);
        switch (aktualnyWyborMenu)
        {   
        case 6:
            strzalkaSprite.setPosition(455, 666);
            break;
        case 8:
            strzalkaSprite.setPosition(455, 766);
            break;
        case 9:
            strzalkaSprite.setPosition(455, 766);
            break;
        case 10:
            strzalkaSprite.setPosition(710, 866);
            break;
        }
        break;
    case POWYNIKI:
        opcjeText[aktualnyWyborMenu].setFillColor(Color::Red);
        strzalkaSprite.setPosition(710, 866);
        break;
    case POTWORCY:
        opcjeText[aktualnyWyborMenu].setFillColor(Color::Red);
        strzalkaSprite.setPosition(710, 866);
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
            obszar = IntRect((tablicaText[i].getPosition().x*procX), (tablicaText[i].getPosition().y*procY),(liczbaLiter * 37 * procX),(40 * procY));
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
            obszar = IntRect((tablicaText[i].getPosition().x * procX),( tablicaText[i].getPosition().y * procY),( liczbaLiter * 37 * procX),( 40 * procY));
            if (obszar.contains(x, y))
            {
                aktualnyWyborMenu = i;
                aktualizacjaMenu();
            }
        }
        break;
    case POOPCJE:
        for (int i = 8; i < 11; i++)
        {
            String tekst = opcjeText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect((opcjeText[i].getPosition().x * procX),( opcjeText[i].getPosition().y * procY), (liczbaLiter * 40 * procX),( 40 * procY));
            if (obszar.contains(x, y))
            {
                aktualnyWyborMenu = i;
                aktualizacjaMenu();
            }
        }
        obszar = IntRect((plusSprite.getPosition().x * procX),( plusSprite.getPosition().y * procY),( 51 * procX), (51 * procY));
        if (obszar.contains(x, y))
        {
            aktualnyWyborMenu = 6;
            aktualizacjaMenu();
        }
        obszar = IntRect((minusSprite.getPosition().x * procX), (minusSprite.getPosition().y * procY), (51 * procX), (51 * procY));
        if (obszar.contains(x, y))
        {
            aktualnyWyborMenu = 6;
            aktualizacjaMenu();
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
            obszar = IntRect(tablicaText[i].getPosition().x * procX, tablicaText[i].getPosition().y * procY, liczbaLiter * 37 * procX, 40 * procY);
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
            obszar = IntRect(tablicaText[i].getPosition().x * procX, tablicaText[i].getPosition().y * procY, liczbaLiter * 37 * procX, 40 * procY);
            if (obszar.contains(x, y))
            {   
                aktualnyWyborMenu = i;
                enter(okno);
            }
        }
        break;
    case POOPCJE:
        for (int i = 8; i < 11; i++)
        {
            String tekst = opcjeText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect(opcjeText[i].getPosition().x * procX, opcjeText[i].getPosition().y * procY, liczbaLiter * 37 * procX, 40 * procY);
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
        obszar = IntRect(plusSprite.getPosition().x * procX, plusSprite.getPosition().y * procY,51 * procX,51 * procY);
        if (obszar.contains(x, y))
        {   
            if (poziomMuzyki == 30.0f){}
            else
            {
                poziomMuzyki += 3.0f;
                menuMuzyka[numerMuzyki].setVolume(poziomMuzyki);
                break;
            }
        } 
        obszar = IntRect(minusSprite.getPosition().x * procX, minusSprite.getPosition().y * procY,51 * procX,51 * procY);
        if (obszar.contains(x, y))
        {   
            if (poziomMuzyki == 0.0f){}
            else
            {
                poziomMuzyki -= 3.0f;
                menuMuzyka[numerMuzyki].setVolume(poziomMuzyki);
                break;
            }
        }
        break;
    case POWYNIKI:
        for (int i = WSTEC; i <= WSTEC; i++)
        {
            String tekst = opcjeText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect(opcjeText[i].getPosition().x * procX, opcjeText[i].getPosition().y * procY, liczbaLiter * 37 * procX, 40 * procY);
            if (obszar.contains(x, y))
            {
                aktualnyWyborMenu = WSTEC;
                enter(okno);
            }
        }
        break;
    case POTWORCY:
        for (int i = WSTEC; i <= WSTEC; i++)
        {
            String tekst = opcjeText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect(opcjeText[i].getPosition().x * procX, opcjeText[i].getPosition().y * procY, liczbaLiter * 37 * procX, 40 * procY);
            if (obszar.contains(x, y))
            {
                aktualnyWyborMenu = WSTEC;
                enter(okno);
            }
        }
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
        case OPCJE:
            podstronaMenu = POOPCJE;
            aktualnyWyborMenu = 9;
            aktualizacjaMenu();
            break;
        case WYNIKI:
            podstronaMenu = POWYNIKI;
            aktualnyWyborMenu = WSTEC;
            aktualizacjaMenu();
            break;
        case TWORCY:
            podstronaMenu = POTWORCY;
            aktualnyWyborMenu = WSTEC;
            aktualizacjaMenu();
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
    case POOPCJE:
        switch (aktualnyWyborMenu)
        {
        case PELNY:
            okno.create(VideoMode(1920, 1080), "Snake", Style::Fullscreen | Style::Close);
            okno.setFramerateLimit(60);
            break;
        case RAMKA:
            okno.create(VideoMode(1920, 1080), "Snake", Style::Titlebar | Style::Close | Style::Resize);
            okno.setFramerateLimit(60);
            break;
        case WSTEC:
            aktualnyWyborMenu = 0;
            podstronaMenu = GLOWNA;
            aktualizacjaMenu();
            break;
        }
    case POWYNIKI:
        switch (aktualnyWyborMenu)
        {
        case WSTEC:
            aktualnyWyborMenu = 0;
            podstronaMenu = GLOWNA;
            aktualizacjaMenu();
            break;
        }
    case POTWORCY:
        switch (aktualnyWyborMenu)
        {
        case WSTEC:
            aktualnyWyborMenu = 0;
            podstronaMenu = GLOWNA;
            aktualizacjaMenu();
            break;
        }
    break;
    }
}

bool Menu::start(RenderWindow& okno)
{   
    menuMuzyka[numerMuzyki].play();
    while (okno.isOpen())
    {
        if (menuMuzyka[numerMuzyki].getStatus() == SoundSource::Stopped)
        {   
            numerMuzyki++;
            if (numerMuzyki > 3) numerMuzyki = 0;
            menuMuzyka[numerMuzyki].play();
        }
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
            case Event::Resized:
                double x1, y1;
                x1 = okno.getSize().x;
                y1 = okno.getSize().y;
                procX = (x1 / 1920.0);
                procY = (y1 / 1080.0);
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
                    case POOPCJE:
                        if (aktualnyWyborMenu == WSTEC)
                            continue;
                        else
                        {
                            aktualnyWyborMenu++;
                            aktualizacjaMenu();
                        }
                        break;
                    case POWYNIKI:
                        aktualnyWyborMenu = WSTEC;
                        aktualizacjaMenu();
                        break;
                    case POTWORCY:
                        aktualnyWyborMenu = WSTEC;
                        aktualizacjaMenu();
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
                    case POOPCJE:
                        if (aktualnyWyborMenu == PELNY)
                            continue;
                        else
                        {
                            aktualnyWyborMenu--;
                            aktualizacjaMenu();
                        }
                        break;
                    case POWYNIKI:
                        aktualnyWyborMenu = WSTEC;
                        aktualizacjaMenu();
                        break;
                    case POTWORCY:
                        aktualnyWyborMenu = WSTEC;
                        aktualizacjaMenu();
                        break;
                    }
                }
                if (zdarzenie.key.code == Keyboard::Escape)
                {   
                    if (podstronaMenu != GLOWNA)
                    {
                        aktualnyWyborMenu = 0;
                        menuDzwiekZatwierdzMenu.play();
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
                double x, y;
                x = zdarzenie.mouseMove.x;
                y = zdarzenie.mouseMove.y;
                ruchMyszka(x, y);
            }
            case Event::MouseButtonPressed:
            {
                if (zdarzenie.mouseButton.button == Mouse::Left)
                {
                    double x, y;
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