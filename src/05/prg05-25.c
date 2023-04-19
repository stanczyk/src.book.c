/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-25.c
 * @brief Struktury anonimowe
 */

int main (void)
{
	struct {      // struktura anonimowa
		struct { int ai, bi; }; // struktura anonimowa
		struct { long al, bl; } l;
		int c;
	} st;

	st.ai = 3;   // przypisanie poprawne
	/*
	st.al = 4;   // błąd: wewnętrzna struktura nie jest anonimowa
	*/
	st.l.al = 5; // przypisanie poprawne
}

/* eof. */
