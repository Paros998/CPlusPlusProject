/*! \file Menu.cpp
*   \brief Plik ten zawiera ciala metod, konstruktorow , inicjalizacje zmiennych ,enumeratorow  , tworzenie obiektow etc.
*/

/*! \enum wyborMenu  {START,OPCJE,WYNIKI,TWORCY,WYJSCIE}
*   \brief Enumerator ten ulatwia orientowanie sie w menu po przyjaznych nazwach.
*/
/*! \enum wyborPodstronyMenu {GLOWNA,POSTART,POOPCJE,POWYNIKI,POTWORCY,PRZEDGRA}
*   \brief Enumerator ten ulatwia orientowanie sie w menu po przyjaznych nazwach.
*/
/*! \enum wyborPoStart {DALEJ,WSTECZ}
*   \brief Enumerator ten ulatwia orientowanie sie w menu po przyjaznych nazwach.
*/
/*! \enum wyborPoWynikiPoTworcy {POWROT}
*   \brief Enumerator ten ulatwia orientowanie sie w menu po przyjaznych nazwach.
*/
/*! \enum opcjeTekst {STEROWANIE,GORA,DOL,PRAWO,LEWO,USTAWIENIA,MUZYKA,EKRAN,PELNY,RAMKA,WSTEC}
*   \brief Enumerator ten ulatwia orientowanie sie po tablicy tekstow.
*/
#include "Menu.h"

enum wyborMenu  {START,OPCJE,WYNIKI,TWORCY,WYJSCIE};
enum wyborPodstronyMenu {GLOWNA,POSTART,POOPCJE,POWYNIKI,POTWORCY,PRZEDGRA};
enum wyborPoStart {DALEJ,WSTECZ};
enum wyborPoWynikiPoTworcy {POWROT};
enum opcjeTekst {STEROWANIE,GORA,DOL,PRAWO,LEWO,USTAWIENIA,MUZYKA,EKRAN,PELNY,RAMKA,WSTEC};

Menu::Menu()
{
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

    teksturaSprite = new Texture[6];
    tablicaSprite = new Sprite[6];

    teksturaSprite[0].loadFromFile("data/Obrazy menu/jablko_animacja2.png");
    teksturaSprite[0].setSmooth(true);
    tablicaSprite[0].setTexture(teksturaSprite[0]);
    tablicaSprite[0].setScale(0.26f, 0.26f);

    teksturaSprite[1].loadFromFile("data/Obrazy menu/jablko_animacja2-gold.png");
    teksturaSprite[1].setSmooth(true);
    tablicaSprite[1].setTexture(teksturaSprite[1]);
    tablicaSprite[1].setScale(0.26f, 0.26f);

    teksturaSprite[2].loadFromFile("data/Sprity do gry/Plansza/dziura.png");
    teksturaSprite[2].setSmooth(true);
    tablicaSprite[2].setTexture(teksturaSprite[2]);
    tablicaSprite[2].setScale(1.0, 1.0);

    teksturaSprite[3].loadFromFile("data/Sprity do gry/Plansza/przeszkoda1.png");
    teksturaSprite[3].setSmooth(true);
    tablicaSprite[3].setTexture(teksturaSprite[3]);
    tablicaSprite[3].setScale(1.0, 1.0);

    teksturaSprite[4].loadFromFile("data/Sprity do gry/Plansza/kamien3.png");
    teksturaSprite[4].setSmooth(true);
    tablicaSprite[4].setTexture(teksturaSprite[4]);
    tablicaSprite[4].setScale(1.0, 1.0);

    teksturaSprite[5].loadFromFile("data/Sprity do gry/Gracz i przedmioty/snake_glowa12.png");
    teksturaSprite[5].setSmooth(true);
    tablicaSprite[5].setTexture(teksturaSprite[5]);
    tablicaSprite[5].setScale(1.0, 1.0);

    for (int i = 0; i < 2; i++)
    {
        tablicaSprite[i].setPosition((float)300, (float)( ((i + 1) * 70.0 + 250.0)) );
        Rect<float> rozmiar = tablicaSprite[i].getGlobalBounds();
        tablicaSprite[i].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));
    }

    for (int i = 2; i < 6; i++)
    {
        tablicaSprite[i].setPosition((float)325, (float)( ( (i+1) * 80.0 + 250.0 )) );
        Rect<float> rozmiar = tablicaSprite[i].getGlobalBounds();
        tablicaSprite[i].setOrigin(Vector2f(rozmiar.width / 2.0f, rozmiar.height / 2.0f));
    }


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
    menuMuzyka[3].openFromFile("data/Muzyka/Winds Of Stories.ogg");
    menuMuzyka[2].openFromFile("data/Muzyka/Path to Lake Land.ogg");
    
    for (int i = 0; i < 4; i++)
    {
    menuMuzyka[i].setVolume(glosnoscMuzyki);
    }
    bufor2.loadFromFile("data/Muzyka/misc_menu_2.wav");

    menuDzwiekZatwierdzMenu.setBuffer(bufor2);
    menuDzwiekZatwierdzMenu.setVolume(6.0f);
}

Menu::~Menu() {
    delete[] tablicaText;
    delete[] opcjeText;
    delete[] wynikiText;
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
        tablicaText[DALEJ].setString("DALEJ");
        tablicaText[WSTECZ].setString("WSTECZ");
        tablicaText[DALEJ].setPosition(890, 250);
        tablicaText[WSTECZ].setPosition(870, 850);
        
        opcjeText[0].setString("Ukoñcz poziomy jedzac jablka!");
        opcjeText[0].setPosition(tablicaSprite[0].getPosition().x + 102.0f, tablicaSprite[0].getPosition().y);
        opcjeText[1].setString("Nabijaj 5 kombo pod rzad i ciesz lepszymi punktami i ochrona!");
        opcjeText[1].setPosition(tablicaSprite[1].getPosition().x + 102.0f, tablicaSprite[1].getPosition().y );

        opcjeText[2].setString("Madrze korzystaj z systemu teleportacji dziurowej!");
        opcjeText[2].setPosition(tablicaSprite[2].getPosition().x + 70.0f, tablicaSprite[2].getPosition().y - 20.0f);

        opcjeText[3].setString("Unikaj lepiej tych drobiazgów o róznym wygladzie!");
        opcjeText[3].setPosition(tablicaSprite[3].getPosition().x + 70.0f, tablicaSprite[3].getPosition().y - 20.0f);

        opcjeText[4].setString("I nie bój siê wchodzic w sciany!");
        opcjeText[4].setPosition(tablicaSprite[4].getPosition().x + 70.0f, tablicaSprite[4].getPosition().y - 20.0f);

        opcjeText[5].setString("Lepiej nie kieruj swojej glodnej paszczy na wlasne cialo!");
        opcjeText[5].setPosition(tablicaSprite[5].getPosition().x + 70.0f, tablicaSprite[5].getPosition().y - 20.0f);

        for (int i = 0; i < 6; i++)
        {
            opcjeText[i].setCharacterSize(40);
            opcjeText[i].setFont(czcionka);
            opcjeText[i].setFillColor(Color::Black);
            opcjeText[i].setOutlineColor(Color::Red);
            opcjeText[i].setOutlineThickness(1.0f);
        }

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
        procent =(int)( ( glosnoscMuzyki / 30.0 )*100 );
        unsigned int znaki;
        
        linia = "";
        linia += std::to_string(procent);
        linia += "%";
       
        znaki = linia.length();
        tablicaText[0].setString(linia);
        
        tablicaText[0].setPosition((float)( 1180 - ((znaki/2.0 )* 40.0) ), (float)700);

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
        for (int i = 0; i < 2; i++)
        {   
            okno.draw(tablicaText[i]);
        }
        for (int i = 0; i < 6; i++)
        {
            okno.draw(tablicaSprite[i]);
            okno.draw(opcjeText[i]);
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
            wynikiText[i].setPosition((float)660.0, (float)( 200.0+(((float)i+1.0)*100.0)) );
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
            strzalkaSprite.setPosition(300, 206);
            break;
        case 1:
            strzalkaSprite.setPosition(280, 806);
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
            obszar = IntRect((int)(tablicaText[i].getPosition().x*procX), (int)(tablicaText[i].getPosition().y*procY),(int)(liczbaLiter * 37.0 * procX),(int)(40.0 * procY));
            if (obszar.contains(x, y)) 
            {
                aktualnyWyborMenu = i;
                aktualizacjaMenu();
            }
        }
        break;
    case POSTART:
        for (int i = 0; i < 2; i++)
        {
            String tekst = tablicaText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect((int)(tablicaText[i].getPosition().x * procX), (int)( tablicaText[i].getPosition().y * procY), (int)( liczbaLiter * 37 * procX), (int)( 40 * procY));
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
            obszar = IntRect((int)(opcjeText[i].getPosition().x * procX), (int)( opcjeText[i].getPosition().y * procY), (int)(liczbaLiter * 37 * procX), (int)( 40 * procY));
            if (obszar.contains(x, y))
            {
                aktualnyWyborMenu = i;
                aktualizacjaMenu();
            }
        }
        obszar = IntRect((int)(plusSprite.getPosition().x * procX), (int)( plusSprite.getPosition().y * procY), (int)( 51 * procX), (int)(51 * procY));
        if (obszar.contains(x, y))
        {
            aktualnyWyborMenu = 6;
            aktualizacjaMenu();
        }
        obszar = IntRect((int)(minusSprite.getPosition().x * procX), (int)(minusSprite.getPosition().y * procY), (int)(51 * procX), (int)(51 * procY));
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
            obszar = IntRect((int)(tablicaText[i].getPosition().x * procX), (int)(tablicaText[i].getPosition().y * procY), (int)(liczbaLiter * 37 * procX), (int)(40 * procY));
            if (obszar.contains(x, y))
            {
                aktualnyWyborMenu = i;
                enter(okno);
            }
        }
        break;
    case POSTART:
        for (int i = 0; i < 2; i++)
        {
            String tekst = tablicaText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect((int)(tablicaText[i].getPosition().x * procX), (int)(tablicaText[i].getPosition().y * procY), (int)(liczbaLiter * 37 * procX), (int)(40 * procY));
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
            obszar = IntRect((int)(opcjeText[i].getPosition().x * procX), (int)(opcjeText[i].getPosition().y * procY), (int)(liczbaLiter * 37 * procX), (int)(40 * procY));
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
        obszar = IntRect((int)(plusSprite.getPosition().x * procX), (int)(plusSprite.getPosition().y * procY), (int)(51 * procX), (int)(51 * procY));
        if (obszar.contains(x, y))
        {   
            if (glosnoscMuzyki == 30.0f){}
            else
            {
                glosnoscMuzyki += 3.0f;
                menuMuzyka[numerMuzyki].setVolume(glosnoscMuzyki);
                break;
            }
        } 
        obszar = IntRect((int)(minusSprite.getPosition().x * procX), (int)(minusSprite.getPosition().y * procY), (int)(51 * procX), (int)(51 * procY));
        if (obszar.contains(x, y))
        {   
            if (glosnoscMuzyki == 0.0f){}
            else
            {
                glosnoscMuzyki -= 3.0f;
                menuMuzyka[numerMuzyki].setVolume(glosnoscMuzyki);
                break;
            }
        }
        break;
    case POWYNIKI:
        for (int i = WSTEC; i <= WSTEC; i++)
        {
            String tekst = opcjeText[i].getString();
            int liczbaLiter = tekst.getSize();
            obszar = IntRect((int)(opcjeText[i].getPosition().x * procX), (int)(opcjeText[i].getPosition().y * procY), (int)(liczbaLiter * 37 * procX), (int)(40 * procY));
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
            obszar = IntRect((int)(opcjeText[i].getPosition().x * procX), (int)(opcjeText[i].getPosition().y * procY), (int)(liczbaLiter * 37 * procX), (int)(40 * procY));
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
        case DALEJ:
            aktualnyWyborMenu = 0;
            podstronaMenu = PRZEDGRA;
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
            okno.setKeyRepeatEnabled(false);
            aktualizacjaMenu();
            break;
        case RAMKA:
            okno.create(VideoMode(1920, 1080), "Snake", Style::Titlebar | Style::Close | Style::Resize);
            okno.setFramerateLimit(60);
            okno.setKeyRepeatEnabled(false);
            aktualizacjaMenu();
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

int Menu::start(RenderWindow& okno)
{
    numerMuzyki = 0;
    menuMuzyka[numerMuzyki].play();
    while (okno.isOpen())
    {
        if (menuMuzyka[numerMuzyki].getStatus() == SoundStream::Stopped)
        {
            numerMuzyki++;
            if (numerMuzyki > 3)
            {
                numerMuzyki = 0;
            }
            menuMuzyka[numerMuzyki].play();
        }
        // Obs³uga zdarzeñ
        Event zdarzenie;
        while (okno.pollEvent(zdarzenie))
        {
            switch (zdarzenie.type)
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
                        if (aktualnyWyborMenu == DALEJ)
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
                    if (podstronaMenu == PRZEDGRA)
                    {
                        switch (aktualnyWyborMenu)
                        {
                        case 0:
                            return 1;
                            break;
                        }
                    }
                    break;
                }
            case Event::MouseMoved:
            {
                double x, y;
                x = zdarzenie.mouseMove.x;
                y = zdarzenie.mouseMove.y;
                ruchMyszka((int)x, (int)y);
            }
            case Event::MouseButtonPressed:
            {
                if (zdarzenie.mouseButton.button == Mouse::Left)
                {
                    double x, y;
                    x = zdarzenie.mouseButton.x;
                    y = zdarzenie.mouseButton.y;
                    klikMyszka((int)x, (int)y, okno);
                    if (podstronaMenu == PRZEDGRA)
                    {
                        switch (aktualnyWyborMenu)
                        {
                        case 0:
                            return 1;
                            break;
                        }
                    }
                }
            }
            default:
                break;
            }
        }
        poruszajTlo();
        okno.clear(Color::Green);
        // Rysowanie ...
        rysuj(okno);
        okno.display();
    }
    return 0;
}