# Zadanie Trójkąt (ppr24)

Dany jest trójkąt prostokątny. Znamy długość przyprostokątnych. Oblicz długość przeciwprostokątnej (zaokrąglonej w górę do najbliższej liczby całkowitej) oraz wielkość najmniejszego z kątów w tym trójkącie, wyrażoną w stopniach, zaokrągloną do liczby całkowitej.

### Wejście

Pierwsza linia wejścia składa się z jednej liczby całkowitej `x` (`1 <= x <= 1000`) oznaczającej ilość zestawów danych.

Każdy zestaw składa się z dwóch liczb naturalnych (od `1` do `1000`) oznaczających długości przyprostokątnych w trójkącie.

### Wyjście

Dla każdego zestawu należy wypisać dwie liczby całkowite, z których pierwsza oznacza zaokrągloną w górę długość przeciwprostokątnej, a druga to wielkość najmniejszego z kątów wyrażona w stopniach (po zaokrągleniu).

### Przykład

```
Wejście:
3
2 2
3 4
9 8

Wyjście:
3 45
5 37
13 42
```

### Rozwiązanie

```cpp
#include <iostream>
#include <cmath>

int hypotenuse(int a, int b) {
	return std::ceil(std::sqrt(std::pow(a, 2) + std::pow(b, 2)));
}

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int angle(int a, int b) {
	if(a > b) {
		swap(a, b);
	}
	double PI = 3.14159265;
	return round(std::atan((double) a / b) * 180 / PI);
}

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int x, y;
		std::cin >> x >> y;
		std::cout << hypotenuse(x, y) << " " << angle(x, y) << std::endl;
	}
    return 0;
}
```