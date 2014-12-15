# Zadanie Od A do B (ppr6a)

Zenek i Gienek dla zabicia czasu wymyślili prostą grę: jeden z nich podaje dwie liczby całkowite `A` i `B` oraz znak oznaczający co należy zrobić z liczbami z podanego przedziału. Znak `'+'` oznacza, że liczby należy dodawać, znak `'-'`, że odejmować, a `'*'`, że mnożyć. Drugi gracz musi podać odpowiednio sumę, różnicę lub iloczyn liczb od mniejszej do większej (liczby `A` i `B` należy uwzględnić w obliczeniach).

Dodatkowo gracze przyjeli, że jeżeli liczby `A` i `B` będą identyczne, to nie należy podawać żadnego wyniku. Dla sprawdzania swojej czujności powiedzieli również, że liczba `A` wcale nie musi być mniejsza niż `B` i gracz musi sobie w razie potrzeby sam je przestawić!

Napisz symulator ich gry.

### Wejście:

W pierwszej lini wejścia znajduje się liczba `n` (`1 <= n <= 1000`) oznaczająca liczbę rozgrywanych gier.

Każda z `n` następnych linii wejścia składa się z dwóch liczb `A` i `B` (`-1000 <= A, B <= 1000`) oraz znaku `'+'`, `'-'` lub `'*'`.

### Wyjście:

Jeżeli na wejściu pojawił się znak `'+'`, należy wypisać sumę liczb od `A` do `B`, jeżeli `'-'`, należy wypisać różnicę, a jeżeli `'*'` to iloczyn. Jeżeli liczby `A` i `B` są sobie równe, nie należy nic wypisywać.

### Przykład:

```
Wejście:
3
1 3 +
2 4 *
-5 -59 -

Wyjście:
6
24
1760
```

### Rozwiązanie

```cpp
#include <iostream>

void swap(int&, int&);

int main() {
    int a, b, numberOfTests, result;
    char operation;
    std::cin >> numberOfTests;
    for(int i = 0; i < numberOfTests; i++) {
        std::cin >> a >> b >> operation;
        if(a == b) {
            continue;
        } else if(a > b) {
            swap(a, b);
        }
        result = (operation == '*') ? 1 : 0;
        for(int j = a; j <= b; j++) {
            if(operation == '+') {
                result += j;
            } else if(operation == '-') {
                result -= j;
            } else {
                result *= j;
            }
        }
        std::cout << result;
    }
    return 0;
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
```