/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-02.c
 * @brief typedef i poprawa czytelności kodu
 *
 * @warning
 * Program zawiera tylko deklaracje
 */
#pragma GCC diagnostic ignored "-Wunused-variable"
int main (void)
{
	typedef int MILE, fun_KLIK();
	typedef struct { double max, min; } zakres;

	// Wszystkie poniższe deklaracje są prawidłowe
	MILE dystans;			// typem MILE jest int
	extern fun_KLIK *fwsk;	// typ fwsk to wskaźnik do funkcji
							// bez specyfikacji parametrów zwracającej int
	zakres z, *zwsk;		// z to typ struktury,
							// zwsk jest wskaźnikiem do takiej struktury
}

/* eof. */
