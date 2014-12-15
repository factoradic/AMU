# Zadanie Duże litery odwrotnie (ppr7c)

Napisz program, który wczyta sekwencję liter, po czym wypisze w odwrotnej kolejności wyłącznie duże litery.

### Wejście

W pierwszej linii wejścia znajduje się liczba całkowita N (`2 <= N <= 300`). Druga linia wejścia zawiera `N` liter małych lub dużych.

### Wyjście

Na wyjściu powinien znaleźć się ciąg oddzielonych spacjami podanych wcześniej dużych liter w odwrotnej kolejności.

### Przykład

```
Wejście:
3
a B C

Wyjście:
C B
```

```
Wejście:
7
a b C d E f G

Wyjście:
G E C
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	char ch;
	char T[n];
	for(int i = 0; i < n; i++) {
		std::cin >> ch;
		T[i] = ch;
	}
	for(int i = n - 1; i >= 0; i--) {
		if(T[i] >= 'A' && T[i] <= 'Z') {
			std::cout << T[i] << " ";
		}
	}
	return 0;
}
```