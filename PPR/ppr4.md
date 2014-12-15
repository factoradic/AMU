# Zadanie Rzutka gra (ppr4)

Pan Jan pracujący w wesołym miasteczku wymyślił bardzo ciekawą grę. Ustawił tarczę w kształcie "linijki", na której były zapisane od lewej do prawej liczby od `1` do `10000`. Gdy ktoś chciał zagrać w grę, Pan Jan losował dwie liczby `x` i `y` (`x <= y`), a celem gracza było trafienie lotką w jakąś liczbę pomiędzy tymi dwoma. Jeśli gracz trafił w cel, wówczas Pan Jan krzyczał `"BINGO"` i wręczał nagrodę. Jeśli cel nie został osiągnięty, wówczas Pan Jan przyznawał graczowi tyle punktów karnych, ile wynosiła odległość od tego celu (na pocieszenie, gdyż w praktyce nie miało to żadnego znaczenia).

Napisz program komputerowy, który pomoże Panu Janowi obsługiwać tę grę.

### Wejście

Wejście składa się z dwóch linii. Pierwsza zawiera dwie liczby całkowite `x` i `y` (`1 <= x <= y <= 10000`), które oznaczają początek i koniec przedziału, w który należy celować. W drugiej linii znajduje się jedna liczba oznaczająca miejsce, w które trafił gracz.

### Wyjście

Jeśli gracz trafił w cel, należy wypisać słowo `"BINGO"`. Jeśli gracz chybił, należy wypisać liczbę zdobytych przez niego punktów karnych (odległość od celu).

**Uwaga**: Granice przedziałów należą również do celu - patrz przykład `3`.

### Przykład

```
Wejście:
4 8
7

Wyjście:
BINGO
```

```
Wejście:
4 8
12

Wyjście:
4
```

```
Wejście:
4 8
8

Wyjście:
BINGO
```

### Rozwiązanie

```cpp
#include <iostream>

int main() {
    int x, y, hit;
    std::cin >> x >> y;
    std::cin >> hit;
    if(hit <= y && hit >= x) {
        std::cout << "BINGO";
    } else if(hit < x) {
        std::cout << x - hit;
    } else {
        std::cout << hit - y;
    }
    return 0;
}
```