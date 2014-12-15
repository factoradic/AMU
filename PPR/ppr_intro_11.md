# Zadanie Średnia bez zera (ppr_intro_11)

Napisz program, który będzie wczytywał liczby całkowite, aż do wystąpienia liczby 0 i wypisze ich średnią arytmetyczną z dokładnością do dwóch miejsc po przecinku.

### Wejście

Na wejściu pojawiają się liczby całkowite różne od zera, a ostatnią liczbą jest `0`. Liczb nie będzie więcej niż `1010`.

### Wyjście

Pojedyncza liczba będąca średnią arytmetyczną liczb z wejścia.

### Przykład

```
Wejście
1 2 3 4 0

Wyjście
2.50
```

### Rozwiązanie

```cpp
#include <iostream>
#include <iomanip> 

int main() {
    int i = 0, number, sum = 0;
    std::cin >> number;
    while(number != 0) {
        i++;
        sum += number;
        std::cin >> number;
    }
	std::cout << std::fixed << std::setprecision(2) << float(sum) / i;
    return 0;
}
```