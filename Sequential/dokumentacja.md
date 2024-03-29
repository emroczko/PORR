# PORR - Projekt - częśc sekwencyjna i OpenMP

## Opis zadania

Zadanie polegało na zbudowaniu prostej sieci społecznaej: klucz - ID osoby, wartość – osoba. Następnie program miał umożliwi zwrócenie liczby przyjaciół każdej z osób w sieci w wersji sekwencyjnej oraz równoległej w technologii OpenMP.

## Opis algorytmu

Zadanie wykonano umyślnie algorytmem bardzo słabo wydajnym zarówno pamięciowo, jak i obliczeniowo. 

Siec społeczna została zaimplementowana jako graf nieskierowany. 

Na początku programu wczytywany jest plik z siecią społeczną, następnie po wczytaniu ilości wierzchołków tworzony jest obiekt grafu. Wewnątrz obiektu tworzona jest macierz sąsiedztwa o wymiarze A x A, gdzie A to ilośc wierzchołków. Macierz sąsiedztwa zainicjalizowana jest początkowo wartościami 0. Następnie iterując po następnych linijkach pliku stopniowo dodawane są wartości 1 w odpowiednich miejscach tabeli. Zatem jeśli w pliku mamy następującą definicję:
```
1 15
```
to znaczy to, że w macierzy w skrzyżowaniu wierszu 1 i 15 kolumny znajdzie się wartośc 1. Z racji celowej niskiej efektywności algorytmu, wartośc 1 pojawi się również w skrzyżowaniu wiersza 15 kolumny 1. 

Po uzupełnieniu macierzy sąsiedztwa program jest gotowy do znalezienia liczby przyjaciół każdej osoby (inaczej - wszystkich węzłów które mają połącznie z danym węzłem). 

Algorytm szukania przyjaciół polega na iteracji wzdłuż wierszy i kolumn w celu szukania wartości 1, czyli w celu szukania połączenia węzłów. Obie pętle mają zakres równy liczbie wierzchołków - jest to zatem zdecydowanie nieefektywne pamięciowo i obliczeniowo rozwiązanie, natomiast jednym z celów tego projektu było pokazanie jak radzi sobie z tym program w wersji sekwencyjnej, a jak program w wersji w technologii OpenMP. 

Dodanie technologii OpenMP polegało na zrównolegleniu pętli szukania przyjaciół. 

## Komentarz dot. wydajności algorytmu

Tak jak zostało wyżej wspomniane, algorytm wykonany jest w wersji nieefektywnej. Potencjalnym polepszeniem było m. in. zmniejszenie macierzy sąsiedztwa o połowę, tak, aby fakt połączenia między wierzchołkami wystąpił tylko raz - obecnie jest raz, symetrycznie. 

Innym rozwiązaniem jest skorzystanie z modelu grafu, jako obiektu "map" z biblioteki standardowej języka C++, gdzie kluczem byłby numer osoby, a wartością byłby wektor przyjaciół. 

Jednak najlepszy efekt różnicy między wersją sekwencyjną, a OpenMP dało wykonanie algorytmu w mniej efektywny sposób.

## Opis techniczny

Zadanie wykonano w języku C++, w wersji conajmniej C++14. W projekcie używana jest technologia OpenMP. 

Projekt budowany jest za pomocą narzędzia CMake. 

Wspierane platformy to Windows oraz macOS. 

Aby uruchomic program, należy przejśc do katalogu z plikami programu, następnie wykonac komendę:
```
cmake .
```

Następnie
```
make
```

Plik wykonywalny jest dostępny pod nazwą PORR. 

Aplikacja po uruchomieniu wykonuje X iteracji, gdzie X to maksymalna ilośc wątków która zdefiniowana jest w programie. W każdej iteracji zwiększa się ilośc wątków, na których pracuje metoda wykorzystująca OpenMP, zaczynając od 1 wątku, aż do X wątków. 

W celu uśrednienia wyników OpenMP, dla każdej liczby wątków (dla każdej iteracji), wykonywane jest kilka uruchomień metody wykorzystującej OpenMP, następnie wyliczana jest średnia z tych prób.  

## Wybrane zbiory danych do testowania 

- rozmiary, jakie pliki 
  
## Wyniki testów

- screeny z terminala 


Graph from brightkite.txt created
Sequential : parallel (1 threads) processing: 7.272695 : 7.261419 seconds
Sequential : parallel (2 threads) processing: 7.657955 : 3.674267 seconds
Sequential : parallel (3 threads) processing: 7.391224 : 2.495635 seconds
Sequential : parallel (4 threads) processing: 7.308102 : 1.898305 seconds
Sequential : parallel (5 threads) processing: 7.395851 : 1.949229 seconds
Sequential : parallel (6 threads) processing: 7.329522 : 1.831887 seconds
Sequential : parallel (7 threads) processing: 7.209378 : 1.639940 seconds
Sequential : parallel (8 threads) processing: 7.201938 : 1.517516 seconds
Sequential : parallel (9 threads) processing: 7.310027 : 1.564583 seconds
Sequential : parallel (10 threads) processing: 7.311517 : 1.548408 seconds
Sequential : parallel (11 threads) processing: 7.204523 : 1.538109 seconds
Sequential : parallel (12 threads) processing: 7.261726 : 1.521996 seconds
Sequential : parallel (13 threads) processing: 7.358666 : 1.529637 seconds
Sequential : parallel (14 threads) processing: 7.329594 : 1.519246 seconds
Sequential : parallel (15 threads) processing: 7.226848 : 1.519507 seconds
Sequential : parallel (16 threads) processing: 7.360881 : 1.515217 seconds
Sequential : parallel (17 threads) processing: 7.340094 : 1.508764 seconds
Sequential : parallel (18 threads) processing: 7.338121 : 1.529946 seconds
Sequential : parallel (19 threads) processing: 7.330441 : 1.521444 seconds
Sequential : parallel (20 threads) processing: 7.386670 : 1.511014 seconds
Graph from epinions.txt created
Sequential : parallel (1 threads) processing: 1.634551 : 1.572193 seconds
Sequential : parallel (2 threads) processing: 1.630362 : 0.851774 seconds
Sequential : parallel (3 threads) processing: 1.632409 : 0.546061 seconds
Sequential : parallel (4 threads) processing: 1.628490 : 0.431503 seconds
Sequential : parallel (5 threads) processing: 1.613139 : 0.445833 seconds
Sequential : parallel (6 threads) processing: 1.649122 : 0.391858 seconds
Sequential : parallel (7 threads) processing: 1.617535 : 0.366014 seconds
Sequential : parallel (8 threads) processing: 1.613619 : 0.335597 seconds
Sequential : parallel (9 threads) processing: 1.609780 : 0.361808 seconds
Sequential : parallel (10 threads) processing: 1.613295 : 0.350453 seconds
Sequential : parallel (11 threads) processing: 1.616510 : 0.344258 seconds
Sequential : parallel (12 threads) processing: 1.616022 : 0.343435 seconds
Sequential : parallel (13 threads) processing: 1.610437 : 0.339843 seconds
Sequential : parallel (14 threads) processing: 1.611172 : 0.343956 seconds
Sequential : parallel (15 threads) processing: 1.607618 : 0.340837 seconds
Sequential : parallel (16 threads) processing: 1.616278 : 0.342746 seconds
Sequential : parallel (17 threads) processing: 1.613513 : 0.339682 seconds
Sequential : parallel (18 threads) processing: 1.616090 : 0.338624 seconds
Sequential : parallel (19 threads) processing: 1.612287 : 0.339361 seconds
Sequential : parallel (20 threads) processing: 1.614702 : 0.335401 seconds
Graph from gplus.txt created
Sequential : parallel (1 threads) processing: 3.519302 : 3.418041 seconds
Sequential : parallel (2 threads) processing: 3.484430 : 1.742770 seconds
Sequential : parallel (3 threads) processing: 3.496732 : 1.185856 seconds
Sequential : parallel (4 threads) processing: 3.476252 : 0.920324 seconds
Sequential : parallel (5 threads) processing: 3.508131 : 0.960810 seconds
Sequential : parallel (6 threads) processing: 3.506912 : 0.863679 seconds
Sequential : parallel (7 threads) processing: 3.441866 : 0.789904 seconds
Sequential : parallel (8 threads) processing: 3.545531 : 0.724816 seconds
Sequential : parallel (9 threads) processing: 3.512662 : 0.753753 seconds
Sequential : parallel (10 threads) processing: 3.517510 : 0.742792 seconds
Sequential : parallel (11 threads) processing: 3.509618 : 0.742069 seconds
Sequential : parallel (12 threads) processing: 3.709940 : 0.736082 seconds
Sequential : parallel (13 threads) processing: 3.508767 : 0.726618 seconds
Sequential : parallel (14 threads) processing: 3.512315 : 0.732999 seconds
Sequential : parallel (15 threads) processing: 3.446164 : 0.730343 seconds
Sequential : parallel (16 threads) processing: 3.510076 : 0.729927 seconds
Sequential : parallel (17 threads) processing: 3.511995 : 0.728040 seconds
Sequential : parallel (18 threads) processing: 3.519717 : 0.727709 seconds
Sequential : parallel (19 threads) processing: 3.503685 : 0.727050 seconds
Sequential : parallel (20 threads) processing: 3.515461 : 0.731463 seconds
Graph from wiki-vote.txt created
Sequential : parallel (1 threads) processing: 0.002180 : 0.001878 seconds
Sequential : parallel (2 threads) processing: 0.001888 : 0.001037 seconds
Sequential : parallel (3 threads) processing: 0.001929 : 0.000823 seconds
Sequential : parallel (4 threads) processing: 0.002271 : 0.000726 seconds
Sequential : parallel (6 threads) processing: 0.002256 : 0.000672 seconds
Sequential : parallel (7 threads) processing: 0.002503 : 0.000617 seconds
Sequential : parallel (8 threads) processing: 0.001913 : 0.000578 seconds
Sequential : parallel (9 threads) processing: 0.002661 : 0.000725 seconds
Sequential : parallel (10 threads) processing: 0.001961 : 0.000669 seconds
Sequential : parallel (11 threads) processing: 0.002739 : 0.000683 seconds
Sequential : parallel (12 threads) processing: 0.001922 : 0.000630 seconds
Sequential : parallel (13 threads) processing: 0.002445 : 0.000621 seconds
Sequential : parallel (14 threads) processing: 0.001960 : 0.000537 seconds
Sequential : parallel (15 threads) processing: 0.002552 : 0.000707 seconds
Sequential : parallel (16 threads) processing: 0.001919 : 0.000547 seconds
Sequential : parallel (17 threads) processing: 0.002669 : 0.000683 seconds
Sequential : parallel (18 threads) processing: 0.002095 : 0.000601 seconds
Sequential : parallel (19 threads) processing: 0.002359 : 0.000655 seconds
Sequential : parallel (20 threads) processing: 0.001979 : 0.000620 seconds
Graph from karate.txt created
Sequential : parallel (1 threads) processing: 0.000009 : 0.000031 seconds
Sequential : parallel (2 threads) processing: 0.000006 : 0.000100 seconds
Sequential : parallel (3 threads) processing: 0.000005 : 0.000083 seconds
Sequential : parallel (4 threads) processing: 0.000006 : 0.000110 seconds
Sequential : parallel (5 threads) processing: 0.000006 : 0.000087 seconds
Sequential : parallel (6 threads) processing: 0.000005 : 0.000099 seconds
Sequential : parallel (7 threads) processing: 0.000013 : 0.000181 seconds
Sequential : parallel (8 threads) processing: 0.000006 : 0.000111 seconds
Sequential : parallel (9 threads) processing: 0.000006 : 0.000098 seconds
Sequential : parallel (10 threads) processing: 0.000006 : 0.000121 seconds
Sequential : parallel (11 threads) processing: 0.000011 : 0.000160 seconds
Sequential : parallel (12 threads) processing: 0.000012 : 0.000187 seconds
Sequential : parallel (13 threads) processing: 0.000006 : 0.000112 seconds
Sequential : parallel (14 threads) processing: 0.000006 : 0.000110 seconds
Sequential : parallel (15 threads) processing: 0.000009 : 0.000174 seconds
Sequential : parallel (16 threads) processing: 0.000008 : 0.000185 seconds
Sequential : parallel (17 threads) processing: 0.000006 : 0.000128 seconds
Sequential : parallel (18 threads) processing: 0.000009 : 0.000243 seconds
Sequential : parallel (19 threads) processing: 0.000010 : 0.000196 seconds
Sequential : parallel (20 threads) processing: 0.000008 : 0.000198 seconds