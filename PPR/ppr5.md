# Zadanie Ciągi liczb (ppr5)

Napisz program, który wypisze wszystkie liczby parzyste lub nieparzyste z danego przedziału.

### Wejście

Wejście składa się z dwóch linii. Pierwsza zawiera dwie liczby całkowite `x` i `y` (`1 <= x <= y <= 10000`), które oznaczają początek i koniec przedziału, z którego należy wypisać liczby.

W drugiej linii znajduje się jedna litera: `'p'` lub `'n'`, która oznacza, czy program ma wypisywać odpowiednio liczby parzyste, czy nieparzyste.

### Wyjście

Na wyjściu, w jednej linii, ma znajdować się ciąg parzystych lub nieparzystych liczb z danego przedziału, wypisanych w kolejności rosnącej.

**Uwaga**: Granice przedziału należą również do przedziału.

### Przykład

```
Wejście:
4 8
p

Wyjście:
4 6 8
```

```
Wejście:
4 8
n

Wyjście:
5 7
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int x, y;
    char mode;
    std::cin >> x >> y >> mode;
    if((mode == 'p' && x % 2 == 1) || (mode == 'n' && x % 2 == 0)) {
        x++;
    }
    for(int i = x; i <= y; i += 2) {
        std::cout << i << " ";
    }
    return 0;
}
```