# Zadanie Wybory (ppr8)

W wyborach burmistrza Wielkiego Guslaru wystartowało `M` kandydatów ponumerowanych liczbami od `1` do `M`. Każdy z `N` głosujących oddał ważny głos na jednego z nich. Napisz program, który wczyta opis głosów, a następnie poda wyniki głosowania i numer kandydata wybranego na burmistrza. Zgodnie z prawem wyborczym Wielkiego Guslaru, jeśli dwóch lub więcej kandydatów uzyskało tę samą, najwyższą liczbę głosów, to wybory wygrywa ten z nich, który ma niższy numer.

### Wejście

W pierwszej linii wejścia znajdują się dwie liczby całkowite `M` i `N` (`1 <= M <= 10`, `1 <= N <= 1000`), określające odpowiednio liczbę kandydatów i liczbę oddanych głosów. W drugiej linii znajduje się `N` liczb całkowitych z zakresu od `1` do `M`. Są to numery kandydatów, na których oddane zostały poszczególne głosy.

### Wyjście

W pierwszych `M` liniach wyjścia należy podać kolejno liczby głosów zdobytych przez kandydatów z numerami od `1` do `M`, w formacie `"X: Y"`, gdzie `X` oznacza numer kandydata, a `Y` - liczbę oddanych na niego głosów. Następnie w osobnej linii należy wypisać numer kandydata, który wygrał wybory.

### Przykład

```
Wejście:
3 10
1 3 2 1 2 3 3 3 2 2 

Wyjście:
1: 2
2: 4
3: 4
2
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
	int m, n, vote, winner, max = -1;
	std::cin >> m >> n;
	int T[m];
	for (int i = 0; i < m; i++){
 		T[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> vote;
		T[vote - 1]++;
	}
	for(int i = 0; i < m; i++) {
		std::cout << i + 1 << ": " << T[i] << std::endl;
		if(T[i] > max) {
			max = T[i];
			winner = i + 1;
		}
	}
	std::cout << winner;	
	return 0;
}
```