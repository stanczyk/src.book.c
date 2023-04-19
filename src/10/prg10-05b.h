/**
 * Kody źródłowe do "Nowoczesny C. Przegląd C23 z przykładami"
 * @author    Jarosław Stańczyk <jaroslaw@stanczyk.pro>
 * @copyright Jarosław Stańczyk
 * @date      2023
 *
 * @file prg10-05b.h
 * @brief Specyfikator inline
 */
#ifndef PRG10_05_H
#define PRG10_05_H

inline int max (int x, int y)
{
	return (x >= y ? x : y);
}

extern int max (int, int);  // funkcja widziana poza jednostką tłumaczeniową

#endif /* PRG10_05_H */
