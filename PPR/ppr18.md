# Zadanie Palindromy (ppr18)

Palindromem nazywamy słowo, które wygląda tak samo pisane od lewej do prawej i od prawej do lewej. Napisz program rozpoznający palindromy.

### Wejście

W pierwszej linii wejścia znajduje się liczba `n` (`1 <= n <= 10`) testowanych słów. W kolejnych `n` liniach podane są słowa, składające się z małych liter alfabetu angielskiego. Długość żadnego słowa nie przekracza `30` znaków.

### Wyjście

Dla każdego wczytanego słowa, w osobnej linii, wypisz najpierw to słowo, a potem symbol `"=="`, jeśli to słowo jest palindromem, lub `"!="`, jeśli nie jest palindromem. Następnie wypisz wczytane słowo zapisane od końca.

### Przykład

```
Wejście:
2
abcddc
ababa

Wyjście:
abcddc!=cddcba
ababa==ababa
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	while(n--) {
		std::cin.clear();
		std::string paragraph;
		std::cin >> paragraph;
		std::string reversed = std::string(paragraph.rbegin(), paragraph.rend());
		std::cout << paragraph << (paragraph == reversed ? "==" : "!=") << reversed << std::endl;
	}
    return 0;
}
```