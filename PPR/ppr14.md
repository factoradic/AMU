# Zadanie Króliki (ppr14)

Agnieszka dowiedziała się ostatnio, skąd wziął się ciąg Fibonacciego. Mianowicie, uczony rozważał teoretyczny eksperyment dotyczący szybkości rozmnażania się stada królików przy następujących założeniach:

- na początku mamy jedną nowo narodzoną parę królików
- każda nowa para staje się płodna po miesiącu życia
- każda płodna para ma co miesiąc jedną parę potomstwa
- króliki są nieśmiertelne.

Wartość F(n) oznacza po prostu liczbę par królików po n miesiącach.

Agnieszka zastanawia się teraz, jakie byłoby rozwiązanie analogicznego zagadnienia w przypadku gdyby każda para królików stawała się płodna dopiero po dwóch miesiącach, ale za to miała co miesiąc dwie nowe pary potomstwa.

### Wejście

W pierwszej linii wejścia znajduje się jedna liczba całkowita `t` (`<=5`) oznaczająca liczbę testów.
W kolejnych liniach znajdują się poszczególne testy. Każdy z nich składa się z jednej liczby całkowitej `n` (`0 <= n <= 30`).

### Wyjście

Dla każdego testu wypisz w osobnej linii liczbę par królików otrzymanych po n miesiącach w eksperymencie Agnieszki.

### Przykład

```
Wejście:
4
0
1
3
4

Wyjście:
1
1
3
5
```

### Rozwiązanie

```cpp
#include <iostream>

int kroliki(int);

int main() {
	int t;
	std::cin >> t;    
    while(t--) {
        int pokolenie;
        std::cin >> pokolenie;
        std::cout << kroliki(pokolenie) << std::endl;
    }
    return 0;
}

int kroliki(int n) {
    if(n < 0) {
        return 0;
    } else if(n == 0) {
        return 1;
    } else {
        return kroliki(n - 1) + 2 * kroliki(n - 3);
    }
}
```