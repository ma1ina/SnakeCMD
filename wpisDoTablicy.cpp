#include<iostream>
#include <fstream>
#include "funkcje.h"
#include <string>
using namespace std;

extern int poziom, lbPunktow;
//rozdziela linie wyniku
string rozdziel(string s) {
    string delimiter = " ";
    size_t pos = 0;
    pos = s.find(delimiter);
    s = s.substr(pos + 1, s.length());

    return s;
}
void zapiszWyniki(string* wyniki) {
    fstream plik("wyniki.txt", ios::out);
    for (int i = 0; i < 9; i++) {
        plik << wyniki[i];
        if (i < 8) {
            plik<<"\n";
        }
    }
}
void wpisDoTablicy() {
    int pozycja = -1;
    string tablicaWynikow[9]{};
    int wlasciweWyniki[3]{};

    otworzWyniki(tablicaWynikow);

    for (int i = 0; i < 9; i++) {
        if ((i > ((poziom * 3) - 1) && i < ((poziom + 1) * 3))) {
            wlasciweWyniki[i % 3] = stoi(rozdziel(tablicaWynikow[i]));
        }
    }
    for (int i = 0; i < 3; i++) {
        if (wlasciweWyniki[i] < lbPunktow) {
            pozycja = i;
            string name = "";
            bool zleImie = true;
            cout << "Podaj imie: " << endl;
            while (zleImie) {
                cin >> name;
                cout << endl;
                for(int i=0;i<name.length();i++){
                    //sprawdza poprawnosc wpisanej nazwy
                    if ((int)(name[i]) < 65 || ((int)(name[i]) > 90 && (int)(name[i]) < 97) || (int)(name[i]) > 122)
                    {
                        zleImie = true;
                        cout << "Podaj dobre imie: ";
                        break;
                    }
                    else {
                        zleImie = false;
                    }
                }
            }
            string temp[9];
            copy(tablicaWynikow, tablicaWynikow + 9, temp);
            //przemieszcza pozycje w tablicy
            if (i == 0) {
                tablicaWynikow[poziom * 3 + pozycja + 1] = temp[poziom * 3 + pozycja];
                tablicaWynikow[poziom * 3 + pozycja + 2] = temp[poziom * 3 + pozycja + 1];
            }
            if (i == 1) {
                tablicaWynikow[poziom * 3 + pozycja + 1] = temp[poziom * 3 + pozycja];
            }
            tablicaWynikow[poziom * 3 + pozycja] = name + " " + to_string(lbPunktow);
            zapiszWyniki(tablicaWynikow);
            break;
        }
    }
}
