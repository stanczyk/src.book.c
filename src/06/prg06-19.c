/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-19.c
 * @brief Atrybut deprecated
 */
struct [[deprecated]] S
{
	int a;
};

enum [[deprecated]] E1
{
	JEDEN
};

enum E2
{
	DWA [[deprecated ("użyj 'TRZY' w zamian")]],
	TRZY
};

[[deprecated]] typedef int Foo;

void f1 (struct S s) // ostrzeżenie dotyczące użycia przestarzałej struktury S
{
	int i = JEDEN;	 // ostrzeżenie dotyczące użycia E1
	int j = DWA;	 // ostrzeżenie dotyczące użycia DWA: "użyj 'TRZY' w zamian"
	int k = TRZY;
	Foo f;			 // ostrzeżenie dotyczące użycia Foo
}

[[deprecated]] void f2 (struct S s)
{
	int i = JEDEN;
	int j = DWA;
	int k = TRZY;
	Foo f;
}

int main (void) {}

/* eof. */
