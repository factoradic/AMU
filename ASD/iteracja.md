# Zadania iteracyjne

*Są to zadania o niskim poziomie trudności. Polegające zazwyczaj na napisaniu kodu proceduralnego opartego na pętli for / while. Łatwość zadań może być złudna. Zwracajcie uwagę na przypadki szczególne, takie jak tablica jednoelementowa, brak danego elementu w tablicy czy tablica jedynie z ujemnymi wartościami. Myślcie.*

### 1. Scalanie ciągu V-kształtnego
> Dane jest `n ≥ 2` i tablica `A` zawierająca `n` różnych elementów indeksowanych od `1` do `n`. Kolejne elementy od początku tablicy `A` najpierw maleją do pewnego miejsca, a następnie od tego miejsca rosną tworząc tak zwany ciąg V-kształtny, np. `12, 9, 7, 3, 1, 2, 5, 8, 17, 28, 49`.

> Napisz w pseudokodzie fragment algorytmu, który wykorzystując pomocniczą tablicę `B[1..n]`, dokona scalenia obu tych podciągów w jeden ciąg rosnący. Podany algorytm powinien mieć złożoność `O(n)`.

Rozwiązaniem tego zadania jest zmodyfikowany algorytm scalania liniowego, którego używaliśmy między innymi przy sortowaniu przez scalanie.

W pierwotnym algorytmie potrzebowaliśmy jednak jednego dodatkowego parametru - indeksu ostatniego elementu pierwszego ciągu / pierwszego elementu drugiego ciągu (zależnie od wersji). Jednak wtedy obie podtablice były posortowane według tej samej reguły.

W tym zadaniu mamy od początku łatwy dostęp do elementów najwyższych obu podtablic (`12` = `A[1]` i `49` = `A[n]`). Dlatego w naszym algorytmie przyrost elementów posortowanych będzie następował z prawej strony. Łatwiej jest nam wskazać element największy całej tablicy niż element najmniejszy.

```
SCAL_V(T, n)
i = 1
j = n
indeks = n
while indeks > 0 do
    if A[i] > A[j] then
        B[indeks] = A[i]
        i = i + 1
    else
        B[indeks] = A[j]
        j = j - 1
    indeks = indeks - 1
return B
```

### 2. Suma elementów podtablicy

> Dana jest tablica `T[1..n]` zawierająca liczby naturalne. Napisz pseudokod algorytmu, który obliczy sumę wszystkich liczb w tej tablicy po pierwszym wystąpieniu pewnej określonej wartości `x`. Np. dla tablicy `[1, 5, 4, 2, 6, 3, 2]` i `x = 2` prawidłową odpowiedzią jest `11`. Parametrami wejściowymi algorytmu powinny być wartości `T`, `n` i `x`.

Jedynym problematycznym składnikiem tego zadania jest konieczność zlokalizowania pierwszego wystąpienia elementu `x` i ignorowanie kolejnych wystąpień tej liczby.

```
SUMA_OD_X(T, n, x)
suma = 0
for i = 1 to n do
    if T[i] == x then
        // w tym momencie i wskazuje na indeks
        // pierwszego wystapienia elementu x,
        // ktory nie ma byc czescia naszej obliczanej sumy
        i = i + 1
        while i ≤ n do
            suma = suma + T[i]
            i = i + 1
return suma
```

### 3. Zliczanie wystąpień elementów z przedziału

> Dana jest tablica `T[1..n]` zawierająca liczby naturalne. Napisz pseudokod algorytmu, który obliczy, ile razy występują w niej wartości z przedziału domkniętego `<x, y>`, zanim w tablicy nie pojawi się liczba `z` (`z` nie należy do przedziału `<x, y>`, przy czym tablicę przeglądamy od indeksu `1` do indeksu `n`. Jeśli liczby `z` nie ma w tablicy, to należy wyznaczyć liczbę wszystkich wystąpień wartości z przedziału `<x, y>`. Parametrami wejściowymi algorytmu powinny być wartości `T`, `n`, `x`, `y` i `z`.

W tym zadaniu musimy zwrócić uwagę na jeden przypadek specjalny - gdy w tablicy `T` element `z` w ogóle nie występuje.

```
ZLICZ_DO_X(T, n, x, y, z)
wynik = 0
for i = 1 to n do
    if T[i] == z then return wynik
    if T[i] ≥ x and T[i] ≤ y then wynik = wynik + 1
// na wypadek gdyby element z nie wystepowal w tablicy
return wynik
```

### 4. Zliczanie elementów mniejszych od x w posortowanej tablicy

> Dana jest posortowana tablica liczb całkowitych `A`, gdzie `A[1] < A[2] < ... < A[n]`. Napisz pseudokod algorytmu podającego dla danej liczby `x` ilość elementów mniejszych od `x` w posortowanej tablicy.

Kolejne zadanie, w którym musimy zwrócić uwagę na jeden specjalny przypadek, tym razem jest to tablica wartości niemniejszych niż `x`. By rozwiązać ten drobny problem posłużymy się podobnym zabiegiem co wyżej, dodamy jedną instrukcję `return` za pętlą `for`.

```
ZLICZ_DO_X(T, n, x)
wynik = 0
for i = 1 to n do
    if T[i] ≥ x then return wynik
    wynik = wynik + 1
return wynik
```

### 5. Znajdź element najczęściej występujący

> Dana jest tablica `T[1..n]`, w której elementy mogą się powtarzać. Wyszukaj element, który najwięcej razy się powtarza w tablicy. Niedozwolone jest użycie tablic pomocniczych.

Takie zadania w pewnych kręgach noszą bardzo ładną nazwę - *pułapki ambicji*. Myślcie trzeźwo, jeżeli zadanie nie wymaga od Was zmieszczenia się w złożoności `O(lg n)` to nie przejmujcie się tym, że złożoność jest kwadratowa. Istnieją takie problemy, niestety.

Zachęcam wszystkich do poświęcenia czasu na research, jeżeli uda Wam się znaleźć jeden z moich ulubionych algorytmów (Boyer Moore majority algorithm) i go zrozumiecie to będę naprawdę pod wrażeniem, ale jeżeli zaczniecie zastanawiać się jak zmodyfikować ten algorytm by rozwiązać to zadanie to okażecie się idiotami, trudno.

Pomysł na rozwiązanie tego zadania jest dosyć intuicyjny. Zaczynając od elementu pierwszego aż do elementu przedostatniego (ostatni element pomijamy bo występuje on tylko jeden raz (zgodnie z naszą regułą zliczania), więc nie może on być elementem najczęściej występującym) zliczamy ilość wystąpień wartości pod aktualnym indeksem **od** aktualnego indeksu do końca tablicy. Nie zliczamy poprzednich wystąpień, ponieważ jeżeli dany element wystąpił już wcześniej to już zliczyliśmy jego wszystkie wystąpienia.

```
NAJ_WYS(A, n)
il_wyst_naj = 0
element_naj = 0 // ta linia nie jest wymagana
for i = 1 to n - 1 do
    il_wyst = 1
    for j = i + 1 to n do
        if A[j] == A[i] then il_wyst = il_wyst + 1
    if il_wyst > il_wyst_naj then
        il_wyst_naj = il_wyst
        element_naj = A[i]
return element_naj
```

### 6. Liczby pierwsze Sophie Germain

> Napisz pseudokod funkcji `PIERWSZA_SG(a)`, która zwraca `true`, jeśli dana liczba naturalna `a` jest liczbą pierwszą Sophie Germain, oraz `false` w przeciwnym przypadku. Liczba `a` jest liczbą pierwszą Sophie Germain, jeśli `a` jest liczbą pierwszą i `2a + 1` jest liczbą pierwszą. Np. `23` jest liczbą pierwszą Sophie Germain, ponieważ `23` i `47` są liczbami pierwszymi. Określ złożoność swojego algorytmu (odpowiedź uzasadnij).

```
PIERWSZA(a)
if a == 1 then                                                      | 1
    return false                                                    | 1
if a == 2 then                                                      | 1
    return true                                                     | 1
for i = 2 to SQRT(a) do                                             | a^(1/2) - 1
    if a mod i == 0 then                                            | 1
        return false                                                | 1
return true                                                         | 1

PIERWSZA_SG(a)
if PIERWSZA(a) == true and PIERWSZA(2a + 1) == true then            | 2 * (5 + 2 * (a^(1/2) - 1))
    return true                                                     | 1
return false                                                        | 1
```

```
T(n) = 1 + 2 * (5 + 2 * (n^(1/2) - 1)) = 1 + 2 * (2 * n^(1/2) + 3) = 7 + 4 * n^(1/2) = O(n^(1/2))
```








