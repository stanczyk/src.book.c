/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg03-03.c
 * @brief Użycie digrafów w kodzie źródłowym
 */
%:include <stdio.h>

int main (void)
<%
	int arr<::> = <%10, 20, 30 %>;
	printf ("Drugi element tablicy: <%i>.\n", arr<:1:>);
%>
/* eof. */
