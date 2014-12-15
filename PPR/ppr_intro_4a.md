# Zadanie Porównanie liczb (ppr_intro_4a)

Napisz program, który wczyta dwie liczby całkowite `A` i `B` i wypisze odpowiedni komunikat `'A>B'`, `'A<B'` lub `'A==B'`.

### Wejście

Dwie liczby całkowite `A` i `B`.

### Wyjście

Napis `'A>B'`, jeżeli liczba `A` jest większa niż `B`, `'A<B'`, jeżeli liczba `A` jest mniejsza od `B` i `'A==B'`, jeżeli liczby są sobie równe.

### Przykład

```
Wejście
2 3

Wyjście
A<B
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << (a > b ? "A>B" : (a == b ? "A==B" : "A<B"));
    return 0;
}
```