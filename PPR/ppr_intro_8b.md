# Zadanie Zliczanie wystąpień (ppr_intro_8b)

Napisz program, który wczyta `N` liczb całkowitych i zliczy ile razy wśród nich pojawiła się liczba `X`.

### Wejście

W pierwszej lini wejścia znajdują się liczba całkowita `X` oraz liczba `N` oznaczająca ilość kolejnych liczb do wczytania, które pojawią się na wejściu w drugiej linii.

### Wyjście

Liczba wystąpień liczby `X` wśród podanych `N` liczb.

### Przykład

```
Wejście
2 5
1 -2 2 12 2

Wyjście
2
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int n, a, x, s = 0;
    std::cin >> x >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> a;
        if(a == x) {
            s++;
        }
    }
    std::cout << s;
    return 0;
}
```