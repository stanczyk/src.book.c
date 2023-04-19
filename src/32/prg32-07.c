/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg32-06.c
 * @brief <stddef.h>: program, w którym przyjęto,
 * że powinien uruchamiać się z co najmniej jednym argumentem wiersza poleceń
 */
#include <stdio.h>
#include <stddef.h>

int main (int argc, char *argv[static argc + 1])
{
	printf("%d\n", argc);
	if (argc <= 2)
		unreachable ();
	else
		return printf ("uruchomiono %s z argumentem: %s\n", argv[0], argv[1]);
	return puts ("to miejsce nigdy nie powinno zostać osiągnięte");
}

/* eof. */
