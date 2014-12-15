# Zadanie Średnie (ppr10)

Studenci w toku swoich studiów otrzymują pewne oceny. Zdarzają się w trakcie studiowania takie momenty, kiedy z pewnych względów potrzebna jest średnia ocen lub lista wszystkich dotychczas otrzymanych ocen.

Napisz program, który będzie wczytywał kolejne oceny otrzymywane przez studenta (od `2` do `5` - zakładamy, że nie ma połówek), a dla podanych poniżej wartości będzie wykonywał następujące akcje:

- `1`: wypisanie na wyjściu średniej dotychczas otrzymanych ocen, z dokładnością do dwóch miejsc po przecinku,
- `0`: wypisanie na wyjściu w jednej linii wszystkich dotychczas otrzymanych ocen w kolejności ich otrzymywania,
- `-1`: zakończenie studiów (koniec działania programu).

### Wejście

Wejście składa się z ciągu liczb całkowitych. Każda liczba przyjmuje wartość od `-1` do `5`, gdzie liczby od `2` do `5` oznaczają oceny otrzymane przez studenta, a znaczenie liczb `1`, `0` i `-1` opisano w treści zadania.

Na wejściu nie pojawi się więcej niż `1010` liczb.

### Wyjście

Na wyjściu należy dla każdej wartości `0` lub `1` wypisać w osobnej linii wartości określone w treści zadania.

### Przykład

```
Wejście:

5 5 4 4 1 5 5 0 4 4 1 0 1 5 4 3 2 1 0 -1

Wyjście:

4.50
5 5 4 4 5 5
4.50
5 5 4 4 5 5 4 4
4.50
4.17
5 5 4 4 5 5 4 4 5 4 3 2
```

### Rozwiązanie

```cpp
#include <iostream>
#include <iomanip>

int T[1010], counter = 0;

void print_grades() {
	for(int i=0; i < counter; i++) {
		std::cout << T[i] << " ";
	}
	std::cout << std::endl;
}

float avg_grades() {
    int s = 0;
	for(int i = 0; i < counter; i++) {
	   s += T[i];
    }
	return (float)s / counter;
}

void add_grade(int grade) {
    T[counter] = grade;
    counter++;
}

int main() {
	int x;
    std::cin >> x;
	while(x != -1) {
		if(x == 1){
			std::cout << std::fixed << std::setprecision(2) << avg_grades() << std::endl;
		} else if(x == 0) {
			print_grades();
		} else {
            add_grade(x);
        }
        std::cin >> x;
	}
    return 0;
}
```