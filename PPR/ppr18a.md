# Zadanie Kalkulator z bajerami (ppr18a)

Jaś uczy się języka C. Ostatnio poznał bibliotekę <string.h>. Postanowił napisać program, w którym wykorzysta jej możliwości. Wymyślił sobie, że będzie to rodzaj kalkulatora, ale z bajerami:

jeśli na wejściu będą podane dwie liczby, to program wyliczy ich sumę,

jeśli na wejściu będą podane dwa napisy, to program wyświetli ich konkatenację,

jeśli na wejściu będzie podana liczba K oraz napis S (w dowolnej kolejności), to program wyświetli K-ty znak napisu S.

Pomóż Jasiowi napisać wymyślony przez niego program.
 
### Wejście
 
W pierwszej linii wejścia znajduje się liczba `n` (`1 <= n <= 100`) "zadań" dla kalkulatora, które się za chwilę pojawią.

W każdej z kolejnych `n` linii znajdują się dwie liczby lub dwa napisy, lub liczba i napis, lub napis i liczba.

Żaden z napisów nie zawiera spacji ani cyfr, żaden też nie jest dłuższy niż `10` znaków.

**UWAGA**: Napisy nie zawierają spacji ani cyfr, ale mogą zawierać inne znaki (np. `'?'`, `'&'` czy `'@'`)!

### Wyjście

Wyjście składa sie z `n` linii.

`n`-ta linia zawiera wynik `n`-tego "zadania" (liczbę, napis bądź pojedynczy znak), zgodnie z założeniami podanymi przez Jasia.

### Przykład

```
Wejście
4
kot lina?
1 pies
swinia! 3
5 7

Wyjście 
kotlina?
p
i
12
```

### Wymagania
 
Użyj funkcji z biblioteki `<string.h>`. Do wczytywania i wypisywania użyj funkcji `scanf` i `printf`.

### Rozwiązanie

```cpp
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char isInt(char* str){
    if((strlen(str) > 1 && (str[1] >= '0' && str[1] <= '9')) || (str[0] >= '0' && str[0] <= '9')) {
        return 'i';
    }
    return 's';
}

int main() {
    int n;
    scanf("%d", &n);
    char word1[11], word2[11];
    while(n--) {
        scanf("%s", word1);
        scanf("%s", word2);
        if(isInt(word1) == 'i' && isInt(word2) == 'i') {
            printf("%d\n",  (atoi(word1) + atoi(word2)));
        } else if(isInt(word1) == 'i') {
            printf("%c\n", word2[atoi(word1) - 1]);
        } else if(isInt(word2) == 'i') {
            printf("%c\n", word1[atoi(word2) - 1]);
        } else {
            printf("%s%s\n", word1, word2);
        }
    }
    return 0;
}
```