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

int     nb_tab_dir(int ac, char **av)
{
    DIR     *fddir = NULL;
    int     i = 1;
    int     nb = 0;

    while (i < ac) {
        if (!if_fg(av[i++]) && !none_file(av[i], 0))
            nb++;
        (fddir) ? closedir(fddir) : 0;
    }
    return (nb);
}

char    **tab_name(int ac, char **av)
{
    DIR     *fddir = NULL;
    char    **dirn;
    int     i = 1;
    int     nb = 0;

    if (!(dirn = malloc(sizeof(char*) * (nb_tab_dir(ac, av) + 1))))
        return (NULL);
    while (i < ac) {
        if (!if_fg(av[i]) && !none_file(av[i], 0) && (fddir = opendir(av[i]))) {
            dirn[nb] = malloc(sizeof(char) * (my_strlen(av[i]) + 1));
            dirn[nb] = my_strcpy(dirn[nb], av[i]);
            closedir(fddir);
            nb++;
        }
        i++;
    }
    dirn[nb] = NULL;
    return (dirn);
}

void    list_dir(int ac, char **av, int fold)
{
    char            **tab = tab_name(ac, av);
    char            *fg = option(ac, av);
    int             nbf = nb_folder(ac, av);
    int             nb = 0;
    int             i = 0;

    sort_str(tab, fg);
    while (tab[i] && fg[2] != 'd') {
        if (!if_fg(tab[i])) {
            get_all_dir(fg, tab[i], NULL, nbf);
            nb++;
            (nb < fold) ? my_putchar('\n') : 0;
        }
        i++;
    }
}

int     my_ls(int ac, char **av)
{
    struct dirent   *dir;
    char            *fg = option(ac, av);
    int             nbf = nb_folder(ac, av);
    int             fold = 0;
    int             ret = 0;

    if (nbf == 0)
        get_all_dir(fg, ".", NULL, 1);
    dir = tab_file(ac, av, &fold, &ret);
    sort_dir(dir, fg);
    display_file(dir, fg, fold);
    list_dir(ac, av, fold);
    return ((ret != 0) ? 84 : 0);
}
