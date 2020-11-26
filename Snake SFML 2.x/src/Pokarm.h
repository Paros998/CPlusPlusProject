/*! \file Pokarm.h
	\brief Plik zawierajacy definicje klasy Pokarm.
*/

/*! \class Pokarm
	\brief Klasa odpowiedzialna za obsluge pokarmu dla weza.

	Znajduja sie w niej funkcje  tjk.:\n
	- ustalanie dokladnej nowej pozycji pokarmu\n
	- rysowanie pokarmu\n
	- dodawanie punktow za zjedzenie pokarmu
*/

/************************************************
 *	Pola klasy PRIVATE
 ***********************************************/
/*! \var float Pokarm::x
	\brief Zmienna typu float, ktora przechowuje kordynate x z okna glownego.
	Okresla polozenie pokarmu w osi x.
*/
/*! \var float Pokarm::y
	\brief Zmienna typu float, ktora przechowuje kordynate y z okna glownego.
	Okresla polozenie pokarmu w osi y.
*/
/*! \var bool Pokarm::rysujEfekt
	\brief Zmienna typu bool, ktora sprawdza czy nalezy wykonac animacje dla pojawienia sie pokarmu.
*/
/*! \var Texture Pokarm::pokarmTekstura
	\brief Obiekt klasy Texture posiadajacy sciezke pliku do animacji poruszania sie pokarmu.
*/
/*! \var Texture Pokarm::efektTekstura
	\brief Obiekt klasy Texture posiadajacy sciezke pliku do animacji pojawienia sie pokarmu.
*/
/*! \var Sprite Pokarm::pokarmSprite
	\brief Obiekt klasy Sprite przechowujacy sprite pokarmu.
*/
/*! \var Sprite Pokarm::efektSprite
	\brief Obiekt klasy Sprite przechowujacy sprite efektu pokarmu.
*/
/*! \var Animacja* Pokarm::animacja
	\brief Wskaznik na obiekt klasy Animacja przechowujacy animacje dla pokarmu.
*/
/*! \var Animacja* Pokarm::efektSpecjalny
	\brief Wskaznik na obiekt klasy Animacja przechowujacy animacje dla efektu pokarmu.
*/
/*! \var Vector2u Pokarm::klatkiEfektu
	\brief Obiekt klasy Vector2u przechowujacy odpowiednie wartosci dla tworzenia animacji w klasie Animacja.
*/

/************************************************
 *	Pola klasy PRIVATE
 ***********************************************/
/*! \var int Pokarm::wartoscPunktow
	\brief Zmienna typu int przechowujaca informacje ile punktow mozna uzyskac za zjedzenie aktualnego pokarmu.
*/
/*! \var int Pokarm::bonus
	\brief Zmienna typu int przyjmujaca wartosci binarane (0 lub 1).

	- jesli jest rowna 1 to zaliczany jest bonus w postaci zlotego jablka\n
	- jesli jest rowna 0 to zaliczana jest normalna wartosc w postaci czerownego jablka.
*/

/************************************************
 *	Metody klasy PUBLIC
 ***********************************************/
/*! \fn Pokarm::Pokarm(string sciezkaPliku, string sciezkaPlikuEfektu, Vector2u klatkiEfektu)
	\brief Konstruktor klasy Pokarm.
	
	- inicjalizuje wszystkie zmienne potrzebne do obslugi pokarmu\n
    - laduje tekstury z plikow oraz przypisuje je do sprite'ow\n
	- ustawia animacje

	\param sciezkaPliku
	\brief Obiekt klasy string (std::string) przechowujacy odpowiednia sciezke do pliku z tekstura pokarmu.

	\param sciezkaPlikuEfektu
	\brief Obiekt klasy string (std::string) przechowujacy odpowiednia sciezke do pliku z tekstura efektu pokarmu.

	\param klatkiEfektu
	\brief Obiekt klasy Vector2u przechowujacy odpowiednie wartosci dla tworzenia animacji w klasie Animacja.
*/ 
/*! \fn Pokarm::~Pokarm()
	\brief Dekonstruktor klasy Pokarm.

	Usuwa efekt i animacje pokarmu.
*/
/*! \fn bool Pokarm::sprawdzCzyZjedzony(Gracz& gracz)
	\brief Metoda sprawdzajaca czy gracz wszedl w kolizje z pokarmem.

	Nastepnie ustalane jest kolejne polozenie pokarmu. Brane sa pod uwage przeszkody oraz cialo weza.

	\param &gracz
	\brief Referencja na obiekt klasy Gracz. Przechowuje informacje na temat gracza.

	\return bool
	\brief Metoda zwraca wartosc bool.
*/
/*! \fn void Pokarm::ustawPokarm(Gracz& gracz, Sprite** plansza, Sprite* przeszkody, int liczbaprzeszkod)
	\brief Metoda poszukujaca nowego polozenia dla pokarmu.

	Brane sa w niej pod uwage przeszkody oraz cialo weza.

	\param &gracz
	\brief Referencja na obiekt klasy Gracz. Przechowuje informacje na temat gracza.

	\param **plansza
	\brief Podwojny wskaznik na dynamiczna tablice dwuwymiarowa klasy Sprite, przechowujacy pola planszy(sprite'y).
	
	\param *przeszkody
	\brief Wskaznik na obiekt klasy Sprite. Jest tablica dynamiczna. Przechowuje sprite'y przeszkod.

	\param liczbaprzeszkod
	\brief Zmienna typu int okreslajaca ilosc przeszkod w tablicy.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn void Pokarm::rysuj(RenderWindow& okno)
	\brief Metoda odpowiedzialna za rysowanie animacji pokarmu oraz efektu pojawiania sie go na planszy.

	\param &okno
	\brief Referencja na obiekt klasy RenderWindow wykorzystywana do rysowania gracza w glownym oknie.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn void Pokarm::wyzerujAnimacje()
	\brief Metoda odpowiedzialna za ustawienie animacji na start.
	
	\param void
	\brief Metoda nie przyjmuje zadnych argumentow.

	\return Metoda nie zwraca zadnej wartosci.
*/
#pragma once
#include "Biblioteki.h"

class Gracz;
class Animacja;

class Pokarm
{
	float x, y;
	bool rysujEfekt;
	Texture pokarmTekstura, efektTekstura;
	Sprite pokarmSprite, efektSprite;
	Animacja* animacja, * efektSpecjalny;
	Vector2u klatkiEfektu;

public:
	Pokarm(string sciezkaPliku, string sciezkaPlikuEfektu, Vector2u klatkiEfektu);
	~Pokarm();
	bool sprawdzCzyZjedzony(Gracz& gracz);
	void ustawPokarm(Gracz& gracz, Sprite** plansza, Sprite* przeszkody, int liczbaprzeszkod);
	void rysuj(RenderWindow& okno);
	void wyzerujAnimacje();
	int wartoscPunktow;
	int bonus;
};

