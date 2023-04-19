/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-20.c
 * @brief Atrybut: fallthrough
 */
void fun_a (void) { ; }
void fun_b (void) { ; }
void fun_c (void) { ; }

void fun (int n)
{
	switch (n)
	{
		case 1:
			// brak ostrzeżenia o przejściu do następnego przypadku
		case 2:
			fun_a ();
			[[fallthrough]]; // brak ostrzeżenia dzięki fallthrough
		case 3:
			fun_b ();
			// ostrzeżenie dot. przejścia do następnego przypadku
		case 4:
			fun_c ();
			[[fallthrough]];
			// ostrzeżenie, ponieważ fallthrough nie poprzedza żadnej etykiety
			// bez fallthrough nie byłoby żadnego ostrzeżenia
	}
}

int main (void)
{
	fun(3);
}
/* eof. */
