# Zadanie Rok przestępny (ppr4a)

Napisz program, który sprawdzi czy podany rok jest rokiem przestępnym. Rok przestępny (liczbowo) spełnia następujące warunki: jest podzielny przez `4`, ale nie jest podzielny przez `100`; lub jest podzielny przez `400`.

### Wejście

Wejście składa się z jednej linii, zawierającej rok.

### Wyjście

Należy wypisać napis `'Yes'`, jeżeli rok jest przestępny lub napis `'No'` w przeciwnym przypadku.

### Przykład

```
Wejście:
2004

Wyjście: 
Yes
```

```
Wejście:
2013

Wyjście: 
No
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int year;
    std::cin >> year;
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
    return 0;
}
```