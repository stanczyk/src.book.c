/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg34-14.c
 * @brief <stdio.h>: użycie fwrite/fread do zapisu/odczytu pojedynczej struktury
 */
#include <stdio.h>
#include <string.h>
struct klient
{
	char imie[10];
	char nazwisko[10];
	int nr;
};

int main (void)
{
	// wypełnienie struktury
	struct klient klient;
	strcpy(klient.imie, "Jarosław");
	strcpy(klient.nazwisko, "Stańczyk");
	klient.nr = 21;
	printf("%s %s %d\n", klient.imie, klient.nazwisko, klient.nr);

	// utworzenie pliku i zapis struktury
	FILE *fp = fopen ("plik-tmp.txt", "ab+");
	fwrite(&klient, sizeof(struct klient), 1, fp);

	// wyzerowanie struktury klienta
	memset(&klient, 0, sizeof klient);
	printf("%s %s %d\n", klient.imie, klient.nazwisko, klient.nr);

	// odczyt danych klienta
	fseek(fp, 0L, SEEK_SET);
	fread(&klient, sizeof(struct klient), 1, fp);
	printf("%s %s %d\n", klient.imie, klient.nazwisko, klient.nr);
}

/* eof. */
