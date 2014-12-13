# Programowanie dynamiczne

## Konwencja stylu

Przy programowaniu dynamicznym korzystamy z tablic prostokrątnych. Prowadzi to do pewnego problemu, czy `A[1, 2]` oznacza element w pierwszym rzędzie i drugiej kolumnie czy w drugim rzędzie i pierwszej kolumnie? Nie ma to żadnego znaczenia, ważna jest konsekwencja i poprawność samego algorytmu. Ja, dla ułatwienia życia zawsze zapisuję indeks rzędu na pierwszym miejscu, a kolumny na drugim.

W tym momencie powinniście sobie zdawać sprawę z tego, że istnieją dwa style programowania dynamicznego. Pierwszy z nich polega na zwykłym przekształceniu funkcji rekurencyjnej tak by korzystała z elementów tablicy zamiast wywołań rekurencyjnych. Drugi styl to metoda iteracyjna, w której najpierw wypełniamy tablicę zgodnie z formułami nierekurencyjnymi a dopiero wtedy iterujemy po pozostałych elementach korzystając ze zmodyfikowanej formuły rekursywnej. Przy drugiej metodzie łatwiej jest rozpisać ilość operacji w każdym kroku, co często jest składnikiem naszego zadania, więc pozwolę sobie korzystać z tej metody.

Wszystkie zadania rozpisuję na tablicy `9 x 9` ale to jest tylko tablica podglądowa, mam nadzieję, że jesteście tego świadomi.

## Zadania

### 1.

> Stosując metodę **programowania dynamicznego**, napisz pseudokod algorytmu znajdującego dla danych liczb naturalnych `n`, `k` wartość funkcji `f(n, k)` określonej wzorami:
```
f(n, k) = 2k                                        dla n = 1
f(n, k) = n                                         dla k = 1 i n > 1
f(n, k) = 2f(n-1, k) + (f(n, k-1) / 2)              dla n, k > 1
```
Jaka jest złożoność tego algorytmu? Odpowiedź uzasadnij.

##### Etap pierwszy (wykonanie formuł nierekurencyjnych)

Znajdujemy formuły nierekurencyjne i wykonujemy je zgodnie z ich założeniami:

```
f(n, k) = 2k                                        dla n = 1
f(n, k) = n                                         dla k = 1 i n > 1
```

Zacznijmy od formuły pierwszej. Założenie (`n = 1`) oznacza, że dla wszystkich komórek w pierwszym rzędzie wartość funkcji będzie wynosić dwa razy indeks kolumny (`k`). Wypełnijmy naszą tabelę:

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
| **1** | 2 | 4 | 6 | 8 |10 |12 |14 |16 |18 |
| **2** |   |   |   |   |   |   |   |   |   |
| **3** |   |   |   |   |   |   |   |   |   |
| **4** |   |   |   |   |   |   |   |   |   |
| **5** |   |   |   |   |   |   |   |   |   |
| **6** |   |   |   |   |   |   |   |   |   |
| **7** |   |   |   |   |   |   |   |   |   |
| **8** |   |   |   |   |   |   |   |   |   |
| **9** |   |   |   |   |   |   |   |   |   | |

Założenie drugiej formuły `k = 1` oznacza pierwszą kolumnę, a `n > 1` oznacza rzędy od 2 do końca. Wartość funkcji w tych komórkach ma być równa `n`, indeksowi rzędu:

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
| **1** | 2 | 4 | 6 | 8 |10 |12 |14 |16 |18 |
| **2** | 2 |   |   |   |   |   |   |   |   |
| **3** | 3 |   |   |   |   |   |   |   |   |
| **4** | 4 |   |   |   |   |   |   |   |   |
| **5** | 5 |   |   |   |   |   |   |   |   |
| **6** | 6 |   |   |   |   |   |   |   |   |
| **7** | 7 |   |   |   |   |   |   |   |   |
| **8** | 8 |   |   |   |   |   |   |   |   |
| **9** | 9 |   |   |   |   |   |   |   |   | |

##### Etap drugi (analiza wywołania rekurencyjnego)

Jest to bardzo ważny etap tworzenia algorytmu dynamicznego. Tak jak pisałem wcześniej, teraz musimy przejść przez wszystkie pozostałe elementy i wyznaczyć wartość każdej komórki za pomocą zmodyfikowanej formuły rekurencyjnej.

Na czym polega sama modyfikacja? Na skorzystaniu z wartości przechowywanych w komórkach zamiast wywołań rekurencyjnych. Zmodyfikowana formuła (gdzie `A` to nasza tablica):

```
A[n, k] = 2 * A[n-1, k] + (A[n, k-1] / 2)              dla n, k > 1
```

Spójrzmy teraz na odwołania do naszej tablicy i zastanówmy się co one oznaczają w relacji do elementu `A[n, k]` pamiętając, że pierwsza wartość oznacza indeks rzędu, a druga kolumny:
* `A[n-1, k]` - wartość przechowywana w komórce **nad** naszym elementem
* `A[n, k-1]` - wartość przechowywana w komórce sąsiedniej naszego elementu, **po lewej** stronie.

Naszą iterację musimy zacząć od takiego elementu, dla którego oba odwołania do naszej tablicy zwrócą wartość. Inaczej mówiąc, musimy spojrzeć na naszą tablicę i znaleźć taki element, dla którego komórka nad nim i komórka po jego lewej stronie ma wpisaną wartość. Taki element jest tylko jeden, oznaczę go `x`:

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
| **1** | 2 | 4 | 6 | 8 |10 |12 |14 |16 |18 |
| **2** | 2 | x |   |   |   |   |   |   |   |
| **3** | 3 |   |   |   |   |   |   |   |   |
| **4** | 4 |   |   |   |   |   |   |   |   |
| **5** | 5 |   |   |   |   |   |   |   |   |
| **6** | 6 |   |   |   |   |   |   |   |   |
| **7** | 7 |   |   |   |   |   |   |   |   |
| **8** | 8 |   |   |   |   |   |   |   |   |
| **9** | 9 |   |   |   |   |   |   |   |   | |

Jeżeli wypełnimy tę komórkę wartością to następnie będziemy mogli wypełnić kolejną komórkę w tym rzędzie (`A[2, 3]`) i tak do ostatniej kolumny. Następnie przejdziemy do koljnego rzędu i posłużymy się tą samą metodą.

##### Etap trzeci (pseudokod)

```
F(n, k)
// pierwsza formula nierekurencyjna
for i = 1 to k do                                       | k
    A[1, i] = 2 * i                                     | 1
// druga formula nierekurencyjna
for i = 2 to n do                                       | n - 1
    A[i, 1] = i                                         | 1
// iteracja po pozostalych elementach zgodnie z metoda wyznaczona w 2 etapie
for i = 2 to n do                                       | n - 1
    for j = 2 to k do                                   | k - 1
        A[i, j] = 2 * A[i-1, j] + (A[i, j-1] / 2)       | 1
// zwracamy element, ktory mielismy obliczyc
return A[n, k]                                          | 1
```

```
T(n, k) = k * 1 + (n - 1) * 1 + (n - 1) * (k - 1) * 1 + 1 = k + n - 1 + nk - n - k + 1 + 1 = nk + 1 = O(n*k)
```

### 2.

> Stosując metodę **programowania dynamicznego**, napisz pseudokod algorytmu znajdującego dla danych liczb naturalnych `n`, `k` wartość funkcji `f(n, k)` określonej wzorami:
```
f(n, k) = k                                         dla n = 1
f(n, k) = 2n                                        dla k = 1 i n > 1
f(n, k) = 3f(n-1, k) + (f(n, k-1) mod 2)            dla n, k > 1
```
Jaka jest złożoność tego algorytmu? Odpowiedź uzasadnij.

Jest to zadanie bardzo podobne do zadania poprzedniego. Ponownie mamy dwie formuły nierekurencyjne, tablica po ich wykonaniu powinna wyglądać tak:

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
| **1** | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| **2** | 4 |   |   |   |   |   |   |   |   |
| **3** | 6 |   |   |   |   |   |   |   |   |
| **4** | 8 |   |   |   |   |   |   |   |   |
| **5** |10 |   |   |   |   |   |   |   |   |
| **6** |12 |   |   |   |   |   |   |   |   |
| **7** |14 |   |   |   |   |   |   |   |   |
| **8** |16 |   |   |   |   |   |   |   |   |
| **9** |18 |   |   |   |   |   |   |   |   | |

W zmodyfikowanej formule rekurencyjnej występują dwa odwołania do tablicy:
* `A[n-1, k]` - wartość przechowywana w komórce **nad** naszym elementem
* `A[n, k-1]` - wartość przechowywana w komórce sąsiedniej naszego elementu, **po lewej** stronie

Do tych samych elementów odwoływała się formuła w poprzednim zadaniu, więc metoda iteracji pozostaje bez zmian.

```
F(n, k)
for i = 1 to k do                                       | k
    A[1, i] = i                                         | 1
for i = 2 to n do                                       | n - 1
    A[i, 1] = 2 * i                                     | 1
for i = 2 to n do                                       | n - 1
    for j = 2 to k do                                   | k - 1
        A[i, j] = 3 * A[i-1, j] + (A[i, j-1] mod 2)     | 1
return A[n, k]                                          | 1
```

```
T(n, k) = k * 1 + (n - 1) * 1 + (n - 1) * (k - 1) * 1 + 1 = k + n - 1 + nk - n - k + 1 + 1 = nk + 1 = O(n*k)
```


### 3.

> Liczby Eulera `E(i, j)` określone są wzorami:
```
E(0, 0) = 1
E(n, 0) = 1,    E(n, n) = 0                         dla n = 1, 2, ...
E(n, k) = (k+1) * E(n-1, k) + (n-k) * E(n-1, k-1)   dla n > 1, 1 ≤ k ≤ (n - 1)
```
Podaj pseudokod algorytmu wykorzystującego metodę **programowania dynamicznego** do znajdowania dla danego `n` oraz `k` (`0 ≤ k ≤ n`) liczby `E(n, k)`.

Pierwsze co powinno zwrócić naszą uwagę to fakt, że argumenty funkcji `f` przyjmują wartości od `0`. W poprzednich zadaniach argumenty przyjmowały wartości od `1` i od tej wartości indeksowaliśmy tablice. Co robimy w tym wypadku? Uznajemy, że nasza tablica `A` jest indeksowana od zera: `A[0..n, 0..k]`.

Tym razem mamy trzy formuły nierekurencyjne, ale postępujemy dokładnie tak samo jak wcześniej. Na potrzeby tego zadania użyję tablicy o wymiarach `12 x 9`. Tablica po ich wykonaniu powinna wyglądać następująco:

|   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|---|
| **0** | 1 |   |   |   |   |   |   |   |   |
| **1** | 1 | 0 |   |   |   |   |   |   |   |
| **2** | 1 |   | 0 |   |   |   |   |   |   |
| **3** | 1 |   |   | 0 |   |   |   |   |   |
| **4** | 1 |   |   |   | 0 |   |   |   |   |
| **5** | 1 |   |   |   |   | 0 |   |   |   |
| **6** | 1 |   |   |   |   |   | 0 |   |   |
| **7** | 1 |   |   |   |   |   |   | 0 |   |
| **8** | 1 |   |   |   |   |   |   |   | 0 |
| **9** | 1 |   |   |   |   |   |   |   |   |
| **10** | 1 |  |   |   |   |   |   |   |   |
| **11** | 1 |  |   |   |   |   |   |   |   ||

Przeanalizujmy teraz naszą zmodyfikowaną formułę rekurencyjną:

```
A[n, k] = (k+1) * A[n-1, k] + (n-k) * A[n-1, k-1]
```

W tej formule występują dwa odwołania do naszej tablicy:
* `A[n-1, k]` - wartość przechowywana w komórce nad naszym elementem
* `A[n-1, k-1]` - wartość przechowywana w komórce znajdującej się po lewej stronie w rzędzie nad naszym elementem

Naszym zadaniem jest znalezienie wartości `A[n, k]`, zaznaczmy `x` wszystkie komórki, których wartości, zgodnie z powyższymi odwołaniami, musimy wcześniej obliczyć by móc wykonać zadanie:

|   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|---|
| **0** | 1 |   |   |   |   |   |   |   |   |
| **1** | 1 | 0 |   |   |   |   |   |   |   |
| **2** | 1 | x | 0 |   |   |   |   |   |   |
| **3** | 1 | x | x | 0 |   |   |   |   |   |
| **4** | 1 | x | x | x | 0 |   |   |   |   |
| **5** | 1 |   | x | x | x | 0 |   |   |   |
| **6** | 1 |   |   | x | x | x | 0 |   |   |
| **7** | 1 |   |   |   | x | x | x | 0 |   |
| **8** | 1 |   |   |   |   | x | x | x | 0 |
| **9** | 1 |   |   |   |   |   | x | x | x |
| **10** | 1 |  |   |   |   |   |   | x | x |
| **11** | 1 |  |   |   |   |   |   |   | x ||

I w tym momencie musimy podjąć bardzo ważną decyzję. Jak sami widzicie, nie musimy obliczać wszystkich elementów poniżej przekątnej, ale znacznie ułatwi to nasz zapis. Ja zdecyduję się na trudniejsze rozwiązanie, ale ta decyzja nie powinna mieć wpływu na ocenę tego zadania.

```
E(n, k)
for i = 0 to n do
    A[i, 0] = 1
for i = 1 to k do
    A[i, i] = 0
for i = 1 to k do
    for j = i + 1 to i + (n - k) do
        A[j, i] = (i+1) * A[j-1, i] + (j-i) * A[j-1, i-1]
return A[n, k]
```


