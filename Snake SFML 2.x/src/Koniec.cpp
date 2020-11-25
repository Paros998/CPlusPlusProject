#include "Koniec.h"

string Koniec::wpiszNick(RenderWindow& okno,Font &czcionka,Sprite& tloMapySprite)
{
	string pseudonim = "";
	Text Pseudonim, TextKoncowy;
	Pseudonim.setCharacterSize(40);
	TextKoncowy.setCharacterSize(40);
	Pseudonim.setFont(czcionka);
	TextKoncowy.setFont(czcionka);
	Pseudonim.setFillColor(Color::Black);
	TextKoncowy.setFillColor(Color::Black);
	Pseudonim.setOutlineThickness(1.0f);
	TextKoncowy.setOutlineThickness(1.0f);
	Pseudonim.setOutlineColor(Color::Red);
	TextKoncowy.setOutlineColor(Color::Red);
	Pseudonim.setString(pseudonim);

	TextKoncowy.setString("Wpisz swoj nick i zatwierdz enterem, jesli jestes super graczem to wpiszemy cie do wynikow!");
	int znaki = 0;
	string linia = "Wpisz swoj nick i jesli jestes super graczem to wpiszemy cie do wynikow!";
	znaki = linia.length();
	TextKoncowy.setPosition(960.0f - (znaki / 2.0f * 20.0f), 350.0f);

	znaki = 0;
	linia = pseudonim;
	znaki = linia.length();
	Pseudonim.setPosition(960.0f - (znaki / 2.0f * 20.0f), 450.0f);
	Time czas = seconds(0.5f);
	sleep(czas);
	Clock czasOdOstatniejLitery;
	float opoznienie = 0.15f, aktualnyCzas = 0.0f;
	while (true)
	{
		okno.draw(tloMapySprite);
		okno.draw(TextKoncowy);
		okno.draw(Pseudonim);
		Event zdarzenie;
		while (okno.pollEvent(zdarzenie));
		{
			switch (zdarzenie.type)
			{
			case Event::Closed:
				continue;
			case Event::KeyPressed:
				if (zdarzenie.key.code == Keyboard::Escape)
					continue;
				break;
			case Event::TextEntered:
				aktualnyCzas = czasOdOstatniejLitery.getElapsedTime().asSeconds();
				if (aktualnyCzas >= opoznienie)
				{
					czasOdOstatniejLitery.restart();
					if ((zdarzenie.text.unicode >= 48 && zdarzenie.text.unicode <= 57) || (zdarzenie.text.unicode >= 65 && zdarzenie.text.unicode <= 90) || (zdarzenie.text.unicode >= 97 && zdarzenie.text.unicode <= 122))
					{
						pseudonim += static_cast <char>(zdarzenie.text.unicode);
						Pseudonim.setString(pseudonim);
					}
					if (zdarzenie.key.code == 8)
					{
						pseudonim = pseudonim.substr(0, pseudonim.length() - 1);
						Pseudonim.setString(pseudonim);
					}
					if (zdarzenie.key.code == 13)
					{
						return pseudonim;
					}
					break;
				}
			}
		}
		znaki = 0;
		linia = pseudonim;
		znaki = linia.length();
		Pseudonim.setPosition(960.0f - (znaki / 2.0f * 20.0f), 450.0f);
		okno.display();
	}
	return pseudonim;
}
void Koniec::wynikiTXT(string& pseudonimGracza)
{
	ListaWynikow* head = new ListaWynikow;
	head->next = NULL;
	int wynik, i = 0;
	int znaleziono = 0;
	string pseudonim;
	fstream wynikiPlik("data/wyniki.txt", ios::in);

	//Wczytywanie wyników z pliku do listy
	if (wynikiPlik)
	{
		while (i < 5 && wynikiPlik.eof() == false)
		{
			wynikiPlik >> pseudonim >> wynik;
			ListaWynikow* new_node = new ListaWynikow;
			new_node->pseudonim = pseudonim;
			new_node->wynikGracza = wynik;
			new_node->next = NULL;
			if (head->next == NULL)
			{
				wsk_wyniki = new_node;
				head->next = wsk_wyniki;
			}
			if (head->next != NULL)
			{
				wsk_wyniki->next = new_node;
				wsk_wyniki = wsk_wyniki->next;
			}
			i++;
		}
	}
	else cout << "Nie znaleziono pliku z wynikami!" << endl;
	wynikiPlik.close();
	fstream wynikiPlik2("data/wyniki.txt", ios::out);
	wsk_wyniki = head->next;

	cout << endl << "LISTA:" << endl;
	while (wsk_wyniki != NULL)
	{
		cout << wsk_wyniki->pseudonim << "  " << wsk_wyniki->wynikGracza << endl;
		wsk_wyniki = wsk_wyniki->next;
	}

	wsk_wyniki = head->next;
	//Jesli lista pusta to wstawi odrazu gracza z wynikiem do niej
	if (head->next == NULL)
	{
		ListaWynikow* new_node = new ListaWynikow;
		new_node->pseudonim = pseudonimGracza;
		new_node->wynikGracza = Wynik;
		new_node->next = NULL;

		head->next = new_node;
	}
	else
	{//Jesli nie to poszuka miejsca
		ListaWynikow* new_node = new ListaWynikow;
		new_node->pseudonim = pseudonimGracza;
		new_node->wynikGracza = Wynik;
		new_node->next = NULL;
		if (wsk_wyniki->wynikGracza <= Wynik)
		{
			new_node->next = wsk_wyniki;
			head->next = new_node;
		}
		else if (wsk_wyniki->wynikGracza > Wynik && wsk_wyniki->next == NULL) wsk_wyniki->next = new_node;
		else if (wsk_wyniki->wynikGracza > Wynik && wsk_wyniki->next != NULL)
			while (wsk_wyniki->next != NULL)
			{
				if (wsk_wyniki->next->wynikGracza > Wynik && wsk_wyniki->next->next != NULL)
				{
					wsk_wyniki = wsk_wyniki->next;
				}
				else if (wsk_wyniki->next->wynikGracza > Wynik && wsk_wyniki->next->next == NULL)
				{
					wsk_wyniki->next->next = new_node;
					break;
				}
				else if (wsk_wyniki->next->wynikGracza <= Wynik && wsk_wyniki->next->next != NULL)
				{
					new_node->next = wsk_wyniki->next;
					wsk_wyniki->next = new_node;
					break;
				}
				else if (wsk_wyniki->next->wynikGracza <= Wynik && wsk_wyniki->next->next == NULL)
				{
					wsk_wyniki->next = new_node;
					break;
				}
			}
	}
	wsk_wyniki = head->next;

	//Wstawianie z listy do pliku
	i = 0;
	if (wynikiPlik)
	{
		while (i < 5 && wsk_wyniki != NULL)
		{
			wynikiPlik2 << wsk_wyniki->pseudonim << "  " << wsk_wyniki->wynikGracza << endl;
			wsk_wyniki = wsk_wyniki->next;
			i++;
		}
	}
	wynikiPlik2.close();
}
