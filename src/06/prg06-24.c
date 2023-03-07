/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg06-24.c
 * @brief Wartości atrybutów __has_c_attribute
 */
# include <stdio.h>

int main (void)
{
	#if __has_c_attribute( deprecated )
		printf("  deprecated = %d\n", __has_c_attribute( deprecated ));
	#endif
	#if __has_c_attribute( fallthrough )
		printf(" fallthrough = %d\n", __has_c_attribute( fallthrough ));
	#endif
	#if __has_c_attribute( maybe_unused )
		printf("maybe_unused = %d\n", __has_c_attribute( maybe_unused ));
	#endif
	#if __has_c_attribute( nodiscard )
		printf("   nodiscard = %d\n", __has_c_attribute( nodiscard ));
	#endif
	#if __has_c_attribute( noreturn )
		printf("    noreturn = %d\n", __has_c_attribute( noreturn ));
	#endif
	#if __has_c_attribute( reproducible )
		printf("reproducible = %d\n", __has_c_attribute( reproducible ));
	#endif
	#if __has_c_attribute( unsequenced )
		printf(" unsequenced = %d\n", __has_c_attribute( unsequenced ));
	#endif
}
/* eof. */
