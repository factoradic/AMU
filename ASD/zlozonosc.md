# Obliczanie / dowodzenie złożoności

*Obliczanie złożoności jest bardzo proste, wymaga jedynie umiejętności korzystania z twierdzenia o rekurencji. Wiem, że wszyscy potraficie czytać!*

*Dowodzenie złożoności może być trochę bardziej problematyczne, ponieważ definicji naszych trzech notacji musicie po prostu nauczyć się na pamięć. We wszystkich poprzednich kolokwiach występowały zadania z notacją theta, ale na wszelki wypadek dobrze jest przygotować się z całości.*

### 1. Dowodzenie złożoności z definicji

> Korzystając z definicji sprawdź czy prawdziwe jest oszacowanie: `4n^2 + 4n + 4 = Θ(n^2)`.

##### Etap pierwszy (przypomnienie definicji)

> Dla danej funkji `g(n)` oznaczamy przez `Θ(g(n))` zbiór wszystkich takich funkcji f (n), dla których istnieją dodatnie stałe `c1`, `c2`, `n0`, takie że dla wszystkich `n ≥ n0`:
```
0 ≤ c1 * g(n) ≤ f(n) ≤ c2 * g(n)
```

> Jeśli `f(n) = Θ(g(n))`, to mówimy, że `g(n)` jest asymptotycznym, dokładnym oszacowaniem funkcji `f(n)`.

##### Etap drugi (podstawienie zmiennych)

Do wzoru z definicji podstawiamy wartości `f(n)` i `g(n)` dane w zadaniu:

```
0 ≤ c1 * n^2 ≤ 4n^2 + 4n + 4 ≤ c2 * n^2
```

##### Etap trzeci (znajdujemy wartości stałych)

Zacznijmy od znalezienia `n0`. W większości przypadków wystarczy znaleźć takie `n0` dla którego prawdziwa jest nierówność:

```
0 ≤ 4 * (n0)^2 + 4 * (n0) + 4
```

Wiemy, że `n0` musi być dodatnie, więc zacznijmy od sprawdzenia `1`. W wyniku obliczeń otrzymujemy nierówność:

```
0 ≤ 12
```

Czy ta nierówność jest prawdziwa? Oczywiście. Mamy naszą pierwszą wartość.

Teraz zajmijmy się `c1`. Ta stała musi spełniać nierówność:

```
c1 * n^2 ≤ 4n^2 + 4n + 4
```

I, tak jak `n0`, musi mieć wartość dodatnią. Jest to banalna nierówność do rozwiązania. Od razu możemy stwierdzić, że dla `1`, `2`, `3` i `4` zawsze będzie prawdziwa (pamiętając o tym, że `n` jest większe lub równe `n0` (`1`)). Wybierzmy `1`.

Ostatnia wartość jaką musimy znaleźć to `c2`. Musi ona spełniać nierówność postaci:

```
4n^2 + 4n + 4 ≤ c2 * n^2
```

I ta nierówność jest również trywialna. Ale, istnieje pewna konwencja jej rozwiązywania i zachęcam Was do jej używania. Bierzemy wyrażenie po lewej stronie i sumujemy wszystkie współczynniki:

```
c2 = 4 + 4 + 4 = 12
```

Odpowiedź dobra jak każda inna :)

##### Etap czwarty (odpowiedź)

Zapisujemy odpowiedź do naszego zadania:

> Nierówność z definicji notacji theta jest spełniona dla `n0 = 1`, `c1 = 1` i `c2 = 12`.

### 2. Obliczanie złożoności z twierdzenia o rekurencji

> Określ ograniczoność asymptotyczną funkcji `T(n)` danej wzorem `T(n) = 5T(n/5) + n`.

##### Etap pierwszy (znalezienie `a`, `b` i `f(n)`

Posługując się twierdzeniem o rekurencji uniwersalnej znajujemy nasze wartości:

```
a = 5
b = 5
f(n) = n
```

##### Etap drugi (obliczenie logarytmu)

Teraz musimy obliczyć (lub oszacować) wartość logarytmu o podstawie `b` z `a`.

```
log(5) 5 = 1
```

##### Etap trzeci (porównanie)

W następnym kroku porównujemy wartość `f(n)` (po wykreśleniu stałych) z wartością `n` do potęgi `log(b) a`:

```
f(n)                                n ^ (log(a) b)
n = n ^ 1                           n ^ (1 + ε)
```

Z tego porównania wynika, że `ε = 0`, więc...

##### Etap czwarty (odpowiedź)

Jest to drugi przypadek twierdzenia o rekurencji uniwersalnej, więc:

```
T(n) = Θ((n ^ (log(a) b)) * lg n) = Θ(n lg n)
```
