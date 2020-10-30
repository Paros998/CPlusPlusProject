#include "Aplikacja.h"

Aplikacja::Aplikacja() 
{
    oknoAplikacji.create(VideoMode(1920, 1080), "Snake", Style::Titlebar | Style::Close | Style::Resize);
    oknoAplikacji.setFramerateLimit(60);
}

void Aplikacja::start()
{
    Menu menu;
    while (true)
    {
        if (!menu.start(oknoAplikacji))
            break;
    }
}