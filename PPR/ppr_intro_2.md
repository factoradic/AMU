# Zadanie Delta trójmianu (ppr_intro_2)

Napisz program, który obliczy deltę trójmianu postaci: `Ax^2 + Bx + C == 0`, mając na wejściu dane liczby całkowite `A`, `B` i `C`.

### Wejście

Trzy liczby całkowite `A`, `B` i `C` opisujące trójmian.

### Wyjście

Jedna liczba całkowita będąca wyróżnikiem trójmianu (delta).

### Przykład

```
Wejście
2 3 -1

Wyjście
17
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << b * b - 4 * a * c;
    return 0;
}
```