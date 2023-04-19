/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-19.c
 * @brief Złożone deklaracje wskaźników
 */
#include <stdio.h>

int fun1(int arg)
{
	return arg;
}

int * fun2(int *arg)
{
	return arg;
}

int main (void)
{
	int arg = 4;
	int       Tab1 [10] 	// tablica z dziesięcioma elementami int
		= {1, 2, 3};
	int  (*wskTab2)[10] 	// wskaźnik do tablicy 10 elementów int
		= &Tab1;
	int   *wskTab3 [10] 	// tablica dziesięciu wskaźników do int
		= {&Tab1[0], &Tab1[1], &Tab1[2]};
	int  (*wskFun1)()		// wskaźnik do funkcji zwracającej int
		= fun1;
	int *(*wskFun2)()		// wskaźnik na funkcję zwracającą int *
		= fun2;
	int  (*wskFun3 [10])()	// tablica wskaźników na funkcje,
						 	// zwracające int
		= { NULL, fun1 };
	printf("      Tab1 []     = {%d, %d, %d, ... }\n",      Tab1 [0],      Tab1 [1],      Tab1 [2]);
	printf(" (*wskTab2)[]     = {%d, %d, %d, ... }\n", (*wskTab2)[0], (*wskTab2)[1], (*wskTab2)[2]);
	printf("  *wskTab3 []     = {%d, %d, %d, ... }\n",  *wskTab3 [0],  *wskTab3 [1],  *wskTab3 [2]);
	printf(" (*wskFun1)()     = %d\n",  (*wskFun1)   ( arg));
	printf("*(*wskFun2)()     = %d\n", *(*wskFun2)   (&arg));
	printf(" (*wskFun3 [1])() = %d\n",  (*wskFun3[1])( arg));
}

/* eof. */
