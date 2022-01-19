#include "globalValues.h"
int SZYBKOSC = 250; //Ustawia szybkosc drukowania planszy a tym samym ustawia szybkosc poruszania weza
int ROZMIAR = 30; //ustawia rozmiar planszy
int lbPunktow = 0; //liczba punktow
int** snake = nullptr; //waz
int poziom = 0; //0- latwy 1-sredni 2-trudny
int snakeLength = 1; //dlugosc weza