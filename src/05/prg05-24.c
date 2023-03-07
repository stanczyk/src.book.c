/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg05-24.c
 * @brief Typ strukturalny użyty w liście jednokierunkowej
 *
 * Lista tworzona dynamicznie (fragment większego programu).
 */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;          // przechowywane dane
	struct node *next; // wskaźnik do następnego elementu listy
};

struct node * tworz_element (void);
int dodaj (struct node ** lista, struct node * element);
void usun (struct node ** lista);
void przegladaj (struct node ** lista);

int main (void)
{
	struct node *lista = NULL;

	srand (time (NULL));  // inicjowanie generatora liczb losowych
	przegladaj (&lista);
	dodaj (&lista, tworz_element ());
	dodaj (&lista, tworz_element ());
	przegladaj (&lista);
	usun (&lista);
	przegladaj (&lista);
	return (EXIT_SUCCESS);
}

// Przegląda (i wyświetla) zawartość listy (w stylu C).
void przegladaj (struct node ** lista)
{
	printf ("Lista: ");
	if (! *lista)
	{
		printf ("pusta\n");
		return;
	}
	for (struct node * cur = *lista; cur; cur = cur->next)
		printf ("%d ", cur->data);
	printf ("\n");
}

// Tworzy element (tzn. przydziela pamięć) i wypełnienie danymi.
struct node * tworz_element (void)
{
	struct node * element = NULL;

	if (! (element = (struct node *) malloc (sizeof (struct node))))
		return element;  // brak pamięci?

	element->data = rand () % 100;  // losowa liczba z zakresu 0-99
	element->next = NULL;
	return element;
}

// Wstawia element na początek listy.
int dodaj (struct node ** lista, struct node * element)
{
	if (! element)
		return (EXIT_FAILURE);  // nie ma czego dodawać

	if (*lista)
		element->next = *lista;
	*lista = element;
	return (EXIT_SUCCESS);
}

// Usuwa całą listę z pamięci
void usun (struct node ** lista)
{
	struct node *cur;
	while (*lista)
	{
		cur = (*lista)->next;
		free (*lista);
		*lista = cur;
	}
}

/* eof. */
