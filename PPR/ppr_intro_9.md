# Zadanie Tylko podzielne z przedziału (ppr_intro_9)

Napisz program, który wypisze wszystkie liczby podzielne przez `X` znajdujące się pomiędzy liczbami `A` i `B` (włącznie).

**Uwaga**: `A` może być większe niż `B`.

### Wejście

Trzy liczby całkowite: dzielnik `X` oraz granice przedziału `A` i `B`.

### Wyjście

Liczby podzielne przez `X` z przedziału `A` i `B` (włącznie), oddzielone spacją.

### Przykład

```
Wejście
5 3 15

Wyjście
5 10 15
```

```
Wejście
5 15 3

Wyjście
15 10 5
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int x, a, b;
    std::cin >> x >> a >> b;
    if(a < b) {
        for(int i = a; i <= b; i++) {
            if(i % x == 0) {
                std::cout << i << " ";
            }
        }
    } else {
        for(int i = a; i >= b; i--) {
            if(i % x == 0) {
                std::cout << i << " ";
            }
        }
    }
    return 0;
}
```