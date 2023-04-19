/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-03.c
 * @brief typedef zastosowany dla poprawy czytelności kodu
 *
 * Trzy identyczne deklaracje funkcji signal
 */
typedef void fun(int), (*wsk_fun)(int);

void (*signal(int, void (*)(int)))(int);
fun *signal(int, fun*);
wsk_fun signal(int, wsk_fun);

int main (void) {}

/* eof. */
