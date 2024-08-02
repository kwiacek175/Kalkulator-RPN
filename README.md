# Kalkulator RPN 

## Opis

Program to prosty kalkulator działający w notacji odwrotnej (RPN - Reverse Polish Notation), implementowany w języku C. Kalkulator używa stosu do przechowywania i przetwarzania liczb. Program obsługuje podstawowe operacje matematyczne oraz dodatkowe operacje na stosie.

## Pliki

### `main.cpp`

Plik główny programu, w którym inicjalizowany jest stos oraz wywoływana jest funkcja `wykonaj_program()`. Program wczytuje dane z wejścia standardowego i wykonuje operacje na stosie do momentu napotkania znaku 'q'.

### `kalkulator_rpn.h`

Plik nagłówkowy zawierający definicje struktur i deklaracje funkcji używanych w programie. Zawiera definicję struktury stosu oraz deklaracje funkcji do zarządzania stosami i wykonywania operacji kalkulatora.

### `kalkulator_rpn.cpp`

Plik implementacji funkcji zadeklarowanych w `kalkulator_rpn.h`. Zawiera implementację operacji na stosie oraz funkcji matematycznych dla kalkulatora RPN.

## Funkcje

- **`init(t_stos **wsk_stos)`**: Inicjalizuje pusty stos.
- **`push(t_stos **wsk_stos, int liczba)`**: Dodaje liczbę na szczyt stosu.
- **`pop(t_stos **wsk_stos)`**: Usuwa liczbę ze szczytu stosu.
- **`print(const t_stos *wsk_stos)`**: Drukuje liczbę ze szczytu stosu.
- **`full_print(t_stos *wsk_stos)`**: Drukuje wszystkie liczby ze stosu.
- **`clear(t_stos **wsk_stos)`**: Czyści wszystkie liczby ze stosu.
- **`reverse(t_stos **wsk_stos)`**: Zamienia miejscami dwie pierwsze liczby na stosie.
- **`duplication(t_stos **wsk_stos)`**: Duplikuje liczbę ze szczytu stosu i dodaje ją ponownie.
- **`addition(t_stos **wsk_stos)`**: Dodaje dwie ostatnie liczby na stosie.
- **`subtraction(t_stos **wsk_stos)`**: Odejmuje dwie ostatnie liczby na stosie.
- **`multiplication(t_stos **wsk_stos)`**: Mnoży dwie ostatnie liczby na stosie.
- **`division(t_stos **wsk_stos)`**: Dzieli dwie ostatnie liczby na stosie.
- **`size(t_stos *wsk_stos)`**: Zwraca liczbę elementów w stosie.
- **`wykonaj_program(t_stos *stos)`**: Wykonuje cały program, wczytuje dane z wejścia i wywołuje odpowiednie funkcje.

## Użycie

1. **Inicjalizacja**: Program tworzy pusty stos.
2. **Wczytywanie danych**: Program wczytuje znaki z wejścia standardowego i interpretuje je jako operacje lub liczby całkowite.
3. **Operacje**:
   - `+`, `-`, `*`, `/` - Operacje matematyczne na dwóch ostatnich liczbach.
   - `P` - Usuwa liczbę ze szczytu stosu.
   - `c` - Czyści cały stos.
   - `r` - Zamienia miejscami dwie pierwsze liczby na stosie.
   - `d` - Duplikuje liczbę ze szczytu stosu.
   - `p` - Drukuje liczbę ze szczytu stosu.
   - `f` - Drukuje wszystkie liczby na stosie.
   - `q` - Kończy działanie programu i zwalnia pamięć.

## Kompilacja i Uruchomienie

Aby skompilować program, użyj następującego polecenia:

```sh
g++ main.cpp kalkulator_rpn.cpp -o kalkulator_rpn
