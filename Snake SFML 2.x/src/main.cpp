/*!  \file main.cpp
*   \brief Plik Zawierajacy glowna funkcje Gry
*   \n
*   Tworzy obiekt apk klasy Aplikacja i wywoluje metode start.
*/

/*! \fn main()
*   \brief Funkcja glowna aplikacji
    \return 0
    \n Zwraca 0 przy zakonczeniu aplikacji
*/

/*! \var Aplikacja apk
*   \brief Obiekt typu Aplikacja 
*/
#include "Aplikacja.h"
int main()
{
    Aplikacja apk;
    apk.start();
    
    return 0;
}
