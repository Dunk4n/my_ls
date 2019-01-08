/*
** EPITECH PROJECT, 2018
** sort_str
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "my.h"
#include "ls.h"

void    swap_sort_str(char **s1, char **s2, int *swap,
int(*cmps)(const char *s1, const char *s2))
{
    char *tmp;

    if (cmps(*s1, *s2) > 0) {
        *swap = 1;
        tmp = *s1;
        *s1 = *s2;
        *s2 = tmp;
    }
}

int     str_cmpt(const char *s1, const char *s2)
{
    struct stat attrib1;
    struct stat attrib2;

    stat(s1, &attrib1);
    stat(s2, &attrib2);
    if (attrib1.st_ctime - attrib2.st_ctime < 0)
        return (1);
    if (attrib1.st_ctime - attrib2.st_ctime == 0)
        return (0);
    return (-1);
}

void    dir_rev_str(char **tab)
{
    char *tmp;
    int  nb = 0;
    int  i = 0;

    if (!tab || !(*tab))
        return ;
    while (tab[nb++]);
    nb--;
    while (i < nb / 2) {
        tmp = tab[i];
        tab[i] = tab[nb - i - 1];
        tab[nb - i - 1] = tmp;
        i++;
    }
}

void    buble_sort_str(char **tab, int(*cmps)(const char *s1, const char *s2))
{
    int i = 0;
    int swap = 1;

    while (swap) {
        i = 1;
        swap = 0;
        while (tab[i]) {
            swap_sort_str(&tab[i - 1], &tab[i], &swap, cmps);
            i++;
        }
    }
}

void    sort_str(char **tab, char *fg)
{
    if (!fg || !tab || !tab[0])
        return ;
    buble_sort_str(tab, &my_strcmp);
    if (fg[4] == 't')
        buble_sort_str(tab, &str_cmpt);
    if (fg[3] == 'r')
        dir_rev_str(tab);
}
