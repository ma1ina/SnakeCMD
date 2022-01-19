#include <iostream>
#include"ustawieniaEkranu.cpp"
#include "funkcje.h"
#include <Windows.h>

extern int ROZMIAR,lbPunktow;
extern int** snake;
using namespace std;

void animacjaPrzegrana() {
	int licznik = 0;
	while (licznik < 10) {
		cout << lgrog;
		wypisz(gora, ROZMIAR);
		cout << pgrog;
		cout << endl;
		for (int i = 0; i < ROZMIAR; i++) {
			cout << bok;
			for (int j = 0; j < ROZMIAR; j++) {
				if (snake[i][j] == 0) {
					cout << " ";
				}
				if (snake[i][j] > 1 && licznik%2==0) {
					cout << "\033[;92m█\033[m";
				}
				else if (snake[i][j] > 1 && licznik % 2 == 1) {
					cout << " ";
				}
				if (snake[i][j] == 1 && licznik%2==0) {
					cout << "\033[;42m \033[m"; //znak esc kodu
				}
				else if(snake[i][j] == 1 && licznik % 2 == 1) {
					cout << " ";
				}
				if (snake[i][j] == -1) {
					cout << "֍";
				}
			}
			cout << bok << endl;
		}
		cout << ldrog;
		wypisz(gora, ROZMIAR);
		cout << pdrog << "\tLiczba punktów: " << lbPunktow << endl;
		licznik++;
		Sleep(500);
		system("cls");
	}
}
void przegrana() {
	animacjaPrzegrana();
	wpisDoTablicy();
}