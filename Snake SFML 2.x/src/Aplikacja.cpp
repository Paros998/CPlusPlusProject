/*! \file Aplikacja.cpp
*   \brief Zawiera ciala konstruktorow ,destruktorow i metod klasy Aplikacja
*/
#include "Aplikacja.h"

Aplikacja::Aplikacja() 
{
    oknoAplikacji.create(VideoMode(1920, 1080), "Snake", Style::Titlebar | Style::Close | Style::Resize);
    oknoAplikacji.setFramerateLimit(60);
    oknoAplikacji.setKeyRepeatEnabled(false);
}

void Aplikacja::start()
{       
    srand(time(0));
    int poziom = MENU;
    while (true)
    {
       if (poziom == MENU)
        {   
            Menu menu;
            poziom = menu.start(oknoAplikacji);
        }
        if (poziom == P1)
        {
            int podpoziom = P1;
            while (podpoziom != 0)
            {
                if (podpoziom == 1)
                {   
                    Poziom1* p1 = new Poziom1;
                    podpoziom = p1->start(oknoAplikacji);
                    delete p1;
                }
                if (podpoziom == 2)
                {   
                    Poziom2* p2 = new Poziom2;
                    podpoziom = p2->start(oknoAplikacji);
                    delete p2;
                }
                if (podpoziom == 3)
                {   
                    Poziom3* p3 = new Poziom3;
                    podpoziom = p3->start(oknoAplikacji);
                    delete p3;
                }
            }
            if (podpoziom == 0) return;
        }
        break;
    }
}