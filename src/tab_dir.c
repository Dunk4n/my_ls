/*
** EPITECH PROJECT, 2018
** src/tab_dir
** File description:
** try not to segfault, good luck :)
*/

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my.h"
#include "ls.h"

int             if_fg(char *str)
{
    char    tab[] = "lRdrt";
    int     i = 1;
    int     j = 0;
    int     bol = 0;

    if (!str || str[0] != '-')
        return (0);
    while (str[i] && !bol) {
        j = 0;
        bol = 1;
        while (tab[j] && bol) {
            if (tab[j] == str[i]) {
                bol = 0;
            }
            j++;
        }
        i++;
    }
    return ((bol == 0) ? 1 : 0);
}

struct dirent   *make_malloc(char *str)
{
    struct dirent   *tab;
    DIR             *fddir = opendir(str);
    struct dirent   *dir;
    int             i = 0;

    if (!fddir)
        return (NULL);
    while ((dir = readdir(fddir)) && i++ >= 0);
    closedir(fddir);
    if (!(tab = malloc(sizeof(struct dirent) * (i + 1))))
        return (NULL);
    return (tab);
}

struct dirent   *tab(char *str)
{
    DIR             *fddir;
    struct dirent   *dir;
    struct dirent   end;
    struct dirent   *tab;
    int             i = 0;

    if (!(tab = make_malloc(str)))
        return (NULL);
    if (!(fddir = opendir(str)))
        return (NULL);
    dir = readdir(fddir);
    while (dir) {
        tab[i++] = *dir;
        dir = readdir(fddir);
    }
    end.d_name[0] = 0;
    tab[i] = end;
    closedir(fddir);
    return (tab);
}

struct dirent   *tab_dir(int ac, char **av, int nb)
{
    int i = 1;
    int tmp = 0;

    if (nb < 0)
        return (NULL);
    if (nb == 0) {
        i = 0;
        tmp--;
    }
    while (i < ac) {
        if (if_fg(av[i]) == 0)
            tmp++;
        if (tmp == nb)
            return (tab(av[i]));
        i++;
    }
    return (NULL);
}
