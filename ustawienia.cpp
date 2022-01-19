#include "ustawieniaEkranu.cpp"
#include "funkcje.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
extern int ROZMIAR, SZYBKOSC,poziom;
void rysujUstawienia() {
	cout << lgrog;
	wypisz(gora, 30);
	cout << pgrog;
	cout << endl;
	for (int i = 0; i < 28; i++) {
		cout << bok;
		for (int j = 0; j < 30; j++) {
			if (j == 3 && i == 10) {
				cout << "Wybierz poziom trudności:";
				wypisz(" ", 2);
				break;
			}
			if (j == 10 && i == 12) {
				cout << "1. ŁATWY";
				wypisz(" ", 12);
				break;
			}
			if (j == 10 && i == 13) {
				cout << "2. ŚREDNI";
				wypisz(" ", 11);
				break;
			}
			if (j == 10 && i == 14) {
				cout << "3. TRUDNY";
				wypisz(" ", 11);
				break;
			}
			cout << " ";
		}
		cout << bok << endl;
	}
	cout << ldrog;
	wypisz(gora, 30);
	cout << pdrog << endl;
}
//ustawia gre
int wyborPoziomuTrudnosci() {
	char znak = 0;
	do {
		if (_kbhit()) {
			znak = _getch();
		}//is true when a key was pressed

		switch (znak) {
		case '1':
			SZYBKOSC = 500;
			ROZMIAR = 6;
			winSize(ROZMIAR);
			poziom = 0;
			return 1;
			break;
		case '2':
			SZYBKOSC = 250;
			ROZMIAR = 12;
			winSize(ROZMIAR);
			poziom = 1;
			return 1;
			break;
		case '3':
			SZYBKOSC = 150;
			ROZMIAR = 18;
			winSize(ROZMIAR);
			poziom = 2;
			return 1;
			break;
		default:
			break;
		}
	} while (znak != '1' && znak != '2' && znak !='3'); //ESC

	return 0;
}
int Ustawienia() {
	rysujUstawienia();
	int x = wyborPoziomuTrudnosci();
	return x;
	
}