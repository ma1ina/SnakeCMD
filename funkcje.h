#pragma once
#include <string>
#ifndef funkcje_h
#define funkcje_h

int menu(); //wysietla menu startu i pobiera wybor
int Gra(); //zawiera logike gry i wyswietla ja na ekran zwraca 2 w przypadku wygranej i 1 w przypadku przegranej
int Ustawienia(); //wysietla menu wyboru trudnosci gry i pobiera wybor
void wypisz(std::string, int); //funkcja dodatkowa drukuje stringa n razy
void winSize(int ROZMIAR); //ustawia rozmiar ekranu
void tablicaWynikow(); //wyswietla tablice wynikow
void wpisDoTablicy(); //analizuje liczbe punktow i wpisuje ja do wynikow jesli lb punktow jest lepsza niz zapisana
void otworzWyniki(std::string* linia); //funkcja dodatkowa obsluguje otwieranie pliku z wynikami
void przegrana();//wyswietla animacje przegranej
void wygrana(); //wyswietla animacje wygranej
#endif