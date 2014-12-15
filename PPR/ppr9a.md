# Zadanie Obracanie tablicy w lewo (ppr9a)

Dana jest tablica liczb całkowitych składająca się z `N` wierszy i `M` kolumn. Wypisz tablicę liczb, która powstanie po obróceniu wejściowej tablicy o 90 stopni w lewo (ostatnia kolumna staje się pierwszym wierszem, przedostatnia kolumna - drugim wierszem, i tak dalej: pierwsza kolumna staje się ostatnim wierszem).

### Wejście

W pierwszej linii wejścia znajdują się dwie liczby całkowite `N` i `M` (`2 <= N`, `M <= 100`), oznaczające liczbę wierszy i kolumn w tablicy. Każda z następnych `N` linii zawiera `M` liczb całkowitych z zakresu od `0` do `99` oddzielonych spacjami.

### Wyjście

Na wyjściu należy wypisać tablicę, która powstanie po obróceniu o 90 stopni w lewo tablicy wejściowej.

### Przykład

```
Wejście:
3 4
1 2 3 4
5 6 7 8
9 10 11 12

Wyjście:
4 8 12
3 7 11
2 6 10
1 5 9
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int n, m, number;
    std::cin >> n >> m;
    int T[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> number;
            T[i][j] = number;
        }
    }
    for(int i = m - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            std::cout << T[j][i] << " ";
        }
        std::cout << std::endl;
    }   
    return 0;
}
```