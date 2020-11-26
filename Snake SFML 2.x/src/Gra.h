/*!	\file Gra.h
*	\brief Plik zawierajacy klase Gra 
*/

/*!	\class Gra : Punkty
*	\brief Klasa glowna Gry ze wszystkimi zmiennymi ,obiektami oraz metodami do glownego rdzenia gry
*/

/*!	\var Texture Gra::tloMapyTekstura
*	\brief Zmienna przechowujaca teskture tla mapy
*/
/*!	\var Texture Gra::planszaTekstura[3]
*	\brief Zmienna przechowujaca tablice tekstur planszy "szachownicy"
*/
/*!	\var Texture Gra::przeszkodaTekstura[3]
*	\brief Zmienna przechowujaca tablice tekstur przeszkod "kamieni"
*/
/*!	\var Texture Gra::dziuraTekstura
*	\brief Zmienna przechowujaca teksture dziury teleportacyjnej
*/
/*!	\var Texture Gra::pucharTekstura
*	\brief Zmienna przechowujaca teksture pucharu przy wyniku w gornej ramce
*/

/*!	\var String* Gra::tablicaTekstur
*	\brief Zmienna przechowujaca wskaznik na tablice sciezek do tekstur planszy
*/
/*!	\var String Gra::tablicaTeksturPrzeszkod[3]
*	\brief Zmienna przechowujaca tablice sciezek do tekstur przeszkod
*/
/*!	\var String Gra::tablicaMuzyka[3]
*	\brief Zmienna przechowujaca tablice sciezek do plikow muzycznych
*/
/*!	\var String Gra::tablicaTeskturPucharu[3]
*	\brief Zmienna przechowujaca tablice sciezek do tesktur pucharu
*/
/*!	\var String Gra::wynikString
*	\brief Zmienna przechowujaca wynik w formie tekstu
*/

/*!	\var Sprite Gra::tloMapySprite
*	\brief Zmienna przechowujaca Sprite tla mapy
*/
/*!	\var Sprite** Gra::planszaSprite
*	\brief Zmienna przechowujaca wskaznik na dwuwymiarowa tablice spriteow planszy
*/
/*!	\var Sprite** Gra::ramkaSprite
*	\brief Zmienna przechowujaca wskaznik na dwuwymiarowa tablice spriteow ramki planszy
*/
/*!	\var Sprite* Gra::przeszkodaSprite
*	\brief Zmienna przechowujaca wskaznik na tablice spriteow ramki planszy
*/
/*!	\var Sprite Gra::dziuraSprite[2]
*	\brief Zmienna przechowujaca tablice spriteow dziur teleportacyjnych
*/
/*!	\var Sprite Gra::pucharSprite
*	\brief Zmienna przechowujaca spritea pucharu
*/

/*!	\var unsigned int Gra::dlugoscPlanszy
*	\brief Zmienna przechowujaca dlugosc planszy
*/	
/*!	\var unsigned int Gra::wysokoscPlanszy
*	\brief Zmienna przechowujaca wysokosc planszy
*/	
/*!	\var unsigned int Gra::odstep
*	\brief Zmienna przechowujaca odstep kwadratow planszy
*/

/*!	\var int Gra::liczbaPrzeszkod
*	\brief Zmienna przechowujaca ilosc przeszkod na mapie
*/
/*!	\var int Gra::wyborPauza
*	\brief Zmienna przechowujaca numer wyboru w czasie pauzy
*/
/*!	\var int Gra::POZIOM
*	\brief Zmienna przechowujaca numer poziomu gry
*/
/*!	\var int Gra::WARUNEK
*	\brief Zmienna przechowujaca warunek konca poziomu
*/

/*!	\var int* Gra::tablicaX
*	\brief Zmienna przechowujaca wskaznik na tablice numerow miejsc w poziomie na planszy dla przeszkod
*/
/*!	\var int* Gra::tablicaY
*	\brief Zmienna przechowujaca wskaznik na tablice numerow miejsc w pionie na planszy dla przeszkod
*/
/*!	\var int* Gra::tablicaJ
*	\brief Zmienna przechowujaca wskaznik na tablice w ktorej znajduja sie numery tekstur dla przeszkod
*/

/*!	\var Text Gra::menuPauzy[2]
*	\brief Tablica przechowujaca obiekty typu Text do menu pauzy
*/
/*!	\var Text Gra::koniecGry[2]
*	\brief Tablica przechowujaca obiekty typu Text do menu konca gry
*/
/*!	\var Text Gra::wynikText
*	\brief Obiekt typu Text do wyswietlania wyniku obok pucharu
*/

/*! \var Music Gra::muzykaGra
*	\brief Obiekt typu Music pozwalajacy streamowac muzyke
*/

/*! \var SoundBuffer Gra::buforJedzenie
*	\brief Obiekt typu SoundBuffer dla dzwieku jedzenia
*/

/*! \var Sound Gra::dzwiekJedzenie
*	\brief Obiekt typu Sound pozwalajacy streamowac dzwiek jedzenia
*/

/*!	\fn Gra::Gra(int iloscprzeszkod,int poziom,int warunek)
*	\brief Konstruktor klasy Gra
*	\param iloscprzeszkod
*	\brief Zmienna przechowujaca liczbe przeszkod na planszy.
*	\param poziom
*	\brief Zmienna oznaczajaca ktory poziom jest grany.
*	\param warunek
*	\brief Zmienna przechowujaca warunek ukonczenia poziomu
*/

/*!	\fn Gra::~Gra()
*	\brief Dekonstruktor Klasy Gra;
*	Jego zadaniem jest usunac wszystkie dynamiczne tablice tekstur spriteow
*/

/*!	\var double Gra::procX
*	\brief Zmienna przechowujaca procentowy rozmiar w poziomie od wartosci 1920
*/
/*!	\var double Gra::procY
*	\brief Zmienna przechowujaca procentowy rozmiar w pionie od wartosci 1080
*/
/*!	\var float Gra::czasZloteJablko
*	\brief Zmienna przechowujaca czas trwania bonusow na danym poziomie
*/
/*!	\var thread Gra::RdzenPlansza
*	\brief Obiekt typu thread do pomocy przy obliczeniach na poczatku poziomu
*/

/*!	\fn void Gra::rysujPlansze(RenderWindow& okno)
*	\brief Metoda do rysowania planszy oraz ramki na ekranie
*	\param okno	
*	\brief okno to referencja na obiekt typu RenderWindow glownego okna aplikacji
*	\return void
*/

/*!	\fn int Gra::pauza(RenderWindow& okno, Gracz& gracz,Pokarm* pokarm)
*	\brief Metoda do pauzowania gry
*	\param okno
*	\brief okno to referencja na obiekt typu RenderWindow glownego okna aplikacji
*	\param gracz
*	\brief gracz to referencja na obiekt typu Gracz czyli weza
*	\param pokarm
*	\brief pokarm to wskaznik na obiekt typu Pokarm czyli ktores z jablek
*	\return int
*	\brief Zwraca 0 lub 1 w zaleznosci od wyboru uzytkownika
*/	

/*!	\fn int Gra::silnikPoziomu(RenderWindow& okno,int poziom)
*	\brief Glowna metoda klasy Gra w ktorej wykonuje sie wiekszosc innych metod oraz sa tworzone obiekty do gry
*	\param okno
*	\brief okno to referencja na obiekt typu RenderWindow glownego okna aplikacji
*	\param poziom
*	\brief Zmienna przechowujaca numer poziomu gry
*	\return int
*	\brief Metoda zwraca 1,2,3 lub 0.
*	Gdy zwraca 1, 2 lub 3 to aplikacja uruchomi odpowiedni poziom gry,
*	jesli zwroci 0 to aplikacja zakonczy dzialanie
*/

/*!	\fn void Gra::obliczPozycje()
*	\brief Metoda pomocnicza dla watku typu Thread aby odciazyc rdzen glowny aplikacji
*/

/*!	\fn bool Gra::przegrana(Gracz& gracz, Clock zegar)
*	\brief Metoda ta sprawdza czy gracz przegral w danym poziomie
*	\param gracz
*	\brief gracz to referencja na obiekt typu Gracz czyli weza
*	\param zegar 
*	\brief Zegar sprawdza dla tej metody czy uplynal czas ochrony gracza przed kolizja
*	\return bool	
*	\brief Metoda zwraca true lub false
*	Zwraca true gdy gracz nie przegral
*	a false gdy zjadl sam siebie lub wszedl w kamien
*/

/*!	\fn int Gra::gameOver(RenderWindow& okno, Gracz& gracz,Pokarm* pokarm)
*	\brief Metoda do dzialania gdy gracz przegra
*	\param okno
*	\brief okno to referencja na obiekt typu RenderWindow glownego okna aplikacji
*	\param gracz
*	\brief gracz to referencja na obiekt typu Gracz czyli weza
*	\param pokarm
*	\brief pokarm to wskaznik na obiekt typu Pokarm czyli ktores z jablek
*	\return int 
*	\brief Metoda zwraca 0 lub 1
*	Gdy zwroci 0 to poziom wlaczy sie od nowa
*	a gdy 1 to nastapi wywolanie metod konczacych gre
*/

/*!	\fn bool Gra::wygrana(int aktualnyStan)
*	\brief Metoda ta sprawdza czy gracz wygral w danym poziomie
*	\param aktualnyStan
*	\brief Ten parametr zawiera aktualny wynik zjedzonych jablek
*	\return bool
*	\brief Metoda zwraca true lub false
*	Zwroci true gdy gracz osiagnie odpowiedni wynik
*	a false gdy gracz nie osiagnie odpowiedniego wyniku lub jest rozgrywany poziom 3
*/

/*!	\fn void Gra::aktualizujStanGry(int aktualnyWynik)
*	\brief Metoda ta aktualizuje wynik zjedzonych jablek na ekranie
*	\param aktualnyWynik
*	\brief Ten parametr przechowuje aktualny wynik zjedzonych jablek gracza
*	\return void
*	\brief Nic nie zwraca
*/

/*!	\fn void Gra::pauzaPrzedGra(RenderWindow& okno, Gracz& gracz,Pokarm * pokarm)
*	\brief Metoda do ustawiania aktywnej pauzy przed gra dopoki gracz nie wcisnie enter
*	\param okno
*	\brief okno to referencja na obiekt typu RenderWindow glownego okna aplikacji
*	\param gracz
*	\brief gracz to referencja na obiekt typu Gracz czyli weza
*	\param pokarm
*	\brief pokarm to wskaznik na obiekt typu Pokarm czyli ktores z jablek
*	\return void
*	\brief Nic nie zwraca
*/
#pragma once
#include "Biblioteki.h"
class Pokarm;
class Gra : public Punkty 
{
protected:
	Texture tloMapyTekstura, planszaTekstura[3], przeszkodaTekstura[3],dziuraTekstura,pucharTekstura;
	String *tablicaTekstur, tablicaTeksturPrzeszkod[3],tablicaMuzyka[3],tablicaTeskturPucharu[3],wynikString;
	Sprite tloMapySprite, ** planszaSprite,**ramkaSprite ,* przeszkodaSprite, dziuraSprite[2],pucharSprite;
	unsigned int dlugoscPlanszy, wysokoscPlanszy, odstep;
	int liczbaPrzeszkod,wyborPauza,POZIOM,WARUNEK;
	int *tablicaX, *tablicaY, *tablicaJ;
	Text menuPauzy[2],koniecGry[2], wynikText;
	Music muzykaGra;
	SoundBuffer buforJedzenie;
	Sound dzwiekJedzenie;
public:
	Gra(int iloscprzeszkod,int poziom,int warunek);
	~Gra();
	double procX, procY;
	float czasZloteJablko;
public:
	thread RdzenPlansza;
protected:
	void rysujPlansze(RenderWindow& okno);
	int pauza(RenderWindow& okno, Gracz& gracz,Pokarm* pokarm);
	int silnikPoziomu(RenderWindow& okno,int poziom);
	void obliczPozycje();
	bool przegrana(Gracz& gracz, Clock zegar);
	int gameOver(RenderWindow& okno, Gracz& gracz,Pokarm* pokarm);
	bool wygrana(int aktualnyStan);
	void aktualizujStanGry(int aktualnyWynik);
	void pauzaPrzedGra(RenderWindow& okno, Gracz& gracz,Pokarm * pokarm);
};

