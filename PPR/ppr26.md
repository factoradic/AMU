# Zadanie NWD (ppr26)

Oblicz największy wspólny dzielnik czterech liczb.

### Wejście

Pierwsza linia wejścia składa się z jednej liczby całkowitej `x` (`1 <= x <= 1000`) oznaczającej liczbę zestawów danych.

Każdy zestaw składa się z czterech liczb naturalnych (od `1` do `30000`).

### Wyjście

Dla każdego zestawu należy wypisać największy wspólny dzielnik liczb podanych na wejściu.

### Przykład

```
Wejście:
2
2 3 4 5
30 15 10 25

Wyjście:
1
5
```

### Rozwiązanie

```cpp
#include <iostream>

int NWD(int, int);
int NWD(int[], int);

int main() {
	int x;
	std::cin >> x;
	while(x--) {
		int d[4];
		std::cin >> d[0] >> d[1] >> d[2] >> d[3];
		std::cout << NWD(d, 4) << std::endl;
	}
  return 0;
}

int NWD(int a, int b) {
    int c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int NWD(int array[], int length) {
    int result = array[0];
    for(int i = 1; i < length; i++) {
        result = NWD(result, array[i]);
    }
    return result;
}
```