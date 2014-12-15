# Zadanie Qsort (ppr25)

„Dziwny jest teeen świat…” — leciało właśnie w radiu. „Oj dziwny, dziwny…” — powiedziałem sobie patrząc na czekoladkę, którą dostałem właśnie od mojego wnuczka. „Co to się porobiło…” — mruczałem sobie pod nosem, tak żeby mój kochany Jasio tego nie usłyszał i nie pomyślał sobie, że jestem niezadowolony. Bardzo lubiłem dostawać czekoladki od mojego wnuczka. A lubiłem dlatego, że lubiłem wnuczka, a nie czekoladki. Ale nigdy nie miałem serca powiedzieć mu o tym — „często jest, że ktoś słowem złym zabija tak jak nożem”. Oglądałem uważnie każdą czekoladkę, którą dostawałem od mojego kochanego Jasia. Nigdy jeszcze żadnej nie zjadłem. Ale każdą dokładnie oglądałem z zaciekawieniem. Głównie dlatego, że prawie każda była inna. „Za moich czasów… ech… czekolada to była czekolada. Prostokąt, wyraźnie zarysowane kostki” — tak sobie marudziłem, ze starego przyzwyczajenia marudzenia na wszystko, na co tylko się da. W rzeczywistości fascynowała mnie różnorodność kształtu, formy, koloru…. wszystko za każdym razem było inne. Każdą nową czekoladkę od mojego Jasia wkładałem do specjalnej szafki, gdzie trzymałem wszystkie, które dostałem od niego. „Z tą też tak zrobię” — powziąłem postanowienie. Otworzyłem szafkę. Ale… „Przyszedł już czas, najwyższy czas” — „Dobrze prawi” — pomyślałem. Najwyższy czas zrobić porządek w szafce. W mig pojawiła się myśl — „Uporządkuję czekoladki tak, żeby na dole były te o największej liczbie kostek, a im wyżej, tym będą mniejsze”. Ale znowu ale… oczy już nie te. „Miniaturyzacja świata jest na pewno oszczędnościową akcją wymierzoną przeciwko emerytom!”. Co teraz? Przecież nie mogę poprosić Jasia o pomoc… „Lecz ludzi dobrej woli jest więcej” —  „Dobrze prawi. Zwrócę się o pomoc do syna”. Ale syn mój strasznym jest pracoholikiem. Cały czas spędza przy komputerze. Na moją prośbę odburknął tylko niezadowolony, że mu przeszkadzam „napiszę Ci program, ok?”. „OK” powiedziałem i zadowolony z użycia tego jakże młodzieżowego słowa wróciłem na swój fotel czekając na program.

Syn okazał się jednak bardzo zajęty i nie miał czasu napisać tego programu. Zlecił mejlem napisanie go właśnie Tobie. Zadaniem jest więc napisanie programu, który dostając na wejściu rozmiary czekoladek (liczby kostek, z których się składają), na wyjściu wypisze kolejność w jakiej trzeba je odkładać do szafki, od największej do najmniejszej.

Ponieważ Ty też nie za bardzo umiesz to zadanie zrobić, to ów syn podpowiedział Ci, że do jego rozwiązania można użyć funkcji qsort. Jeszcze nie wiesz co to znaczy, ale od tego już jest wujek google ;)

### Wejście

Pierwsza linia wejścia zawiera liczbę całkowitą `D` (`1 <= D <= 50`), oznaczającą liczbę zestawów danych. Każdy zestaw składa się z dwóch linii. W pierwszej znajduje się liczba `N` — liczba czekoladek, które były w szafce (`1 <= N <= 100`). W drugiej linii znajduje się N dodatnich liczb całkowitych oddzielonych spacjami, oznaczających wielkości kolejnych czekoladek, z których każda jest niewiększa niż `10000`.

### Wyjście

Wyjście zawiera dokładnie `D` linii. Dla każdego zestawu należy najpierw wypisać, jakiej wielkości czekoladki trzeba wkładać po kolei do szafki.

### Przykład

```
Wejście
2
4
1 2 3 4
10
9 2 34 1 2 3 4 1 12 3

Wyjście
4 3 2 1
34 12 9 4 3 3 2 2 1 1
```

### Rozwiązanie

```cpp
#include <iostream>
#include <cstdlib>

int reversed_order_int(const void*, const void*);

int main() {
	int D;
	std::cin >> D;
	while(D--) {
		int n;
		std::cin >> n;
		int *czekoladki = new int[n];
		for(int i = 0; i < n; i++) {
			std::cin >> czekoladki[i];
		}
		qsort(czekoladki, n, sizeof(int), reversed_order_int);
		for(int i = 0; i < n; i++) {
			std::cout << czekoladki[i] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

int reversed_order_int(const void * a, const void * b) {
	if (*(int*)a < *(int*)b) return 1;
	if (*(int*)a == *(int*)b) return 0;
	if (*(int*)a > *(int*)b) return -1;
}
```