# Sortowanie

### 1. Sortowanie przez wstawiania

> Dane jest `n >= 1` oraz tablica elementów `A[1..n]`. Elementy w tablicy `A` mogą się powtarzać. Podaj pseudokod algorytmu sortowania tej tablicy **nierosnąco**, wykorzystując metodę **sortowania przez wstawianie**.

Sortowanie przez wstawianie w uproszczeniu polega na *podnoszeniu* kolejnych elementów tablicy i wstawianiu ich w odpowiednie miejsce (poprzez serię porównań i operacji swap).

Pozwolę sobie nie opisywać dokładnie tego sortowania, wikipedia robi to z pewnością lepiej niż ja.

W tym zadaniu jeden fragment powinien zwrócić naszą uwagę - *sortowania tej tablicy nierosnąco*. Przy omawianiu algorytmów sortowania na zajęciach i wykładach zazwyczaj sortowaliśmy od najmniejszego elementu do największego. Teraz musimy postąpić odwrotnie, więc element o największej wartości będzie elementem pierwszym w wynikowej tablicy.

```
SORT_WST(A, n)
// operację sortowania rozpoczynamy od drugiego elementu, ponieważ
// element pierwszy w podtablicy o długości 1 już stoi na odpowiednim miejscu
for i = 2 to n do
    j = i
    // dopóki element podniesiony (A[j]) nie stoi na początku
    // tablicy i jest większy od elementu poprzedniego
    while A[j] > A[j - 1] and j > 1 do
        // zamień miejscami element podniesiony i element poprzedni
        A[j] ↔ A[j - 1] // ↔ to operacja swap
        // zmniejsz wartość indeksu j (który wskazuje na podniesiony element) o 1
        j = j - 1
// zwróć posortowaną tablicę
return A
```

### 2. Sortowanie względem pola powierzchni

> Dany jest ciąg par dodatnich liczb rzeczywistych `(a1, b1), ..., (an, bn)` reprezentujących długości boków `n` prostokątów. Napisz pseudokod algorytmu sortującego (dowolną metodą) te prostokąty w porządku nierosnącym względem wartości ich pól powierzchni. Wynik działania algorytmu powinien być wypisany w postaci posortowanego nierosnąco ciągu liczb oznaczjących pola powierzchni poszczególnych prostokątów. Np. dla danych wejściowych `[2, 2, 1, 8, 1, 1, 4, 8]` prawidłowym wynikiem jest `[32, 8, 4, 1]`. Jaka jest złożoność tego algorytmu? Odpowiedź uzasadnij.

W tym zadaniu musimy zmierzyć się z dwoma problemami:
1. Obliczenie pola powierzchni dla każdej pary boków
2. Posortowanie i zwrócenie pól powierzchni

Te dwa problemy możemy traktować oddzielnie, ale możemy je także sprytnie połączyć. Istnieją takie algorytmy sortowanie, które wymagają jedynie znajomości wartości aktualnie sortowanego elementu i elementów posortowanych do tej pory. W przypadku tych algorytmów możemy w jednej pętli obliczyć i posortować nasze wartości. Takim sposobem sortowania jest na przykład sortowanie przez wstawianie, które opisaliśmy w poprzednim zadaniu.

Po obliczeniu wartości pól powierzchni zmieni się ilość elementów w naszej tablicy z `n` na `n div 2`elementów. Już posortowane elementy będę umieszczał po lewej stronie tablicy.

```
SORT_POLE(A, n)
for i = 1 to n div 2 do
    // obliczamy pole powierzchni aktualnie rozpatrywanego prostokąta
    A[i] = A[2i - 1] * A[2i]
    // sortujemy metodą znaną z sortowania przez wstawianie
    j = i
    while A[j] > A[j - 1] and j > 1 do
        A[j] ↔ A[j - 1] // ↔ to operacja swap
        j = j - 1
// zwracamy pierwszą połowę tablicy A
return A[1..n div 2]
```

### 3. Sortowanie względem dwóch ostatnich cyfr

> Dany jest ciąg `n` czterocyfrowych liczb całkowitych dodatnich `(a1, ..., an)`. Napisz pseudokod algorytmu sortującego te liczby w porządku nierosnącym względem liczb utworzonych przez ich dwie ostatnie cyfry, dowolną metodą **za wyjątkiem** sortowania bąbelkowego. Np. dla wejściowego ciągu `(1268, 7612, 1857, 8573, 3465)` prawidłowym wynikiem jest `(8573, 1268, 3465, 1857, 7612)`. Jaka jest złożoność tego algorymu? Odpowiedź uzasadnij.

Możemy użyć dowolnego algorytmu sortowania (za wyjątkiem bąbelków), więc ja skorzystam z sortowania przez wstawianie, dzięki czemu samej metody sortowania nie będę musiał tłumaczyć.

Dwie ostatnie cyfry danej liczby `n` otrzymujemy przez operację `n mod 100`.

```
SORT_WZG_2OST(A, n)
for i = 2 to n do
    j = i
    while (A[j] mod 100) > (A[j - 1] mod 100) and j > 1 do
        A[j] ↔ A[j - 1]
        j = j - 1
return A
```

```
T(n) = (n-1) * (1 + (n-1) * 2) + 1 = (n-1) * (2n-1) + 1 = O(n^2)
```

