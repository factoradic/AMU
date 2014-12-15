# Zadanie Suma kwadratów (ppr_intro_1)

Napisz program, który wczyta dwie liczby i wypisze sumę ich kwadratów.

### Wejście:

Dwie liczby całkowite `A` i `B`.

### Wyjście:

Jedna liczba całkowita będąca sumą kwadratów liczb `A` i `B`.

### Przykład:

```
Wejście:
2 3

Wyjście:
13
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << (a * a) + (b * b);
	return 0;
}
```