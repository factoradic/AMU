# Zadanie Kalkulator (ppr21)

Początkujący programista Marcin postanowił zaimplementować zaawansowany kalkulator, obsługujący niezwykle skomplikowane funkcje dwóch zmiennych. Na początek chce jednak sprawdzić swoje umiejętności pisząc program kalkulatora obsługującego tylko trzy najprostsze działania na liczbach całkowitych (zwykle kalkulatory obsługują co najmniej cztery działania, ale Marcin wciąż nie może się zdecydować, w jaki sposób karać użytkowników próbujących dzielić przez zero). Pomóż mu w tym zadaniu.

### Wejście

W pierwszej linii wejścia znajduje się liczba naturalna `n` (`1 <= n <= 20`) oznaczająca liczbę działań do wykonania. W kolejnych liniach opisane są te działania, w postaci `"a op b"`, gdzie `a` i `b` są liczbami całkowitymi z zakresu od `-1000` do `1000`, a `op` jest jednym ze znaków: `+`, `-` lub `*`.

### Wyjście

Dla każdego zadanego działania wypisz w osobnej linii jego wynik.

### Przykład

```
Wejście:
3
13 + -10
2 * 5
7 - 18

Wyjście:
3
10
-11
```

### Rozwiązanie

```cpp
#include <iostream>

int add(int, int);
int sub(int, int);
int mul(int, int);
void printResult(int (*)(int, int), int, int);

int main() {
	int n, a, b;
	char op;
	std::cin >> n;
	while(n--) {
		std::cin >> a >> op >> b;
		if(op == '+') printResult(add, a, b);
		if(op == '-') printResult(sub, a, b);
		if(op == '*') printResult(mul, a, b);
	}
	return 0;
}

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}

void printResult(int (*f)(int, int), int a, int b) {
	std::cout << f(a, b) << std::endl;
}
```