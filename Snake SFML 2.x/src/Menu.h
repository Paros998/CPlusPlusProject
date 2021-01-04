/*!	\file Menu.h
*	\brief Plik ten zawiera definicje klasy Menu,
	zmiennych obiektow,tablic oraz konstruktor,destruktorow i metod tej klasy.
*/

/*!	\class Menu
*	\brief Klasa ta odpowiada za dzialanie menu glownego gry
*/

/*!	\var Texture Menu::menuTekstura
*	\brief Zmienna typu Texture przechowujaca teksture tla menu glownego
*/
/*!	\var Texture Menu::logoTekstura
*	\brief Zmienna typu Texture przechowujaca teksture logo menu glownego
*/
/*!	\var Texture Menu::strzalkaTekstura
*	\brief Zmienna typu Texture przechowujaca teksture strzalki menu glownego
*/
/*!	\var Texture Menu::plusTekstura
*	\brief Zmienna typu Texture przechowujaca teksture plusa do zmiany glosnosci muzyki w opcjach 
*/
/*!	\var Texture Menu::minusTekstura
*	\brief Zmienna typu Texture przechowujaca teksture minusa do zmiany glosnosci muzyki w opcjach 
*/
/*!	\var Texture Menu::opcjeTekstura
*	\brief Zmienna typu Texture przechowujaca teksture znaczka opcji
*/
/*!	\var Texture Menu::ludzikiTekstura
*	\brief Zmienna typu Texture przechowujaca teksture znaczka osob
*/
/*!	\var Texture Menu::kontrolerTekstura
*	\brief Zmienna typu Texture przechowujaca teksture znaczka kontrolera
*/
/*!	\var Texture Menu::dolTekstura
*	\brief Zmienna typu Texture przechowujaca teksture znaczka strzalki w dol
*/
/*!	\var Texture Menu::goraTekstura
*	\brief Zmienna typu Texture przechowujaca teksture znaczka strzalki w gore
*/
/*!	\var Texture Menu::lewoTekstura
*	\brief Zmienna typu Texture przechowujaca teksture znaczka strzalki w lewo
*/
/*!	\var Texture Menu::prawoTekstura
*	\brief Zmienna typu Texture przechowujaca teksture znaczka strzalki w prawo
*/

/*!	\var Sprite Menu::menuSprite
*	\brief Zmienna typu Sprite przechowujaca tlo menu glownego gry
*/
/*!	\var Sprite Menu::logoSprite
*	\brief Zmienna typu Sprite przechowujaca logo menu glownego gry
*/
/*!	\var Sprite Menu::strzalkaSprite
*	\brief Zmienna typu Sprite przechowujaca strzalke menu glownego gry
*/
/*!	\var Sprite Menu::plusSprite
*	\brief Zmienna typu Sprite przechowujaca plus w opcjach gry
*/
/*!	\var Sprite Menu::minusSprite
*	\brief Zmienna typu Sprite przechowujaca minus w opcjach gry
*/
/*!	\var Sprite Menu::opcjeSprite
*	\brief Zmienna typu Sprite przechowujaca znaczek opcje
*/
/*!	\var Sprite Menu::ludzikiSprite
*	\brief Zmienna typu Sprite przechowujaca znaczek osob
*/
/*!	\var Sprite Menu::kontrolerSprite
*	\brief Zmienna typu Sprite przechowujaca znaczek kontrolera
*/
/*!	\var Sprite Menu::dolSprite
*	\brief Zmienna typu Sprite przechowujaca znaczek strzalki w dol
*/
/*!	\var Sprite Menu::goraSprite
*	\brief Zmienna typu Sprite przechowujaca znaczek strzalki w gore
*/
/*!	\var Sprite Menu::lewoSprite
*	\brief Zmienna typu Sprite przechowujaca znaczek strzalki w lewo
*/
/*!	\var Sprite Menu::prawoSprite
*	\brief Zmienna typu Sprite przechowujaca znaczek strzalki w prawo
*/

/*!	\var Sprite* Menu::tablicaSprite
*	\brief Zmienna wskaznikowa przechowujaca wskaznik na tablice sprite do menu postartowego
*/
/*!	\var Texture* Menu::teksturaSprite
*	\brief Zmienna wskaznikowa przechowujaca wskaznik na tablice tekstur do menu postartowego
*/
/*!	\var Text* Menu::tablicaText
*	\brief Zmienna wskaznikowa przechowujaca wskaznik na tablice tekstu do menu glownego
*/
/*!	\var Text* Menu::opcjeText
*	\brief Zmienna wskaznikowa przechowujaca wskaznik na tablice tekstu do opcji
*/
/*!	\var Text* Menu::wynikiText
*	\brief Zmienna wskaznikowa przechowujaca wskaznik na tablice tekstu do wynikow
*/

/*!	\var ifstream Menu::wynikiPlik
*	\brief Zmienna typu ifstream do zczytywania danych z pliku wynikowego
*/

/*!	\var string Menu::linia
*	\brief Zmienna pomocnicza
*/

/*!	\var Music* Menu::menuMuzyka
*	\brief Zmienna wskaznikowa na tablice obiektow typu Music do streamowania muzyki w menu glownym
*/

/*!	\var Sound Menu::menuDzwiekZatwierdzMenu
*	\brief Obiekt typu Sound umozliwiajacy wlaczanie dzwieku przekazanego mu przez bufor2
*/

/*!	\var SoundBuffer Menu::bufor2
*	\brief Obiekt typu SoundBuffer umozliwiajacy zczytywanie z dysku dzwieku
*/

/*!	\var Font Menu::czcionka
*	\brief Obiekt typu Font przechowujacy typ czcionki tekstu
*/

/*!	\var IntRect Menu::obszar
*	\brief Obiekt typu IntRect pozwalajacy na dokladne sprawdzanie klikniec myszki w menu 
*/

/*!	\var int Menu::kierunekTla
*	\brief Zmienna nadajaca kierunek ruchu tla 
*/
/*!	\var int Menu::aktualnyWyborMenu
*	\brief Zmienna okreslajaca wybor w menu 
*/
/*!	\var int Menu::podstronaMenu
*	\brief Zmienna okreslajaca podstrone w menu glownym 
*/
/*!	\var int Menu::iloscWynikow
*	\brief Zmienna pomocnicza przy wypisywaniu wynikow
*/
/*!	\var int Menu::numerMuzyki
*	\brief Zmienna okreslajaca ktora muzyka jest grana
*/

/*!	\var double Menu::procX
*	\brief Zmienna okreslajaca procentowy rozmiar okna w poziomie od wartosci 1920
*/
/*!	\var double Menu::procY
*	\brief Zmienna okreslajaca procentowy rozmiar okna w pionie od wartosci 1080
*/

/*!	\fn Menu::Menu()
*	\brief Jest to konstruktor obiektu klasy Menu
*	Inicjalizuje on zmienne,obiekty ,tablice itd
*/

/*!	\fn Menu::~Menu()
*	\brief Jest to dekonstruktor obiektu klasy Menu
*	Niszczy on dynamicznie utworzone tablice w konstruktorze
*/

/*!	\fn int Menu::start(RenderWindow& okno)
*	\brief Metoda ktora uruchamia menu glowne
*	\param okno
*	\brief okno to referencja na obiekt typu RenderWindow sluzacy do rysowania elementow 2d w tym oknie
*	\return int
*	\brief Metoda ta zwraca 0 lub 1
*	Zwraca 1 gdy uzytkownik rozpocznie granie a 0 gdy chce wyjsc z gry
*/

/*!	\fn void Menu::poruszajTlo()
*	\brief Metoda ta ma za zadanie poruszac tlem menu glownego
*	\return void
*	\brief Nic nie zwraca
*/

/*!	\fn void Menu::rysuj(RenderWindow& okno)
*	\brief Metoda ta ma za zadanie rysowanie odpowiedniego podmenu menu glownego .
*	\param okno
*	\brief okno to referencja na obiekt typu RenderWindow sluzacy do rysowania elementow 2d w tym oknie
*	\return void
*	\brief Nic nie zwraca
*/

/*!	\fn void Menu::przygotujStrone()
*	\brief Metoda ta przygotowuje odpowiednie zasoby do rysowania dla danej podstrony i wyboru uzytkownika
*	\return void
*	\brief Nic nie zwraca
*/

/*!	\fn void Menu::aktualizacjaMenu()
*	\brief Metoda ta ma za zadanie odpowiednio aktualizowac widok wyboru uzytkownika
*	\return void
*	\brief Nic nie zwraca
*/

/*!	\fn void Menu::ruchMyszka(int x,int y)
*	\brief Metoda ta oblicza czy myszka najechala na ktorys interaktywny element
*	\param x
*	\brief miejsce myszki w poziomie na ekranie w pixelach od lewego gornego rogu okna
*	\param y 
*	\brief miejsce myszki w pionie na ekranie w pixelach od lewego gornego rogu okna
*	\return void
*	\brief Nic nie zwraca
*/
/*!	\fn void Menu::klikMyszka(int x,int y, RenderWindow& okno)
*	\brief Metoda ta oblicza czy myszka najechala na ktorys interaktywny element
*	\param x
*	\brief miejsce myszki w poziomie na ekranie w pixelach od lewego gornego rogu okna
*	\param y 
*	\brief miejsce myszki w pionie na ekranie w pixelach od lewego gornego rogu okna
*	\param okno
*	\brief okno to referencja na obiekt typu RenderWindow sluzacy do rysowania elementow 2d w tym oknie
*	\return void
*	\brief Nic nie zwraca
*/

/*!	\fn void Menu::enter(RenderWindow& okno)
*	\brief Metoda ta ma za zadanie zmieniac podtstrony menu lub uruchamiac poziom czy tez konczyc dzialanie aplikacji
*	\param okno
*	\brief okno to referencja na obiekt typu RenderWindow sluzacy do rysowania elementow 2d w tym oknie
*	\return void
*	\brief Nic nie zwraca
*/
#pragma once
#include "Biblioteki.h"

class Menu
{
	Texture menuTekstura,logoTekstura,strzalkaTekstura,plusTekstura,minusTekstura,opcjeTekstura,ludzikiTekstura,kontrolerTekstura,dolTekstura,goraTekstura,lewoTekstura,prawoTekstura;
	Sprite menuSprite,logoSprite,strzalkaSprite,plusSprite,minusSprite,opcjeSprite,ludzikiSprite,kontrolerSprite,dolSprite,goraSprite,lewoSprite,prawoSprite;
	Sprite *tablicaSprite;
	Texture *teksturaSprite;
	Text *tablicaText,*opcjeText,*wynikiText;
	ifstream wynikiPlik;
	string linia;
	Music *menuMuzyka; 
	Sound menuDzwiekZatwierdzMenu;
	SoundBuffer bufor2;
	Font czcionka;
	IntRect obszar;
	int kierunekTla,aktualnyWyborMenu,podstronaMenu,iloscWynikow, numerMuzyki;
	double procX, procY;
public:
	Menu();
	~Menu();
	int start(RenderWindow& okno);
private:
	void poruszajTlo();
	void rysuj(RenderWindow& okno);
	void przygotujStrone();
	void aktualizacjaMenu();
	void ruchMyszka(int x,int y);
	void klikMyszka(int x,int y, RenderWindow& okno);
	void enter(RenderWindow& okno);

};

