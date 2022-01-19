#include "ustawieniaEkranu.cpp"
#include "funkcje.h"
#include <iostream>
#include <conio.h>

using namespace std;


void rysujMenu() {
	cout << lgrog;
	wypisz(gora, 30);
	cout << pgrog;
	cout << endl;
	for (int i = 0; i < 28; i++) {
		cout << bok;
		for (int j = 0; j < 30; j++) {
			if (j == 12 && i == 10) {
				cout << "MENU";
				wypisz(" ", 14);
				break;
			}
			if (j == 10 && i == 12) {
				cout << "1. GRAJ";
				wypisz(" ", 13);
				break;
			}
			if (j == 6 && i == 13) {
				cout << "2. TABLICA WYNIKÓW";
				wypisz(" ", 6);
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
int menu() {
	rysujMenu();
	char znak = 0;
	do {
		if (_kbhit()) {  //is true when a key was pressed
			znak = _getch();
		}
		switch (znak) {
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case 27:
			return 27;
			break;
		default:
			znak = 0;;
		}
	} while (znak ==0);
	return 0;
}

