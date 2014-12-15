# Zadanie Zlicz największą (ppr_intro_12)

Napisz program, który wczyta `N` liczb całkowitych i wypisze ile razy pojawiła się największa z nich.

### Wejście

W pierwszej linii wejścia znajduje się liczba `N` (`1 <= N <= 1000`) oznaczająca ilość kolejnych liczb na wejściu do wczytania.

### Wyjście

Wyjście składa się z liczby wystąpień największej z podanych liczb.

### Przykład

```
Wejście
6
1 4 2 5 3 5

Wyjście
2
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int n, number, counter = 1, max;
    std::cin >> n;
    std::cin >> number;
    max = number;
    for(int i = 1; i < n; i++) {
        std::cin >> number;
        if(number > max) {
            max = number;
            counter = 1;
        } else if (number == max) {
            counter++;
        }
    }
    std::cout << counter;
    return 0;
}
```