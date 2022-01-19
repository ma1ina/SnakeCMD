#include "funkcje.h"
#include "ustawieniaEkranu.cpp"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include<ctime>
#include<random>

using namespace std;

extern int ROZMIAR, SZYBKOSC, lbPunktow,snakeLength;
extern int** snake;

//Jesli true pozwala na przenikiwanie wężą i zawracanie w miejscu
bool DEBUG = false;


mt19937 generator((unsigned int)time(nullptr));

//sprawdza czy znak chcemy pokierowac weza w przeciwna strone do ruchu jesli tak to blokuje taki ruch
bool czyZnakPrzeciwny(char l1, char l2,int snakeLength) {
	if (snakeLength == 1 || DEBUG==true) { return false; }
	switch (l1) {
		case 'w':
			if (l2 == 's') { return true;}
			break;
		case 's':
			if (l2 == 'w') { return true; }
			break;
		case 'a':
			if (l2 == 'd') { return true; }
			break;
		case 'd':
			if (l2 == 'a') { return true; }
			break;
	}
	return false;
}
//powieksza weza
void zjedz(int * dlugosc,int **snake) {
	*dlugosc = *dlugosc + 1;
	lbPunktow++;
	uniform_int_distribution<int>distribution(0, ROZMIAR - 1);
	bool zlePole = true;
	while (zlePole) {
		int x = distribution(generator);
		int y = distribution(generator);	
		if (snake[x][y] == 0 || *dlugosc==ROZMIAR*ROZMIAR) {
			snake[x][y] = -1;
			zlePole = false;
		}
	}

}
//wyswietla gre
void RysujPlansze(int** snake) {
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
			if (snake[i][j] >1) {
				cout<<"\033[;92m█\033[m";
			}
			if (snake[i][j] == 1) {
				cout << "\033[;42m \033[m"; //znak esc kodu ascii
			}
			if (snake[i][j] == -1) {
				cout << "֍";
			}
		}
		cout << bok << endl;
	}
	cout <<ldrog;
	wypisz(gora, ROZMIAR);
	cout << pdrog <<"\tLiczba punktów: "<<lbPunktow<< endl;
}
//funkcja zajmuje sie ruchem weza 
int snakeMove(int** snake, int* dlugosc, char znak){
	switch (znak) {
		case 'w':
			for (int i = 0; i < ROZMIAR; i++) {
				for (int j = 0; j < ROZMIAR; j++) {
					if (snake[i][j] == 1) {
						//sprawdza czy wąż uderza w ściane
						if (i - 1 >= 0) {
							if (snake[i - 1][j] == -1) {
								zjedz(dlugosc,snake);
							}
							if (snake[i - 1][j] > 0 && DEBUG == false) { return 1; } //Jesli ugryzie siebie
							snake[i - 1][j] = 1;
						}
						else {
						return 1;
						}
					}
					if (0 < snake[i][j]) {
						snake[i][j]++;
					}
					if (snake[i][j] > *dlugosc) {
						snake[i][j] = 0;
					}
				}
			}
			break;
		case 's':
			for (int i = ROZMIAR - 1; i > -1; i--) {
				for (int j = 0; j < ROZMIAR; j++) {
					if (snake[i][j] == 1) {
						//sprawdza czy wąż uderza w ściane
						if (i + 1 < ROZMIAR) {
							if (snake[i + 1][j] == -1) {
								zjedz(dlugosc, snake);
							}
							if (snake[i + 1][j] > 0 && DEBUG == false) { return 1; } //Jesli ugryzie siebie
							snake[i + 1][j] = 1;
						}
						else {
							return 1;
						}
					}
					if (0 < snake[i][j]) {
						snake[i][j]++;
					}
					if (snake[i][j] > *dlugosc) {
						snake[i][j] = 0;
					}
				}
			}
			break;
		case 'a':
			for (int i = 0; i < ROZMIAR; i++) {
				for (int j = 0; j < ROZMIAR; j++) {
					if (snake[i][j] == 1) {
						if (j - 1 >= 0) {
							//sprawdza czy wąż uderza w ściane
							if (snake[i][j - 1] == -1) {
								zjedz(dlugosc, snake);
							}
							if (snake[i][j - 1] > 0 && DEBUG == false) { return 1; } //Jesli ugryzie siebie
							snake[i][j - 1] = 1;
						}
						else {
							return 1;
						}
					}
					if (0 < snake[i][j]) {
						snake[i][j]++;
					}
					if (snake[i][j] > *dlugosc) {
						snake[i][j] = 0;
					}
				}
			}
			break;
		case 'd':
			for (int i = 0; i < ROZMIAR; i++) {
				for (int j = ROZMIAR - 1; j > -1; j--) {
					if (snake[i][j] == 1) {
						//sprawdza czy wąż uderza w ściane
						if (j + 1 < ROZMIAR) {
							if (snake[i][j + 1] == -1) {
								zjedz(dlugosc, snake);
							}
							if (snake[i][j + 1] > 0 && DEBUG == false) { return 1; } //Jesli ugryzie siebie
							snake[i][j + 1] = 1;
						}
						else {
							return 1;
						}
					}
					if (0 < snake[i][j]) {
						snake[i][j]++;
					}
					if (snake[i][j] > *dlugosc) {
						snake[i][j] = 0;
					}
				}
			}
			break;
	}
	return 0;
}
int Gra() {
	char znak = 0;
	
	bool przyspieszenie = false;

	char znakTemp = 's';

	snake = new int* [ROZMIAR];
	for (int i = 0; i < ROZMIAR; ++i) {
		snake[i] = new int[ROZMIAR]();
	}
	//usawia środkową pozycje węża
	snake[ROZMIAR / 2][ROZMIAR / 2] = 1;
	//ustawia pierwsze "jedzenie"
	snake[(ROZMIAR / 2) - 1][ROZMIAR / 2] = -1;
	do {
		if (snakeLength == ROZMIAR * ROZMIAR) {
			return 2;
		}
		if (_kbhit()) {
			char x = _getch();
			if(!czyZnakPrzeciwny(x,znak,snakeLength)){
				if (x == znak) {
					przyspieszenie = true;
				}
				else {
					znak = x;
				}
			}
			
		}
		switch (znak) {
		case 'w':
			if (snakeMove(snake, &snakeLength, 'w') != 1) {
				znakTemp = 'w';
				break;
			}
			else {
				return 1;
			}
		case 's':
			if (snakeMove(snake, &snakeLength, 's') != 1) {
				znakTemp = 's';
				break;
			}
			else {
				return 1;
			}
		case 'a':
			if (snakeMove(snake, &snakeLength, 'a') != 1) {
				znakTemp = 'a';
				break;
			}

			else {
				return 1;
			}
		case 'd':
			if (snakeMove(snake, &snakeLength, 'd') != 1) {
				znakTemp = 'd';
				break;
			}
			else {
				return 1;
			}
		default:
			if (snakeMove(snake, &snakeLength, znakTemp) != 1) {
				break;
			}
			else {
				return 1;
			}

		}
		RysujPlansze(snake);
		if (przyspieszenie) {
			Sleep(SZYBKOSC/2);
		}
		else {
			Sleep(SZYBKOSC);
		}
		przyspieszenie = false;

		system("cls");
	} while (znak != 27);
	return 0;
}
