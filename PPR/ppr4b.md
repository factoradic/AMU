# Zadanie Starsza data (ppr4b)

Są dane dwie daty, każda w postaci trzech liczb całkowitych. Napisz program, który wskaże starszą datę.

### Wejście

Wejście składa się z dwóch linii, każda zawiera datę w postaci trzech liczb całkowitych, odpowiadających za rok, miesiąc i dzień.

### Wyjście

Należy wypisać starszą datę.

### Przykład

```
Wejście:
2013 10 3
2012 10 1

Wyjście: 
2012 10 1
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int y1, y2, m1, m2, d1, d2;
    std::cin >> y1 >> m1 >> d1;
    std::cin >> y2 >> m2 >> d2;
    if(y1 * 10000 + m1 * 100 + d1 < y2 * 10000 + m2 * 100 + d2) {
        std::cout << y1 << " " << m1 << " " << d1;
    } else {
        std::cout << y2 << " " << m2 << " " << d2;
    }
    return 0;
}
```