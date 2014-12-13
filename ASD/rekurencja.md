# Zadania rekurencyjne

*Darmowe punkty. Zadania z rekurencji wymagają tylko jednej umiejętności - czytania. Pamiętajcie o tym, że każda funkcja rekurencyjna musi mieć warunek podstawowy (początkowy / końcowy, milion różnych nazw) dla którego funkcja zwróci określoną wartość bez odwołania rekurencyjnego i wzór rekurencyjny dla pozostałych elementów. W tych zadaniach równania rekurencyjne są jednoargumentowe, a sama rekursja jest zazwyczaj postaci liniowej (rekursja na kolumnę).*

### 1. Iloczyn elementów tablicy

> Niech `A[1..n]` będzie tablicą zawierającą pewne liczby. Napisz algorytm rekurencyjny wyznaczający iloczyn elementów w tej tablicy, korzystający z następującej własności: iloczyn wszystkich elementów w tablicy jest iloczynem wartości pierwszego elementu oraz wartości iloczynu elementów od drugiego do ostatniego. Podaj równanie rekurencyjne opisujące czas działania tego algorytmu i rozwiąż je (podaj dokładne oszacowanie asymptotyczne).

Zacznijmy od ustalenia ilu parametrów wejściowych potrzebujemy. Na pewno musimy przekazać koniec tablicy by wiedzieć do jakiego indeksu możemy / musimy liczyć. Zgodnie z treścią zadania powinniśmy również przekazywać tablicę od pewnego elementu ("wartości iloczynu elementów od **drugiego** do ostatniego"). Wiemy już, że potrzebne nam są trzy parametry - tablica, indeks początkowy, indeks końcowy.

Warunek podstawowy naszej rekurencji nie został podany w treści zadania. Musimy odpowiedzieć sobie na pytanie: "kiedy obliczenie iloczynu `n` liczb jest trywialne?". Odpowiedź jest prosta, gdy `n` jest równe `1`, wtedy wynikiem naszych działań będzie właśnie ta liczba. Podobnej zależności używaliśmy przy algorytmach sortowania, tablice jednoelementowe uznajemy za posortowane.

```
ILOCZYN(A, p, k)
if p == k then return A[p]                  | 2
return A[p] * ILOCZYN(A, p + 1, k)          | T(n - 1) + 1
```

Po prawej stronie, za pionowymi kreskami zapisałem ilość operacji w danej linii. W drugiej znajduje się `T(n - 1)`, ponieważ wywołujemy rekurencyjnie naszą funkcję, ale rząd danych jest mniejszy o `1`.

Złożoność obliczamy za pomocą rozpisywania kolejnych wywołań rekurencyjnych. Następnie wykreślamy stałe i otrzymujemy oszacowanie asymptotyczne.

```
T(n) = 2 + T(n -1) + 1 = T(n - 1) + 3 = T(n - 2) + 3 + 3 = T(0) + 3 * n = 3n = O(n)
```

### 2. Suma elementów tablicy

> Niech `A[1..n]` będzie tablicą zawierającą pewne liczby. Napisz algorytm rekurencyjny wyznaczający sumę elementów w tej tablicy, korzystający z następującej własności: suma wszystkich elementów w tablicy jest sumą wartości pierwszego elementu oraz wartości sumy elementów od drugiego do ostatniego. Podaj równanie rekurencyjne opisujące czas działania tego algorytmu i rozwiąż je (podaj dokładne oszacowanie asymptotyczne).

Jest to zadanie bardzo podobne do zadania wyżej, zbyt podobne. Jeżeli nie rozumiecie kodu poniżej, proszę wrócić do opisu zadania pierwszego i w każdym miejscu, w którym napisałem *iloczyn* wstawić *sumę*.

```
SUMA(A, p, k)
if p == k then return A[p]                  | 2
return A[p] + SUMA(A, p + 1, k)             | T(n - 1) + 1
```

```
T(n) = 2 + T(n -1) + 1 = T(n - 1) + 3 = T(n - 2) + 3 + 3 = T(0) + 3 * n = 3n = O(n)
```


### 3. Sześcian liczby

> Sześcian liczby `f(n) = n^3` może zostać wyznaczony za pomocą następującego równania rekurencyjnego: `f(n) = f(n - 1) + 3n^2 - 3n + 1` przy czym `f(1) = 1`. Napisz procedurę rekurencyjną wyznaczającą tę wartość oraz określ złożoność czasową podanego algorytmu.

Tym razem w treści zadania mamy jasno zdefiniowany warunek podstawowy. Jednak sama struktura naszego kodu będzie wyglądać dokładnie tak samo:

```
SZESCIAN(n)
if n == 1 then return 1                     | 2
return SZESCIAN(n - 1) + 3n^2 - 3n + 1      | T(n - 1) + 1
```

```
T(n) = 2 + T(n -1) + 1 = T(n - 1) + 3 = T(n - 2) + 3 + 3 = T(0) + 3 * n = 3n = O(n)
```

### 4. Podzielne przez 11

> Liczba jest podzielna przez `11`, jeżeli wartość bezwzględna z różnicy sumy jej cyfr stojących na miejscach parzystych i sumy jej cyfr stojących na miejsca nieparzystych dzieli się przez `11`. Wykorzystując podaną własność napisz pseudokod **rekurencyjnej funkcji `PODZIELNE11(n)`** sprawdzającej, czy dana liczba `n ≥ 0` jest podzielna przez `11` wobec faktu, że jedyną liczbą jednocyfrową podzielną przez `11` jest zero. Użyj funkcji `ABS(x)` dla oznaczenia wartości bezwzględnej z `x`.

To zadanie wymaga od nas większego skupienia. Warunek początkowy jest jasno określony w zadaniu, ale naprawdę łatwo jest pomylić się i uznać, że algorytm powinien zakończyć się, gdy `n == 0`. Tak naprawdę jest to warunek dla którego algorytm zakończy swoją pracę i zwróci wartość `true`. Ale jeżeli nasze `n` będzie równe `8` to po obliczeniu różnicy sumy jej cyfr stojących na miejscach nieparzystych (`8`) i sumy cyfr stojących na miejscach parzystych (`0`) otrzymujemy `8`. Pętla nieskończona. Dlatego warunek podstawowy to `n < 10` i teraz możemy decydować o tym jaką wartość zwrócić, jeżeli `n` jest równe `0` to `true`, w przeciwnym wypadku `false` (bo `0` jest jedyną liczbą jednocyfrową podzielną przez `11`).

Musimy również znaleźć sposób na obliczenie sumy cyfr stojących na miejscach parzystych i nieparzystych. Warto pamiętać, że ostatnią cyfrę danej liczby `x` możemy uzyskać przez działanie `x mod 10` a następnie możemy usunąć tę cyfrę z liczby `x` za pomocą dzielenia całkowitego: `x div 10`.

To co może być zaskakujące w moim rozwiązaniu to to, że w każdej iteracji pętli `while` usuwam dwie cyfry z liczby `n`. Nie ma to negatywnego wpływu na działanie programu z tego powodu, że `0 mod 10` jest równe `0` i `0 div 10` jest również równe `0`.

```
PODZIELNE11(n)
// sprawdzenie warunku podstawowego
if n < 10 then
    if n == 0 then return true
    return false

// a - suma cyfr z pozycji nieparzystych
a = 0
// b - suma cyfr z pozycji parzystych
b = 0
// dopoki n jest rozne od 0 (...)
while n ≠ 0 do
    // dodaj do a ostatnia cyfre
    a = a + n mod 10
    // usun z n ostatnia cyfre
    n = n div 10
    // dodaj do b ostatnia cyfre
    b = b + n mod 10
    // usun z n ostatnia cyfre
    n = n div 10
return PODZIELNE11(ABS(a - b))
```

### 5. Podzielne przez 4

> Niech `A[1..n]` będzie tablicą zawierającą liczby dodatnie. Napisz pseudokod algorytmu wykorzystującego metodę **dziel i zwyciężaj** do znalezienia liczby elementów tej tablicy, które są podzielne przez `4`. Podaj równanie rekurencyjne opisujące czas działania tego algorytmu i rozwiąż je (podaj dokładnie oszacowanie asymptotyczne).

Zgodnie z zasadą dziel i zwyciężaj musimy dzielić nasz główny problem na podproblemy tak długo aż dojdziemy do problemów trywialnych.

W naszym zadaniu podproblemem będzie zliczenie liczb podzielnych przez `4` w podtablicy. A problemem trywialnym będzie zliczenie liczb podzielnych przez `4` w tablicy o długości `1`.

```
PODZIELNE_4(A, p, k)
if p == k then                                              | 1
    if A[p] mod 4 == 0 then                                 | 1
        return 1                                            | 1
    else
        return 0
else
    q = (p + k) div 2                                       | 1
    return PODZIELNE_4(A, p, q) + PODZIELNE_4(A, q + 1, k)  | 2 * T(n/2) + 1
```

```
T(n) = 3 + 1 + 2 * T(n/2) + 1 = 2 * T(n/2) + 5
```

Z twierdzenia o rekurencji:
```
a       = 2
b       = 2
f(n)    = 5

log(b) a = log(2) 2 = 1
```

Z pierwszego przypadku twierdzenia o rekurencji `T(n) = Θ(n)`, algorytm ma złożoność liniową.

## Drobne wariacje

Czasem, w treści zadania mamy podany gotowy nagłówek naszej procedury / funkcji, którą mamy napisać. Wróćmy na chwilę do zadania pierwszego. Co by było, gdyby nagłówek w tym zadaniu wyglądał następująco: `ILOCZYN(A, n)`?

Brakuje nam jednego parametru. Wiemy, że `n` oznacza liczebność naszej tablicy, a więc jest to również ostatni indeks występujący w tej tablicy.

Rozwiązanie jest bardzo proste. Jeżeli możemy kontrolować tylko indeks do którego nasza funkcja zlicza iloczyn to musimy przyjąć, że będzie ona zliczać od elementu o stałym indeksie - `1`.

Jeżeli mamy tablicę o długości równej `4` postaci `[2, 4, 3, 6]` i chcemy obliczyć iloczyn wszystkich elementów tej tablicy mając do dyspozycji:
1. Element ostatni tablicy - `A[n]`
2. Funkcję zliczającą iloczyn tablicy od pierwszego elementu do zadanego zakresu

to wiemy, że rozwiązaniem będzie formuła `ILOCZYN(A, n) = A[n] * ILOCZYN(A, n - 1)`.

```
ILOCZYN(A, n)
if n == 1 then return A[1]                  | 2
return A[n] * ILOCZYN(A, n - 1)             | T(n - 1) + 1
```
