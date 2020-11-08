#include "Aplikacja.h"

Aplikacja::Aplikacja() 
{
    oknoAplikacji.create(VideoMode(1920, 1080), "Snake", Style::Titlebar | Style::Close | Style::Resize);
    oknoAplikacji.setFramerateLimit(60);
}

void Aplikacja::start()
{       
    srand(time(0));
    int poziom = P1;
    while (true)
    {
       if (poziom == MENU)
        {   
            Menu menu;
            poziom = menu.start(oknoAplikacji);
        }
        if (poziom == P1)
        {
            Poziom1 p1;
            if (!p1.start(oknoAplikacji));
        }
        break;
    }
}