/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg11-17.c
 * @brief Zmienna ilość argumentów w makrze
 *
 * __VA_OPT__
 */
#include <stdio.h>!

int main (void)
{
#define F(...) f(0 __VA_OPT__(,) __VA_ARGS__)
#define G(X, ...) f(0, X __VA_OPT__(,) __VA_ARGS__)
#define SDEF(sname, ...) S sname __VA_OPT__(= { __VA_ARGS__ })
#define EMP
	F (a, b, c)	// rozwinięte do f(0, a, b, c)
	F ()		// rozwinięte do f(0)
	F (EMP)		// rozwinięte do f(0)

	G (a, b, c)	// rozwinięte do f(0, a, b, c)
	G (a,)		// rozwinięte do f(0, a)
	G (a)		// rozwinięte do f(0, a)

	SDEF (foo);	// rozwinięte do S foo;
	SDEF (bar, 1, 2);	// rozwinięte do S bar = { 1, 2 };

#define H1(X, ...) X __VA_OPT__(##) __VA_ARGS__
	// error: ## on line above
	// may not appear at the beginning of a replacement list

#define H2(X, Y, ...) __VA_OPT__(X ## Y,) __VA_ARGS__
	H2 (a, b, c, d)	// rozwinięte do ab, c, d

#define H3(X, ...) #__VA_OPT__(X##X X##X)
	H3 (, 0)	// rozwinięte do ""

#define H4(X, ...) __VA_OPT__(a X ## X) ## b
	H4 (, 1)	// rozwinięte do a b

#define H5A(...) __VA_OPT__()/**/__VA_OPT__()
#define H5B(X) a ## X ## b
#define H5C(X) H5B(X)
		H5C (H5A ())	// rozwinięte do ab
}

/* eof. */
