# Zadanie Odwróć tablicę (ppr_intro_10)

Napisz program, który wczyta `N` liczb całkowitych i wypisze je w odwrotnej kolejności.

### Wejście

W pierwszej linii wejścia znajduje się liczba `N` (`1 <= N <= 1000`) oznaczająca ilość kolejnych liczb na wejściu do wczytania.

### Wyjście

`N` liczb, które pojawiły się na wejściu w odwrotnej kolejności i oddzielone spacją.

### Przykład

```
Wejście:
4
1 2 3 4

Wyjście:
4 3 2 1
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int n, number;
    std::cin >> n;
    int T[n];   
    for(int i = 0; i < n; i++) {
        std::cin >> number;
        T[i] = number;
    }
    for(int i = n - 1; i >= 0; i--) {
        std::cout << T[i] << " ";
    }
    return 0;
}
```