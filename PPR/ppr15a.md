# Zadanie Synowie Abrahama (ppr15a)

Stary Abraham miał siedmiu synów. Każdy potomek Abrahama z parzystego pokolenia (wnuk, praprawnuk, praprapraprawnuk...) miał `3` synów, a każdy potomek Abrahama z nieparzystego pokolenia (syn, prawnuk, prapraprawnuk...) miał `5` synów. Oj, liczne jest potomstwo Abrahama – dlatego nie dziwi, że stary Abraham nie może się doliczyć swoich zstępnych. Pomóż Abrahamowi policzyć swoich potomków.

### Wejście

Pierwsza linia wejścia składa się z jednej liczby całkowitej `1 <= N <= 20`, która oznacza liczbę testów.
W każdej z `N` kolejnych linii znajduje się liczba `1 <= M <= 15`, która oznacza liczbę pokoleń, które bierzemy pod uwagę.

### Wyjście

Dla każdej liczby `M` należy w osobnym wierszu wypisać liczbę potomków Abrahama (nie wliczając samego Abrahama) od pierwszego aż do `M`-tego pokolenia (pierwszym pokoleniem są synowie Abrahama, drugim – wnuki itd.).

### Przykład

```
Wejście:
4
1
2
3
5

Wyjście:
7
42
147
2247
```

### Rozwiązanie

```cpp
#include <iostream>

int sa(int);

int main() {
	int n;
	std::cin >> n;
	while(n--) {
        int m;
        std::cin >> m;
        std::cout << sa(m) << std::endl;
    }
	return 0;
}

int sa(int n) {
    if (n == 0) return 0;
    if (n == 1) return 7;
    if (n % 2 == 0) return 5 * (sa(n - 1) - sa(n - 2)) + sa(n - 1);
    return 3 * (sa(n - 1) - sa(n - 2)) + sa(n - 1);
}
```