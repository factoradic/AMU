# Zadanie Loteria (ppr23)

W miasteczku Macondo co tydzień odbywa się loteria z cennymi nagrodami. Sprzedawane losy mają przypisane numery od `1` do `100 000 000`. Losowany jest tylko jeden zwycięski kupon. Niektórzy mieszkańcy podejrzewają, że maszyna losująca nie jest do końca uczciwa i pewne numery mają większe szanse na wygraną. Sprawdź, czy wyniki dotychczasowych losowań wskazują na taką możliwość.

### Wejście

Pierwsza linia wejścia zawiera liczbę `n` (`1 <= n <= 100 000`) dotychczasowych losowań. W kolejnych `n` liniach podane są numery kuponów, które wygrały w poszczególnych losowaniach (liczby całkowite z zakresu od `1` do `100 000 000`).

### Wyjście 

Wypisz posortowane rosnąco numery, które zostały wylosowane więcej niż jeden raz.

### Przykład

```
Wejście:
7
1
3
8
3
1
3
1004

Wyjście:
1
3
```

### Rozwiązanie

```cpp
#include <iostream>
 
void q_sort(int tab[], int left, int right);
 
int main() {
    int n;
    std::cin >> n;
    int *kupony = new int[n];
    for(int i = 0; i < n; i++) {
        std::cin >> kupony[i];
    }
    q_sort(kupony, 0, n - 1);
    for(int i = 1; i < n; i++) {
        if((kupony[i] == kupony[i - 1]) && (i + 1 == n || kupony[i] != kupony[i + 1]))  {
            std::cout << kupony[i] << std::endl;
        }
    }
    return 0;
}
 
void q_sort(int tab[], int left, int right) {
    int i = left;
    int j = right;
    int x = tab[( left + right ) / 2 ];
    do {
        while(tab[i] < x)
        i++;
        while(tab[j] > x)
            j--;
        if(i <= j) {
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
            j--;
        }
    } while(i <= j);    
    if(left < j) q_sort(tab, left, j);
    if(right > i) q_sort(tab, i, right);
}
```