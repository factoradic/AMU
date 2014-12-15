# Zadanie Spamer (ppr19)

Administratorzy pewnego forum podejrzewają, że jeden z użytkowników jest złośliwym spamerem. Postanowili to sprawdzić, zliczając, ile razy w ustalonym okresie czasu wypowiedział się na forum. Pomóż im w tym zadaniu.

### Wejście

W pierwszej linii wejścia znajduje się liczba całkowita `n` (`1 <= n <= 100`), określająca liczbę postów, które pojawiły się na forum w czasie obserwacji. W kolejnych `n` liniach znajdują się loginy autorów poszczególnych postów. Każdy login jest napisem składającym się z co najmniej jednego i co najwyżej `20` znaków, a ponadto może zawierać wyłącznie małe i duże litery alfabetu angielskiego oraz cyfry. W ostatniej linii znajduje się login użytkownika podejrzanego o bycie spamerem.

### Wyjście

Wypisz liczbę zaobserwowanych postów podejrzanego użytkownika.

### Przykład

```
Wejście:
5
user1
aaa
aaa
student808
x
aaa

Wyjście:
2
```

### Rozwiązanie

```cpp
#include <iostream>

int countOc(std::string[], int, std::string);

int main() {
	int n;
	std::cin >> n;
	std::string arr[n];
	for(int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	std::string spamer;
	std::cin >> spamer;
	std::cout << countOc(arr, n, spamer);
	return 0;
}

int countOc(std::string tab[], int length, std::string s) {
	int result = 0;
	for(int i = 0; i < length; i++) {
		if(tab[i] == s) {
			result++;
		}
	}
	return result;
}
```