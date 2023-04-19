/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg03-04.c
 * @brief Użycie komentarzy w programie
 *
 * Przykład niebanalny
 */

int f = 1, g = 1, h = 1, m = 1, n = 1, p = 1;

void l(void) { ; }

int main (void)
{
//  komentarz (do końca wiersza)
/*
    komentarz
*/

// */          // komentarz, a nie błąd składni
f = g/**//h;   // ekwiwalent f = g / h;
//\
i();           // część dwuwierszowego komentarza (wiersze 25-26)
/\
/ j();         // część dwuwierszowego komentarza (wiersze 27-28)
/*//*/ l();    // ekwiwalent l();
m = n//**/o
    + p;       // ekwiwalent m = n + p;

	return 0;
}

/* eof. */
