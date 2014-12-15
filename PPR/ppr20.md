# Zadanie Podejrzana karteczka (ppr20)

Detektyw Paul Drake, prowadząc przeszukanie w mieszkaniu zatrzymanego przemytnika, znalazł pod dywanem karteczkę zapisaną dziwnymi symbolami. Podejrzewa, że może to być zaszyfrowana wiadomość dotycząca miejsca przechowywania przemycanego towaru. Zamierza przekazać ją specjalistom od kryptologii, ale postanowił sam przeprowadzić wstępną analizę. Na początek potrzebuje informacji o liczbie liter oraz cyfr w poszczególnych liniach tekstu.

### Wejście

Pierwsza linia wejścia zawiera liczbę naturalną `n` (`1 <= n <= 10`), mówiącą, ile linii tekstu znajduje się na znalezionej karteczce. Następnie podane są kolejno te linie. Każda z nich może zawierać małe i duże litery alfabetu angielskiego, cyfry, znaki interpunkcyjne oraz spacje. Długość każdej linii wynosi co najmniej `1` i co najwyżej `30` znaków.

### Wyjście

Dla każdej linii tekstu wypisz oddzielone spacjami trzy liczby, oznaczające kolejno liczbę wszystkich znaków w tej linii, liczbę zawartych w niej liter oraz liczbę cyfr.

### Przykład

```
Wejście:
2
Poczatek
23572,asd,329956!!!
 
Wyjście:
8 8 0
19 3 11
```

### Rozwiązanie

```cpp
#include <iostream>

int countAlp(std::string);
int countNum(std::string);

int main() {
	int n;
	std::string line;
	std::cin >> n;
	std::cin.ignore();
	while(n--) {
		std::getline(std::cin, line);
		std::cout << line.length() << " " << countAlp(line) << " " << countNum(line) << std::endl;
	}
	return 0;
}

int countAlp(std::string s) {
	int result = 0;
	for(int i = 0; i < s.length(); i++) {
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
			result++;
		}
	}
	return result;
}

int countNum(std::string s) {
	int result = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			result++;
		}
	}
	return result;
}
```