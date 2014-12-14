# Zadanie Big boom! (ppr10a)

Napisz program, który dla `N` przykładów wypisze napis `"BIG BOOM!"` z zadaną liczbą zanaków `"I"`, `"O"` oraz `"!"`.

### Wejście

Wejście składa się z liczby `N` (`1 <= N <= 100`) oraz z `N` liczb określających liczbę liter `"I"`, `"O"` oraz `"!"`.

### Wyjście

Na wyjściu należy wypisać `N` razy napis `"BIG BOOM!"`, w którym znaki `"I"`, `"O"` oraz `"!"` będą powtórzone `M` razy.

### Przykład

```
Wejście:
3
2 4 6

Wyjście:
BIIG BOOM!!
BIIIIG BOOOOM!!!!
BIIIIIIG BOOOOOOM!!!!!!
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
	int n, count;
	std::cin >> n;
	while(n--) {
		std::cin >> count;
		std::string word = "B";
		for(int i = 0; i < count; i++) {
			word += "I";
		}
		word += "G B";
		for(int i = 0; i < count; i++) {
			word += "O";
		}
		word += "M";
		for(int i = 0; i < count; i++) {
			word += "!";
		}
		std::cout << word << std::endl;
	}
	return 0;
}
```