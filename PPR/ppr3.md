# Zadanie Bilety (ppr3)

Grupa studentów wybrała się do kina. Niestety, nie wszyscy pamiętali o zabraniu legitymacji studenckich, przez co tylko U osób mogło kupić bilety ulgowe, a pozostałe N osób musiało kupić bilety normalne. W sumie wszystkie bilety kosztowały S złotych. Wiedząc, że cena każdego biletu wyraża się całkowitą liczbą groszy, a bilet ulgowy jest dokładnie dwa razy tańszy od normalnego, oblicz cenę normalnego biletu do kina.

### Wejście

Wejście składa się z jednej linii, zawierającej oddzielone pojedynczymi spacjami trzy liczby całkowite `U`, `N`, `S` (`1 < U, N < 100`, `0 < S < 10000`).

### Wyjście

Należy wypisać cenę biletu normalnego w złotych, z dokładnie dwiema cyframi po kropce dziesiętnej.

### Przykład

```
Wejście:
4 2 102

Wyjście: 
25.50
```

### Rozwiązanie

```cpp
#include <iostream>
#include <iomanip> 

int main() {
	float u, n, s;
	std::cin >> u >> n >> s;
	std::cout << std::fixed << std::setprecision(2) << s / (u / 2 + n);
	return 0;
}
```