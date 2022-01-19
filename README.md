# SnakeCMD
1. Opis projektu.
Projekt jest grą „SNAKE” w konsoli windows
2. Wymagania 
•	Menu z wyborem poziomu trudności i i tablicą wyników
•	Sterowanie wężem za pomocą klawiszy WSAD
•	Możliwość zbierania punktów na planszy powodujących powiększanie węża
•	Gdy wąż uderzy w swój ogon lub ścianę gra się kończy
•	Wygrywa się wtedy gdy nie będzie już wolnych pól na planszy
•	Zapisanie wyniku do pliku jeśli wynik ten jest najlepszy.

3. Przebieg realizacji
Grę napisałem za pomocą standardowych bibliotek C++
Zacząłem od implementacji algorytmu samej gry:

Wąż jest reprezentowany przez tablicę 2D:
- 0 w tablicy oznacza puste pole:
- -1 w tablicy oznacza „pokarm” dla węża powodujący jego wzrost
- Liczby większe od 0 pokazują węża w tym 1 oznacza głowę węża i od tego miejsca wyznacza się następne pola do poruszania

Algorytm(powtarzany co sekundę):

1. Oblicza zmienne x i y w nowym kierunku co każdą klatkę (jeśli kierunek jest prawidłowy, zwiększ x lub y o 1)
2. Jeśli x i y jest nie prawidłowy (wychodzi poza tablice lub w miejscu x,y jest już wąż gra zwraca wartość 1= przegranej
3. jeśli wartość snake w xy jest równa -1 dodaje do długości węża 1 i losuje nowe wolne pole na którym zapisuje -1
4. Przechodzi pętlą po wężu i dodaje 1 do pól na których jest wąż i jeśli wartość jest większa od długości nadpisuje ją jako 0

Potem zająłem się resztą gry: utworzeniem menu, ekranu wygranej, przegranej i metodą zapisywania wyniku.

4. Instrukcja użytkownika 
Menu wyboru obsługuje się poprzez naciśnięcie odpowiadającego klawisza na klawiaturze.

Poruszanie wężem odbywa się za pomocą klawiszy „WSAD”, gra polega na zbieraniu „jedzenia” i osiąganiu jak największej długości węża.
 
