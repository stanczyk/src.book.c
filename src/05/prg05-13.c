/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-13.c
 * @brief Przykład łańcuchów rozszerzonych
 *
 * "Witaj, Świecie!" w kilku językach
 */
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main (void)
{
	setlocale (LC_ALL, "");
	// setlocale(LC_ALL, "C.UTF-8");  //  także działa
	wchar_t pl[] = L"Witaj, Świecie!";
	wchar_t en[] = L"Hello World!";
	wchar_t cn[] = L"世界, 你好!";
	wchar_t jp[] = L"こんにちは日本!";
	wchar_t il[] = L"!שלום עולם";

	printf ("%ls %zu znaków, rozmiar: %zu bajtów\n", pl, wcslen (pl), sizeof (pl));
	printf ("%ls\n", en);
	printf ("%ls\n", cn);
	printf ("%ls\n", jp);
	printf ("%ls\n", il);
}

/* eof. */
