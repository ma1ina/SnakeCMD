// SnakeCMD.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <windows.h>
#include "globalValues.h"
#include "funkcje.h" 

using namespace std;
extern int ROZMIAR, SZYBKOSC;
int main()
{

    winSize(ROZMIAR);
    //Ustawia chcp konsoli na utf8
    SetConsoleOutputCP(CP_UTF8);
    int x = 0;
    bool Temp = true;
    int y = 0;
    while (Temp) {
        ROZMIAR = 30;
        SZYBKOSC = 250;
        lbPunktow = 0;
        snakeLength = 1;
        snake = nullptr;
        winSize(ROZMIAR);
        x = menu();
        switch (x) {
        case 1:
            Ustawienia();
            system("cls");
            y = Gra();
            if (y == 1) {
                przegrana();
            }
            if (y == 2) {
                wygrana();
            }
            break;
        case 2:
            system("cls");
            tablicaWynikow();
            break;
        case 27:
            Temp = false;
            break;
        }
    }
    return 0;
}
