/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-19.c
 * @brief Użycie literału złożonego w strukturach
 */
#include <stdio.h>

struct punkt { int x, y; };

void rysujline1 (struct punkt  start, struct punkt  koniec);
void rysujline2 (struct punkt *start, struct punkt *koniec);

int main (void)
{
	rysujline1 (
		(struct punkt) { .x = 1, .y = 1 },
		(struct punkt) { .x = 3, .y = 4 }
	);  // tworzy dwie struktury i wywołuje rysujline1, przekazując parametry przez wartość

	rysujline2 (
		&(struct punkt) { .x = 11, .y = 12 },
		&(struct punkt) { .x = 13, .y = 14 }
	);  // tworzy dwie struktury i wywołuje rysujline2, przekazując adresy struktur
}

void rysujline1 (struct punkt start, struct punkt koniec)
{
	printf ("rysujline1: start {x=%2i, y=%2i}, koniec {x=%2i, y=%2i}\n", start.x, start.y, koniec.x, koniec.y);
}

void rysujline2 (struct punkt *start, struct punkt *koniec)
{
	printf ("rysujline2: start {x=%2i, y=%2i}, koniec {x=%2i, y=%2i}\n", start->x, start->y, koniec->x, koniec->y);
}

/* eof. */
