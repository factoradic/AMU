# Zadanie Rzutka gra 2 (ppr6)

Pan Jan pracujący w wesołym miasteczku wymyślił bardzo ciekawą grę. Ustawił tarczę w kształcie "linijki", na której były zapisane od lewej do prawej liczby od `1` do `10000`. Gdy ktoś chciał zagrać w grę, Pan Jan losował dwie liczby `x` i `y` (`x <= y`), a celem gracza było trafienie lotką w jakąś liczbę pomiędzy tymi dwoma. Jeśli gracz trafił w cel, wówczas Pan Jan krzyczał `"BINGO"` i wręczał nagrodę. Jeśli cel nie został osiągnięty, wówczas Pan Jan przyznawał graczowi tyle punktów karnych, ile wynosiła odległość od tego celu.

Do celu rzucało się pewną określoną liczbę razy. W przypadku gdy nie trafiło się w określony cel, liczba punktów karnych się kumulowała (wartości były do siebie dodawane), natomiast w momencie, w którym trafiło się w cel, liczba punktów była zerowana.

Napisz program komputerowy, który pomoże Panu Janowi obsługiwać tę grę i zliczać punkty karne.

### Wejście

Pierwsza linia wejścia zawiera dwie liczby całkowite `x` i `y` (`1 <= x <= y <= 10000`), które oznaczają początek i koniec przedziału, w który należy celować.  W drugiej linii znajduje się liczba `n` (`1 <= n <= 100`) - liczba rzutów oddawanych przez gracza. Trzecia linia zawiera `n` liczb opisujących kolejne trafienia.

### Wyjście

Na wyjściu powinna znajdować się jedna liczba całkowita oznaczająca liczbę punktów karnych na koniec gry.

**Uwaga**: Granice przedziałów należą również do celu.

### Przykład

```
Wejście:
4 8
7
1 2 3 4 5 6 7

Wyjście:
0
```

```
Wejście:
4 8
7
7 6 5 4 3 2 1

Wyjście:
6
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int x, y, numberOfThrows, hit, points = 0;
    std::cin >> x >> y;
    std::cin >> numberOfThrows;
    
    for(int i = 0; i < numberOfThrows; i++) {
        std::cin >> hit;
        if(hit <= y && hit >= x) {
            points = 0;
        } else if(hit < x) {
            points += x - hit;
        } else {
            points += hit - y;
        }
    }
    
    std::cout << points;
    return 0;
}
```