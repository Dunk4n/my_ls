/*
** EPITECH PROJECT, 2018
** option
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <dirent.h>
#include "my.h"
#include "ls.h"

void    set_fgin(char *fgin)
{
    int i = 0;

    while (i < 5) {
        fgin[i] = ' ';
        i++;
    }
    fgin[5] = '\0';
}

char    *option(int ac, char **av)
{
    char *fgin = malloc(6);
    int i = 1;
    int j = 1;

    if (!fgin)
        return (NULL);
    set_fgin(fgin);
    while (i < ac) {
        j = 1;
        while (if_fg(av[i]) && av[i][j]) {
            (av[i][j] == 'l') ? fgin[0] = 'l' : 0;
            (av[i][j] == 'R') ? fgin[1] = 'R' : 0;
            (av[i][j] == 'd') ? fgin[2] = 'd' : 0;
            (av[i][j] == 'r') ? fgin[3] = 'r' : 0;
            (av[i][j] == 't') ? fgin[4] = 't' : 0;
            j++;
        }
        i++;
    }
    return (fgin);
}
