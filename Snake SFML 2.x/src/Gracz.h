/*! \file Gracz.h
	\brief Plik zawierajacy definicje klasy gracza.
*/

/************************************************
 *	Pola klasy PRIVATE
 ***********************************************/
/*! \class Gracz
	\brief Klasa odpowiedzialna za obsluge gracza.

	Znajduja sie w niej funkcje  tjk.:\n
	- ruch gracza\n
	- obsluga dynamicznej listy dwukierunkowej\n
	- obsluga zegarow\n
	- obsluga tekstur oraz animacji\n
	- detekcja kolizji dziura - waz\n
	- detekcja kolizji przeszkoda - waz\n
	- detekcja kolizji waz - waz\n
*/
/*! \var int Gracz::Poziom
	\brief Zmienna typu int informujaca o aktualnym poziomie rozgrywki.
*/
/*! \var float Gracz::rozmiar_weza
	\brief Zmienna typu float przechowujaca rozmiar weza.

	Stosowana w ruchu weza. Dzieki niej waz dopasowany jest do planszy.
*/
/*! \var float Gracz::opoznienie
	\brief Zmienna typu float, przechowujaca wartosc opoznienia ruchu weza.

	Stosowana w opoznianiu ruchu.
*/
/*! \var float Gracz::mnoznikCzasu
	\brief Zmienna typu float, przechowujaca mnoznik.

	Zaleznie od poziomu zwieksza sie ona, powodujac szybkie poruszanie sie weza.
*/
/*! \var bool Gracz::ustawTeksture
	\brief Pomocnicza zmienna typu bool.

	Jesli ma wartosc true to pozwala zatrzymac animacje ochrony przed kolizja oraz ustawic teksture nieprzezroczysta.
*/
/*! \var Texture Gracz::graczCialoTekstura
	\brief Obiekt klasy Texture, przechowujacy teksture ciala weza.
*/
/*! \var Texture Gracz::graczGlowaTekstura
	\brief Obiekt klasy Texture, przechowujacy teksture glowy weza.
*/
/*! \var Sprite* Gracz::graczSprite
	\brief Wskaznik na obiekt klasy Sprite.

	Stosowany jest do dynamicznej tablicy dwuelementowej. Przechowuje ona sprite'y glowy i ciala weza. 
*/
/*! \var String Gracz::tablicaStringCialoTekstura[3][8]
	\brief Tablica dwuwymiarowa obiektow klasy String(sf::String).
	
	Zawarte sa w niej sciezki do tekstur weza.
*/
/*! \var String Gracz::tablicaKroki[3]
	\brief Tablica jednowymiarowa obiektow klasy String(sf::String).

	Zawarte sa w niej sciezki do dzwiekow chodu weza.
*/ 
/*! \var Sound Gracz::dzwiekTeleport
	\brief Obiekt klasy Sound przechowujacy dzwiek przemieszczania sie przez dziury.
*/
/*! \var Sound Gracz::dzwiekWalnieciePrzeszkody
	\brief Obiekt klasy Sound przechowujacy dzwiek uderzenia w przeszkode.
*/
/*! \var Sound Gracz::dzwiekWalniecieSiebie
	\brief Obiekt klasy Sound przechowujacy dzwiek uderzenia w samego siebie.
*/
/*! \var Sound Gracz::dzwiekKroki
	\brief Obiekt klasy Sound przechowujacy dzwiek krokow gracza.
*/
/*! \var SoundBuffer Gracz::buforTeleport
	\brief Obiekt klasy SoundBuffer przechowujacy bufor dzwieku przemieszczania sie przez dziury.
*/
/*! \var SoundBuffer Gracz::buforPrzeszkoda
	\brief Obiekt klasy SoundBuffer przechowujacy bufor dzwieku uderzenia w przeszkode.
*/
/*! \var SoundBuffer Gracz::buforWaz
	\brief Obiekt klasy SoundBuffer przechowujacy bufor dzwieku uderzenia w samego siebie.
*/
/*! \var SoundBuffer Gracz::buforKroki
	\brief Obiekt klasy SoundBuffer przechowujacy bufor dzwieku krokow gracza.
*/
/*! \var Animacja* Gracz::animacjaCiala
	\brief Wskaznik na obiekt klasy Animacja przechowujacy odpowiednie wywolania do animacji ciala weza.
*/
/*! \var int Gracz::kierunek
	\brief Zmienna typu int okreslajaca kierunek, w ktorym porusza sie gracz.
*/

/************************************************
 *	Pola klasy PUBLIC
 ***********************************************/
/*! \var Clock Gracz::zegar
	\brief Obiekt klasy Clock odpowiadajacy za spowolnienie ruchu weza.
*/
/*!	\var Clock Gracz::zegarDzwieki
	\brief Obiekt klasy Clock odpowiadajacy za czestotliwosc odtwarzania dzwieku krokow.
*/
/*! \var Clock Gracz::zegarSterowania
	\brief Obiekt klasy Clock odpowiadajacy za czestotliwosc zmiany kierunku weza.
*/
/*! \var float Gracz::czasomierz
	\brief Zmienna typu float przechowujaca krotki odcinek czasu, nastepnie jest zerowana.
*/
/*! \var Lista* Gracz::wsk_listy
	\brief Wskaznik na poczatek listy dwukierunkowej.
*/
/*! \var int Gracz::tekstura
	\brief Zmienna typu int odpowiadajaca za aktualny numer tekstury weza.
*/

/************************************************
 *	Metody klasy PUBLIC
 ***********************************************/
/*! \fn Gracz::Gracz(int poziom)
	\brief Konstruktor klasy Gracz.
	 - inicjalizuje wszystkie zmienne potrzebne do obslugi gracz\n
	 - laduje tekstury z plikow oraz przypisuje je do sprite'ow\n
	 - laduje dzwieki z plikow oraz przypisuje je do buforow\n
	 - tworzy liste dwukierunkowa\n

	 \param poziom
	 \brief Zmienna typu int okresla poziom gracza.
	 Dzieki niej konstruktor dopasowywuje odpowiednie ustawienia do poziomu rozgrywki.
*/
/*! \fn Gracz::~Gracz()
	\brief Dekonstruktor klasy Gracz usuwajacy zmienne dynamiczne oraz liste dwukierunkowa.
*/
/*! \fn void Gracz::dodajElement()
	\brief Metoda odpowiedzialna za obsluge listy dwukierunkowej; dodaje nowy element do listy.

	\param void
	\brief Metoda nie przyjmuje zadnych parametrow.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn void Gracz::rysuj(RenderWindow& okno)
	\brief Metoda rysujaca elementy gracza.

	\param &okno
	\brief Referencja na obiekt klasy RenderWindow wykorzystywana do rysowania gracza w glownym oknie.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn void Gracz::obsluguj(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	\brief Metoda zwiazana z ruchem gracza.

	Zawarte sa w niej prywatne metody zwiazane z ruchem oraz sterowaniem gracza.

	\param *dziuraSprite
	\brief Wskaznik na obiekt klasy Sprite. Jest tablica dynamiczna dwuelementowa. Przechowuje sprite'y dziur.
	
	\param liczbaDziur
	\brief Zmienna typu int okreslajaca ilosc dziur w tablicy.

	\param *przeszkodaSprite
	\brief Wskaznik na obiekt klasy Sprite. Jest tablica dynamiczna. Przechowuje sprite'y przeszkod.
	
	\param liczbaPrzeszkod
	\brief Zmienna typu int okreslajaca ilosc przeszkod w tablicy.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn bool Gracz::walnijPrzeszkode(Sprite* przeszkodaSprite, int liczbaPrzeszkod)
	\brief Metoda sprawdzajaca czy gracz znajduje sie na przeszkodzie.

	\param *przeszkodaSprite 
	\brief Wskaznik na obiekt klasy Sprite. Jest tablica dynamiczna. Przechowuje sprite'y przeszkod.

	\param liczbaPrzeszkod
	\brief Zmienna typu int okreslajaca ilosc przeszkod w tablicy.

	\return bool
	\brief Metoda zwraca wartosc bool.
*/
/*! \fn bool Gracz::samoUkaszenie()
	\brief Metoda sprawdzajaca czy gracz znajduje sie na swoim ciele.

	\param void
	\brief Metoda nie przyjmuje zadnych argumentow.

	\return bool
	\brief Metoda zwraca wartosc bool.
*/
/*! \fn void Gracz::zerujAnimacje()
	\brief Metoda odpowiedzialna za ustawienie animacji na start.
	
	\param void
	\brief Metoda nie przyjmuje zadnych argumentow.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn void Gracz::ochronaKolizji()
	\brief Metoda odpowiedzialna za dopasowanie tekstur podczas bonusu ochrony przed kolizja.

	\param void
	\brief Metoda nie przyjmuje zadnych argumentow.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn void Gracz::ustawNowaTeksture()
	\brief Ustawia nowa tekstura odpowiednio do uzyskanego wyniku.
	
	\param void
	\brief Metoda nie przyjmuje zadnych argumentow.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn void Gracz::ustawTeksture100()
	\brief Metoda, ktora ustawia teksture nieprzezroczysta po bonusie ochorony przed kolizja.
	
	\param void
	\brief Metoda nie przyjmuje zadnych argumentow.

	\return Metoda nie zwraca zadnej wartosci.
*/

/************************************************
 *	Metody klasy PRIVATE
 ***********************************************/
/*! \fn void Gracz::sterowanie()
	\brief Metoda odpowiedzialna za odczytywanie klawiszy strzalek w celu ustaleniu kierunku poruszania sie gracza.
	
	\param void
	\brief Metoda nie przyjmuje zadnych argumentow.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn void Gracz::przejdzPrzezDziure(Sprite* dziuraSprite, int liczbaDziur)
	\brief Metoda odpowiedzialna za przenoszenie weza przez tunel w inne miejsce planszy (druga dziura).

	\param *dziuraSprite
	\brief Wskaznik na obiekt klasy Sprite. Jest tablica dynamiczna dwuelementowa. Przechowuje sprite'y dziur.

	\param liczbaDziur
	\brief Zmienna typu int okreslajaca ilosc dziur w tablicy.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn void Gracz::ruchGracza(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod)
	\brief Metoda odpowiadajaca za poruszanie sie weza.
	 
	Kontroluje wszystkie ruchy weza np.:\n
	- przejscie przez sciane\n
	- przejscie przez dziure\n
	- wejscie w przeszkode

	\param *dziuraSprite
	\brief Wskaznik na obiekt klasy Sprite. Jest tablica dynamiczna dwuelementowa. Przechowuje sprite'y dziur.
	
	\param liczbaDziur
	\brief Zmienna typu int okreslajaca ilosc dziur w tablicy.

	\param *przeszkodaSprite
	\brief Wskaznik na obiekt klasy Sprite. Jest tablica dynamiczna. Przechowuje sprite'y przeszkod.

	\param liczbaPrzeszkod
	\brief Zmienna typu int okreslajaca ilosc przeszkod w tablicy.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn void Gracz::przejdzNaKoniecListy(Lista **wskaznik)
	\brief Metoda odpowiedzialna za obsluge listy dwukierunkowej; przechodzi na koniec listy.

	\param **wskaznik
	\brief Podwojny wskaznik na liste.

	\return Metoda nie zwraca zadnej wartosci.
*/
/*! \fn void Gracz::przejdzPrzezSciane()
	\brief Metoda odpowiedzialna za przejscie weza przez sciane.

	Np. waz przechodzi przez lewa sciane i wychodzi prawa.

	\param void
	\brief Metoda nie przyjmuje zadnych argumentow.

	\return Metoda nie zwraca zadnej wartosci.
*/

/************************************************
 *	Struktura Lista
 ***********************************************/
/*! \struct Lista
	\brief Struktura listy dynamicznej listy dwukierunkowej.
	Przechowuje ona:\n
	- kordynaty x, y dla elementow weza\n
	- sprite'y\n
	- wskazniki na element poprzedni i nastepny\n

	\fn Lista::Lista()
	\brief Konstruktor struktury Lista.

	\var float Lista::x
	\brief Zmienna typu float, ktora przechowuje kordynate x z okna glownego.
	Okresla polozenie w osi x elementu weza.

	\var float Lista::y
	\brief Zmienna typu float, ktora przechowuje kordynate y z okna glownego.
	Okresla polozenie w osi y elementu weza.

	\var Sprite Lista::sprite
	\brief Obiekt klasy Sprite przechowujacy aktualny sprite weza.

	\var Lista* Lista::nast
	\brief Wskaznik na nastepny element listy.

	\var Lista* Lista::poprz
	\brief Wskaznik na poprzedni element listy.
*/
#pragma once
#include "Biblioteki.h"

struct Lista
{
	float x, y;
	Sprite sprite;
	struct Lista* nast, * poprz;
	Lista()
	{
		x = START_X;
		y = START_Y;
		nast = poprz = NULL;
	}
};

class Animacja;

class Gracz
{
	int Poziom;
	float rozmiar_weza, opoznienie, mnoznikCzasu;
	bool ustawTeksture;
	Texture graczCialoTekstura, graczGlowaTekstura;
	Sprite* graczSprite;
	String tablicaStringCialoTekstura[3][8], tablicaKroki[3];
	Sound dzwiekTeleport, dzwiekWalnieciePrzeszkody,dzwiekWalniecieSiebie,dzwiekKroki;
	SoundBuffer buforTeleport, buforPrzeszkoda,buforWaz,buforKroki;
	Animacja* animacjaCiala;
	int kierunek;

public:
	Clock zegar,zegarDzwieki, zegarSterowania;
	float czasomierz;
	struct Lista* wsk_listy;
	int tekstura;

public:
	Gracz(int poziom);
	~Gracz();
	void dodajElement();
	void rysuj(RenderWindow& okno);
	void obsluguj(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	bool walnijPrzeszkode(Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	bool samoUkaszenie();
	void zerujAnimacje();
	void ochronaKolizji();
	void ustawNowaTeksture();
	void ustawTeksture100();

private:
	void sterowanie();
	void przejdzPrzezDziure(Sprite* dziuraSprite, int liczbaDziur);
	void ruchGracza(Sprite* dziuraSprite, int liczbaDziur, Sprite* przeszkodaSprite, int liczbaPrzeszkod);
	void przejdzNaKoniecListy(Lista **wskaznik);
	void przejdzPrzezSciane();
};

