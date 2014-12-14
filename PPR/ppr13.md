# Zadanie Silnie (ppr13)

Wartość `k`-tej silni wielokrotnej z liczby `n` (oznaczaną przez `n` z `k` wykrzyknikami) obliczamy ze wzorów `n!!...! = 1`, jeśli `0 <= n < k`, oraz `n!!...! = n((n-k)!!...!)`, jeśli `n >= k` (we wszystkich wzorach występuje po `k` wykrzykników). Napisz program służący do obliczania wartości silni wielokrotnych.

### Wejście

W pierwszej linii wejścia znajduje się jedna liczba całkowita `t <= 10` oznaczająca liczbę testów.
W kolejnych liniach znajdują się poszczególne testy. Każdy z nich składa się z dwóch liczb całkowitych, `n` oraz `k` (`1 <= n, k <= 12`).

### Wyjście

Dla każdego testu wypisz w osobnej linii wartość `k`-tej silni liczby `n`.

### Przykład

```
Wejście:
3
5 1
5 2
10 4

Wyjście:
120
15
60
```

### Rozwiązanie

```cpp
#include <iostream>

int silnia(int, int);

int main() {
    int t, n, k;
    std::cin >> t;
    for(int i = 0; i < t; i++) {
        std::cin >> n >> k;
        std::cout << silnia(n, k) << std::endl;
    }
    return 0;
}

int silnia(int a, int b) {
    if (a < b) {
        return 1;
    }
    return a * silnia(a - b, b);
}
```