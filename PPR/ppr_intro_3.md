# Zadanie Iloraz (ppr_intro_3)

Napisz program, który obliczy iloraz dwóch liczb zmiennoprzecinkowych `A` i `B` i wypisze go z dokładnością do czterech miejsc po przecinku.

### Wejście

Dwie liczby zmiennoprzecinkowe `A` i `B`.

### Wyjście

Iloraz liczb `A` i `B` z dokładnością do czterech miejsc po przecinku.

### Przykład

```
Wejście
5.1234 2.123

Wyjście
2.4133
```

### Rozwiązanie

```cpp
#include <iostream>
#include <iomanip>

int main() {
    float a, b;
    std::cin >> a >> b;
    std::cout << std::fixed << std::setprecision(4) << a / b;
    return 0;
}
```