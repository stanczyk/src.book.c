/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-01.c
 * @brief <stdio.h>: usuwanie flagi błędu przy użyciu clearerr
 */
#include <stdio.h>

int main (void)
{
	FILE *fp = NULL;
	int c;

	fp = fopen ("plik-tmp.txt", "w"); 	// utworzenie pliku
	c = fgetc (fp); 	// czytanie z pustego pliku - wystąpi błąd
	if (ferror (fp))
		perror ("Błąd fgetc");
	clearerr (fp); 		// usuwanie flag błędów

	fputc ('z', fp); 	// zapis do pliku
	fclose (fp);

	fp = fopen ("plik-tmp.txt", "r"); 	// otwarcie do czytania
	c = fgetc (fp);
	if (ferror (fp)) 	// nie powinno być żadnych błędów
		perror ("Błąd fgetc");
	if (fclose (fp))
		perror ("Błąd fclose");
	printf ("odczytany znak: %c\n", c);
}

/* eof. */
