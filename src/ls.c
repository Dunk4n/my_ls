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

int     my_ls(int ac, char **av)
{
    struct dirent   *dir = tab_dir(ac, av, 1);
    char            *fg = option(ac, av);

    if (!nb_folder(ac, av)) {
        av[0][0] = '.';
        av[0][1] = '\0';
        dir = tab_dir(ac, av, 0);
        sort_dir(dir, fg);
        display_dir(dir, fg);
        return (0);
    }
    sort_dir(dir, fg);
    display_dir(dir, fg);
    /*while (dir && dir[i].d_name[0]) {
        printf("%s\n", dir[i].d_name);
        i++;
    }*/
    return (0);
/*  while (dir) {
        while (k < ac) {
            if (!if_fg(av[k]))
                printf("%s:\n", av[k]);
            k++;
        }
        while (dir && dir[i].d_name[0]) {
            printf("%s\n", dir[i].d_name);
            i++;
        }
        j++;
        dir = tab_dir(ac, av, j);
    }*/
    put_color('W', 0, 1);
    return (0);
}
