#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
#include "funkcje.h"
#include "ustawieniaEkranu.cpp"
using namespace std;
void rysujNaWymiar(string linia, int pominZnaki=0) {
	int dlugoscLinii = (int)linia.size()-pominZnaki;
	cout << bok;
	for (int i = 0; i < 30 - dlugoscLinii; i++) {
		if (i == int(15 - dlugoscLinii / 2)) {
			cout << linia;
		}
		cout << " ";
	}
	cout << bok;
	cout << endl;

}
void wyswietlWyniki(string* linia) {
	cout << lgrog;
	wypisz(gora, 30);
	cout << pgrog;
	cout << endl;
	for (int j = 0; j < 16; j++) {
		if (j == 6) { rysujNaWymiar("NAJLEPSZE WYNIKI:"); }
		if (j == 8) {
			for (int i = 0; i < 9; i++) {
				if (i == 0) { rysujNaWymiar("\033[;92mLATWY:\033[m",9); }
				if (i == 3) { rysujNaWymiar("\033[;92mSREDNI:\033[m",9); }
				if (i == 6) { rysujNaWymiar("\033[;92mTRUDNY:\033[m",9); }
				rysujNaWymiar(linia[i]);
			}
		}
		else if (j == 10) {rysujNaWymiar("\033[;92mNACISNIJ 'ESC' ABY WYJSC:\033[m",9); }
		else{
			cout << bok;
			wypisz(" ", 30);
			cout << bok;
			cout << "\n";
		}
	}
	cout << ldrog;
	wypisz(gora, 30);
	cout << pdrog;
	cout << endl;
}
void tablicaWynikow() {
	string linia[9]{};
	otworzWyniki(linia);
	wyswietlWyniki(linia);
	char znak = 0;
	do {
		if (_kbhit()) {
			znak = _getch();
		}
	} while (znak != 27);
	cout << endl;
	system("cls");
}