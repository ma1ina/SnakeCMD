#include <iostream>
#include"ustawieniaEkranu.cpp"
#include "funkcje.h"
#include "globalValues.h"
#include <Windows.h>

extern int ROZMIAR, lbPunktow;
extern int** snake;
using namespace std;

extern int snakeLength;
void animacjaWygrana() {
	while (snakeLength > 0) {
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
				if (snake[i][j] > 1) {
					cout << "\033[;92m█\033[m";
				}
				if (snake[i][j] == 1) {
					cout << "\033[;42m \033[m"; //znak esc kodu ascii
				}
				if (snake[i][j] == -1) {
					cout << "֍";
				}
				if (snake[i][j] == snakeLength) {
					snake[i][j] = 0;
				}
			}
			cout << bok << endl;
		}
		cout << ldrog;
		wypisz(gora, ROZMIAR);
		cout << pdrog << "\tLiczba punktów: " << lbPunktow << endl;
		Sleep(300-(poziom*100));
		system("cls");
		snakeLength--;
	}
}
void wygrana() {
	animacjaWygrana();
	wpisDoTablicy();
}