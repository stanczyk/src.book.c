/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-26.c
 * @brief Inicjalizacja struktur zagnieżdżonych
 */
#include <stdint.h>
#include <stdio.h>

int main (void)
{
	struct ipv4 {
		struct {
			uint16_t nr;
		} port;
		union {
			uint8_t a8[4];
			uint32_t ip;
		} addr;
	};

	struct ipv4 ip1 = { 	// start inicjalizacji struktury ip1
		{					// start inicjalizacji pierwszej składowej - ip1.port
		  80				// inicjalizacja pierwszej (i jedynej) składowej
		},					// koniec inicjalizacji ip1.port
		{					// start inicjalizacji następnej składowej - ip1.addr
		  { 127, 0, 0, 1 } 	// inicjalizacja kolejnych elementów pierwszej składowej
		}					// koniec inicjalizacji ip1.addr
	};						// inicjalizacja ip1 zakończona

	struct ipv4 ip2 = { 80, 127, 0, 0, 1 };
		// inicjalizacja jak wyżej, ale z pominięciem nawiasów

	struct ipv4 ip3 = { .addr.a8[0] = 127, 0, 0, 1, .port = 80 };
		// inicjalizacja przy użyciu desygnatorów

	struct ipv4 ip4 = { 80, .addr = { 127, .a8[2] = 1 } };
		// inicjalizacja w stylu mieszanym

	printf ("adres: %i.%i.%i.%i:%i\n", ip1.addr.a8[0], ip1.addr.a8[1], ip1.addr.a8[2], ip1.addr.a8[3], ip1.port.nr);
	printf ("adres: %i.%i.%i.%i:%i\n", ip2.addr.a8[0], ip2.addr.a8[1], ip2.addr.a8[2], ip2.addr.a8[3], ip2.port.nr);
	printf ("adres: %i.%i.%i.%i:%i\n", ip3.addr.a8[0], ip3.addr.a8[1], ip3.addr.a8[2], ip3.addr.a8[3], ip3.port.nr);
	printf ("adres: %i.%i.%i.%i:%i\n", ip4.addr.a8[0], ip4.addr.a8[1], ip4.addr.a8[2], ip4.addr.a8[3], ip4.port.nr);
}

/* eof. */
