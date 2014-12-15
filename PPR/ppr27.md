# Zadanie NWW (ppr27)

Oblicz najmniejszą wspólną wielokrotność czterech liczb.

### Wejście

Pierwsza linia wejścia składa się z jednej liczby całkowitej `x` (`1 <= x <= 1000`) oznaczającej liczbę zestawów danych.

Każdy zestaw składa się z czterech liczb naturalnych (od `1` do `100`).

### Wyjście

Dla każdego zestawu należy wypisać najmniejszą wspólną wielokrotność liczb podanych na wejściu.

### Przykład

```
Wejście:
2
2 3 4 5
30 15 10 25

Wyjście:
60
150
```

### Rozwiązanie

```cpp
#include <iostream>

int NWD(int, int);
int NWW(int, int);
int NWW(int[], int);

int main() {
	int x;
	std::cin >> x;
	while(x--) {
		int d[4];
		std::cin >> d[0] >> d[1] >> d[2] >> d[3];
		std::cout << NWW(d, 4) << std::endl;
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

int NWW(int a, int b) {
	return (a * b) / NWD(a, b);
}

int NWW(int array[], int length) {
    int result = array[0];
    for(int i = 1; i < length; i++) {
        result = NWW(result, array[i]);
    }
    return result;
}
```