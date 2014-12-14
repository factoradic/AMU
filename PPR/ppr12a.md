# Zadanie Pudełeczka (ppr12a)

Mała Zosia chowa swoje skarby w pudełeczkach. Często chciałaby wiedzieć, ile w którym się znajduje, ale niestety nie umie jeszcze liczyć, więc poprosiła Cię, abyś jej pomógł. Napisz program, który odpowie na pytanie Zosi: Ile skarbów znajduje się w pudełeczkach, które stoją pomiędzy dwoma wskazanymi pudełkami?

### Wejście

Pierwsza linia wejścia składa się z jednej liczby całkowitej `x` (`1 <= x <= 1000`) oznaczającej liczbę pudełeczek. W kolejnej linii znajduje się x liczb całkowitych opisujących liczbę skarbów w każdym pudełeczku - od pierwszego do `x`-tego. Każde pudełeczko mieści co najwyżej `100` skarbów.
W kolejnej linii znajduje się liczba `y` (`1 <= y <= 1000`) zapytań Zosi. Kolejnych `y` linii zawiera po dwie liczby całkowite `a` i `b` (`1 <= a <= b <= x`), oznaczające numery pudełek wskazanych przez Zosię.

### Wyjście

Na wyjściu należy wypisać `y` linii - każda powinna zawierać dokładnie jedną liczbę, która jest odpowiedzią na pytanie Zosi, czyli łączną liczbą skarbów w pudełkach, które stoją pomiędzy wskazanymi (wraz z zawartością wskazanych pudełek).
*Uwaga*: Zawartość pudełek wskazanych przez Zosię (czyli krańcowych) wlicza się do łącznej liczby skarbów "pomiędzy" nimi.

### Przykład

```
Wejście:
6
1 2 3 4 5 6
4
1 3
2 4
4 4
1 6

Wyjście:
6
9
4
21
```

### Rozwiązanie

```cpp
#include <iostream>

void fillArray(int*, int);
int sumSubarray(int*, int, int);

int main() {
    int x, y, a, b;
    std::cin >> x;
    int tab[x];
    fillArray(tab, x);
    std::cin >> y;
    for(int i = 0; i < y; i++) {
        std::cin >> a >> b;
        std::cout << sumSubarray(tab, a, b) << std::endl;
    }
    return 0;
}

void fillArray(int T[], int n) {
    for(int i = 0; i < n; i++) {
        std::cin >> T[i];
    }
}

int sumSubarray(int T[], int x, int y) {
    int result = 0;
    for(int i = x - 1; i < y; i++) {
        result += T[i];
    }
    return result;
}
```