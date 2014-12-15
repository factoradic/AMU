# Zadanie Suma wielu liczb (ppr_intro_8)

Napisz program, który wczyta N liczb całkowitych i obliczy ich sumę.

### Wejście

W pierwszej linii wejścia znajduje się liczba `N` oznaczająca ilość kolejnych liczb na wejściu do wczytania.

### Wyjście

Suma `N` liczb, które pojawiły się na wejściu.

### Przykład

```
Wejście
4
1 2 3 10

Wyjście
16
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int n, a, s = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> a;
        s += a;
    }
    std::cout << s;
    return 0;
}
```