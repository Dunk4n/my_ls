/*
** EPITECH PROJECT, 2018
** ls
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "my.h"
#include "ls.h"

void    color_dir(struct dirent *dir, char *str)
{
    struct stat     filestat;

    stat(str, &filestat);
    if (dir->d_type == 4)
        put_color('B', 0, 1);
    if (dir->d_type == 8)
        put_color('W', 0, 1);
    if (dir->d_type != 4 && (filestat.st_mode &S_IXUSR || filestat.st_mode
&S_IXGRP || filestat.st_mode &S_IXOTH))
        put_color('G', 1, 1);
}

int     nb_folder(int ac, char **av)
{
    int i = 1;
    int nb = 0;

    while (i < ac) {
        if (!if_fg(av[i]))
            nb++;
        i++;
    }
    return (nb);
}

char    **tab_name(int ac, char **av)
{
    char    **dirn;
    int     i = 1;
    int     nb = 0;

    while (i < ac) {
        if (!if_fg(av[i++]))
            nb++;
    }
    dirn = malloc(sizeof(char*) * (nb + 1));
    i = 1;
    nb = 0;
    while (i < ac) {
        if (!if_fg(av[i])) {
            dirn[nb] = malloc(sizeof(char) * (my_strlen(av[i]) + 1));
            dirn[nb] = my_strcpy(dirn[nb], av[i]);
            nb++;
        }
        i++;
    }
    dirn[nb] = NULL;
    return (dirn);
}

int     my_ls(int ac, char **av)
{
    struct dirent   *dir;
    char            *fg = option(ac, av);
    int             nbf = nb_folder(ac, av);
    int             i = 1;
    int             nb = 0;
    int             fold = 0;

    if (nbf == 0)
        get_all_dir(fg, ".", NULL, 1);
    dir = tab_file(ac, av, &fold);
    sort_dir(dir, fg);
    display_file(dir, fg, fold);
    while (i < ac) {
        if (!if_fg(av[i])) {
            get_all_dir(fg, av[i], NULL, nbf);
            nb++;
            (nb < fold) ? my_putchar('\n') : 0;
        }
        i++;
    }
    return (0);
}
