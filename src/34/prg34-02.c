/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-02.c
 * @brief <stdio.h>: użycie funkcji fopen i feof
 */
#include <stdio.h>

int main (void)
{
	FILE *fp = NULL;
	int c;
	// otwórz istniejący plik do odczytu
	if (!(fp = fopen ("plik-tmp.txt", "r")))
	{
		perror (NULL);
		return 1;
	}
	// odczytuj znak po znaku, zatrzymaj się przy EOF
	while (1)
	{
		c = fgetc (fp);
		if (feof (fp))
		{
			printf ("koniec pliku\n");
			break;
		}
		printf ("odczytano: %c\n", c);
	}
	fclose (fp);
}

/* eof. */
