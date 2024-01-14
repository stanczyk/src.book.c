/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg08-25.c
 * @brief Operator typeof i typeof_unqual
  */
const _Atomic int purr = 0;
const int meow = 1;
const char* const mew[] = { "aardvark", "bluejay", "catte", };

typeof_unqual(meow) main (int argc, char* argv[])
{
	typeof_unqual(purr) 		 plain_purr;
	typeof(_Atomic typeof(meow)) atomic_meow;
	typeof(mew) 				 mew_array[3];
	typeof_unqual(mew) 			 mew2_array[3];
	return 0;
}
/* eof. */
