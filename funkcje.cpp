#include<string>
#include<iostream>
#include<fstream>
#include<string>
void wypisz(std::string co, int ileRazy) {
	for (int i = 0; i < ileRazy; i++) {
		std::cout << co;
	}
}
void winSize(int ROZMIAR) {
	std::string mode = "mode " + std::to_string(ROZMIAR + 30)+ "," + std::to_string(ROZMIAR + 3);
	const char* cstr = mode.c_str();
	system(cstr);

}
void otworzWyniki(std::string* linia) {
	int licznik = 0;
	std::fstream plik("wyniki.txt", std::ios::in);
	if (plik) {
		while (!plik.eof()) {
			std::getline(plik, linia[licznik]);
			licznik++;
		}
	}
	plik.close();
}