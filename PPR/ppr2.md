# Zadanie Monolit (ppr2)

Andrzej dostał w prezencie grę planszową inspirowaną znaną powieścią fantastyczno-naukową. W skład zestawu do gry wchodzą między innymi figurki do własnoręcznego pomalowania. Andrzej planuje zacząć malowanie od figurki w kształcie prostopadłościanu, przedstawiającej olbrzymi monolit. Aby dowiedzieć się, ile farby potrzebuje, musi obliczyć pole powierzchni tej figurki.

### Wejście

Wejście składa się z jednej linii, zawierającej oddzielone pojedynczymi spacjami trzy liczby całkowite `A`, `B`, `C`, oznaczające odpowiednio długość, szerokość i wysokość figurki (`0 < A, B, C < 10000`).

### Wyjście

Należy wypisać jedną liczbę całkowitą, określającą pole powierzchni figurki monolitu.

### Przykład

```
Wejście:
10 10 10

Wyjście: 
600
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << 2 * a * b + 2 * a * c + 2 * b * c;
	return 0;
}
```