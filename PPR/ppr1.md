# Zadanie A+B (ppr1)

Dane są dwie liczby całkowite, A i B. Należy obliczyć ich sumę.

### Wejście

Wejście składa się z jednej linii, zawierającej oddzielone spacją dwie liczby całkowite, `A` i `B` (`-1000 < A, B < 1000`).

### Wyjście

Należy wypisać napis `"suma="`, a następnie sumę liczb `A` i `B`.

### Przykład

```
Wejście:
12 4

Wyjście: 
suma=16
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    std::cout << "suma=" << A + B;
    return 0;
}
```