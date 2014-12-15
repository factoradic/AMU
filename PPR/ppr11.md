# Zadanie Suma NWD (ppr11)

Dany jest następujący problem: pewien generator wyrzuca z siebie ciąg losowych liczb naturalnych. Co jakiś czas na wejściu pojawia się liczba `1`. Należy wówczas wyliczyć największy wspólny dzielnik dwóch ostatnich liczb większych od `1`, aby na końcu móc podać sumę wszystkich obliczonych w ten sposób wartości. Gdy na wejściu pojawia się `0`, oznacza to, że generator zakończył swe działanie.

### Wejście

Wejście składa się z ciągu liczb całkowitych. Każda liczba przyjmuje wartość od `0` do `30000`, gdzie liczby od `2` do `30000` oznaczają kolejne wartości dane przez generator, liczba `1` oznacza rozkaz wyznaczenia `NWD` ostatnich dwóch liczb większych od `1`, a `0` jest zawsze ostatnią liczbą pojawiającą się na wejściu.
Dwie pierwsze liczby są zawsze większe od `1` (czyli liczb na wejściu jest co najmniej `3`).
Na wejściu nie pojawi się więcej niż `1 000 000 000` liczb.

### Wyjście

Na wyjściu należy wypisać jedną liczbę całkowitą, która oznacza sumę wszystkich wyznaczonych największych wspólnych dzielników.

### Przykład

```
Wejście:
5 5 4 4 1 5 5 1 4 4 1 1 1 5 4 3 2 1 0

Wyjście:
22
```

### Rozwiązanie

```cpp
#include <iostream>

int NWD(int, int);

int main() {
	int a, b, c, sum = 0;
	std::cin >> a >> b >> c;
    while(c != 0) {
        if(c == 1) {
            sum += NWD(a, b);
            std::cin >> c;
            continue;
        }
        a = b;
        b = c;
        std::cin >> c;
    }
    std::cout << sum;
    return 0;
}

int NWD(int a, int b) {
	int c;
	while(b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
```