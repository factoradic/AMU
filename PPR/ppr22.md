# Zadanie Słownik delfinów (ppr22)

Długoletnie badania nad intelektem i mową delfinów przyniosły wreszcie rezultaty. Naukowcom udało się ustalić reguły zapisu delfinich słów za pomocą liter alfabetu angielskiego oraz zanotować wiele powszechnie używanych przez delfiny wyrazów. Napisz program, który posortuje te słowa alfabetycznie, ułatwiając tworzenie słownika delfinów.

### Wejście

Pierwsza linia wejścia zawiera liczbę całkowitą `n` (`1 <= n <= 1000`), oznaczającą liczbę słów zarejestrowanych przez naukowców. W kolejnych n liniach podane są te słowa. Każde z nich składa się z co najmniej jednej i co najwyżej 20 małych liter alfabetu angielskiego.

### Wyjście

Wypisz w osobnych liniach wszystkie znane słowa języka delfinów, posortowane alfabetycznie (UWAGA! łańcuch `"a"` jest "mniejszy" niż łańcuch `"ab"`).

### Przykład

```
Wejście:
5
afdg
sspade
trekk
bbre
lol

Wyjście:
afdg
bbre
lol
sspade
trekk
```

```
Wejście:
2
abc
a

Wyjście:
a
abc
```

### Rozwiązanie

```cpp
#include <iostream>
#include <cstdlib>
#include <string>

void merge(std::string toSort[], std::string helper[], int l, int m, int r);
void mergeSort(std::string toSort[], std::string helper[], int p, int k);

int main() {
	int n;
	std::cin >> n;
	std::string *words = new std::string[n];
	for(int i = 0; i < n; i++) {
		std::cin >> words[i];
	}
	std::string *pom = new std::string[n];
	mergeSort(words, pom, 0, n - 1);
	for(int i = 0; i < n; i++) {
		std::cout << words[i] << std::endl;
	}
	return 0;
}

void merge(std::string toSort[], std::string helper[], int l, int m, int r) {
	int i = l,
        j = m,
        k = l;
    while(i < m && j <= r) {
        if(toSort[i] <= toSort[j]) {
            helper[k++] = toSort[i++];
        } else {
            helper[k++] = toSort[j++];
        }
    }
    while(i < m) {
        helper[k++] = toSort[i++];
    }
    while(j <= r) {
        helper[k++] = toSort[j++];
    }
    for(i = l; i <= r; i++) {
        toSort[i] = helper[i];
    }
}

void mergeSort(std::string toSort[], std::string helper[], int p, int k) {
    int inversions = 0;
    if(k > p) {
        int q = (k + p) / 2;
        mergeSort(toSort, helper, p, q);
        mergeSort(toSort, helper, q + 1, k);
        merge(toSort, helper, p, q + 1, k);
    }
}
```