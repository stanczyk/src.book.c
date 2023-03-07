/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-25.c
 * @brief Dyrektywa #pragma
 *
 * Po sprawdzeniu poprzez gcc -E prg11-25.c wywołanie ALIGNMENT (2) zostaje rozwinięte do #pragma pack(2)
 */
#define STR(s) #s  // zamiana argument na łańcuch
#define ALIGNMENT(n) _Pragma(STR(pack(n)))

int main (void)
{
	ALIGNMENT (2);
}

/* eof. */
