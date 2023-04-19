/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-25.c
 * @brief Typy niezgodne i zgodne
 */
int main (void)
{
	// dwie identyczne struktury anonimowe:
	struct { int i; } a, b;
	struct { int i; } c;

	b = a;  // operacja poprawna
	c = a;  // BŁĄD: typy niezgodne
			// anonimowe struktury "nie mają takiej samej nazwy"

	// podejście poprawne:
	struct s { int i; };
	typedef struct s typ1;
	typedef struct s typ2;

	typ1 d, e;
	typ2 f;
	e = d;  // operacja poprawna, ten sam typ
	f = d;  // operacja poprawna, typy zgodne
}

/* eof. */
