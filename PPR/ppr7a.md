# Zadanie Odwrócone podciągi (ppr7a)

Profesor Nowak jest matematykiem i bada własności ciągów i ich podciągów. Dla danego ciągu (`a_n`) potrzebuje znaleźć podciąg złożony z co trzeciego wyrazu tego podciągu (`a_3n`). Poprosił Cię o pomoc. Napisz program, który po wczytaniu `N` pierwszych wyrazów ciągu wypisze wyrazy szukanego podciągu, ale w odwrotnej kolejności.

### Wejście

W pierwszej linii wejścia znajduje się liczba całkowita `N` (`2 <= N <= 200`). Druga linia wejścia zawiera `N` wyrazów ciągu, czyli liczb całkowitych z zakresu od `0` do `999`.

### Wyjście

Na wyjściu powinien znaleźć się ciąg oddzielonych spacjami liczb, będący wypisanym od końca szukanym podciągiem.

### Przykład

```
Wejście:
9
9 8 7 6 5 4 3 2 1

Wyjście:
1 4 7
```

```
Wejście:
7
2 2 5 1 1 3 4

Wyjście:
3 5
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
	int n, a;
	std::cin >> n;
	int T[n];
	for(int i = 0; i < n; i++) {
		std::cin >> a;
		T[i] = a;
	}
	for(int i = n - (n % 3) - 1; i >= 0; i -= 3) {
		std::cout << T[i] << " ";
	}
	return 0;
}
```