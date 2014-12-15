# Zadanie Rytuał (ppr16)

Znany podróżnik Antonio przebywając wśród Indian Ameryki Południowej zapoznał się z rytuałem ułatwiającym szamanom wejście w trans. Szaman zasiada przy ognisku i określa magiczną liczbę x. Następnie, jeśli x jest liczbą parzystą, to szaman dorzuca do ogniska garść kwiatów i dzieli x przez 2. Jeśli natomiast x jest nieparzyste, to do ogniska dorzuca garść liści i oblicza wartość 3x+1. Te operacje należy powtarzać dla otrzymywanych kolejno wartości do czasu kiedy x będzie równe 1.

Antonio zastanawia się, dla jakich wartości x rytuał zostaje zakończony po co najwyżej 15 krokach. Chciałby też wiedzieć, ile kwiatów i liści potrzeba do wprowadzenia szamana w trans. W związku z tym poprosił programistów o zaimplementowanie funkcji, która dla zadanej wartości x odpowie na pytanie, czy rytuał zakończy się po najwyżej 15 krokach, i jeśli tak, to poda także liczbę zużytych garści kwiatów i liści.

### Wejście

Wejście zawiera co najwyżej `20` testów. Każdy test składa się z jednej liczby naturalnej `x` z zakresu od `2` do `100`. Ostatnią liczbą wejścia jest zawsze `0`.

### Wyjście

Dla każdego testu należy w osobnej linii wypisać słowo `"TAK"`, jeśli rytuał zakończy się po co najwyżej `15` krokach, lub `"NIE"` w przeciwnym przypadku. Jeśli odpowiedź brzmi `"TAK"`, należy w tej samej linii wypisać także liczbę zużytych w rytuale garści kwiatów i garści liści.

### Przykład

```
Wejście:
7
10
0

Wyjście:
NIE
TAK 5 1
```

### Rozwiązanie

```cpp
#include <iostream>

bool rytual(int, int&, int&);

int main() {
	int a;
	std::cin >> a;
	while(a != 0) {
		int b = 0, c = 0;
		if(rytual(a, b, c)) {
			std::cout << "TAK " << b << " " << c << std::endl;
		} else {
			std::cout << "NIE" << std::endl;
		}
		std::cin >> a;
	}
	return 0;
}

bool rytual(int x, int& kwiaty, int& liscie) {
	for(int i = 0; i < 15; i++) {
		if(x % 2 == 0) {
			kwiaty++;
			x /= 2;
		} else {
			liscie++;
			x = 3 * x + 1;
		}
		if(x == 1) {
			return true;
		}
	}
	return false;
}
```