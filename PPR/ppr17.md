# Zadanie Liczba Roku (ppr17)

Naukowcy z całego świata postanowili wybrać Liczbę Roku 2012. Ustalili, że wybór odpowiedniej liczby powinien mieć coś wspólnego z podzielnością. Stworzyli długą listę liczb, które ich zdaniem byłyby dobrymi kandydatami na dzielniki Liczby Roku. Ponieważ każdy naukowiec dopisywał swoje liczby nie oglądając się na innych, na liście tej mogą występować powtórzenia. Wydawałoby się, że wybór Liczby Roku powinien być teraz łatwy, ale doradcy do spraw PR doszli do wniosku, że przyjęcie bardzo dużej wartości byłoby niekorzystne. Naukowcy muszą wybrać liczbę nie większą niż milion. Rozważają kandydatury różnych ciekawych liczb i dla każdej z nich chcą się dowiedzieć, ile liczb z przygotowanej listy jest jej dzielnikami.

### Wejście

W pierwszej linii wejścia znajduje się liczba naturalna `n` (`1 <= n <= 200000`), określająca długość listy potencjalnych dzielników Liczby Roku 2012. W kolejnej linii podane są elementy tej listy, będące liczbami naturalnymi z zakresu od `1` do `1000`. W trzeciej linii znajduje się liczba naturalna m (`1 <= m <= 10`), oznaczająca liczbę rozważanych kandydatów na Liczbę Roku. W kolejnych `m` liniach znajdują się te liczby (całkowite, z zakresu od `1` do `1000000`).

### Wyjście

Dla każdego kandydata na Liczbę Roku wypisz w osobnej linii, ile liczb z listy przygotowanej przez naukowców jest jego dzielnikami.

### Przykład

```
Wejście:
5
2 1 7 3 2
2
8
11

Wyjście:
3
1
```

### Rozwiązanie

```cpp
#include <iostream>

int countDivisible(int[], int, int);

int main() {
	int n, m;
	std::cin >> n;
	int T[n];
	for(int i = 0; i < n; i++) {
		std::cin >> T[i];
	}
	std::cin >> m;
	while(m--) {
		int cand;
		std::cin >> cand;
		std::cout << countDivisible(T, n, cand) << std::endl;
	}
	return 0;
}

int countDivisible(int arr[], int length, int div) {
	int result = 0;
	for(int i = 0; i < length; i++) {
		if(div % arr[i] == 0) {
			result++;
		}
	}
	return result;
}
```