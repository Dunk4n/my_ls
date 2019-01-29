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
            (tab[j] == str[i]) ? bol = 0 : 0;
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

struct dirent   *tab_dir(char *str)
{
    DIR             *fddir;
    struct dirent   *dir;
    struct dirent   end;
    struct dirent   *tab;
    int             i = 0;

    if (!str || !(tab = make_malloc(str)) || !(fddir = opendir(str)) ||
!(dir = readdir(fddir))) {
        free(tab);
        return (NULL);
    }
    while (dir) {
        tab[i++] = *dir;
        dir = readdir(fddir);
    }
    end.d_name[0] = 0;
    tab[i] = end;
    closedir(fddir);
    return (tab);
}

int             nb_file(int ac, char **av, int *fold)
{
    DIR             *fddir;
    int             i = 1;
    int             nb = 0;
    struct stat     filestat;

    while (i < ac) {
        if (!stat(av[i], &filestat) && !(filestat.st_mode & S_IROTH))
            (*fold)++;
        if (!(fddir = opendir(av[i])) || !if_fg(av[i]))
            nb++;
        if (fddir) {
            (*fold)++;
            closedir(fddir);
        }
        i++;
    }
    return (nb);
}

struct dirent   *tab_file(int ac, char **av, int *fold, int *ret)
{
    struct stat     filestat;
    struct dirent   *dir;
    char            *fg = option(ac, av);
    int             i = 1;
    int             nb = 0;

    file_no(ac, av);
    if (!(dir = malloc(sizeof(struct dirent) * (nb_file(ac, av, fold) + 1))))
        return (NULL);
    while (i < ac) {
        stat(av[i], &filestat);
        if (!if_fg(av[i]))
            *ret = (none_file(av[i]) == 1 || *ret == 0) ? 1 : 0;
        cond_tab(av[i], fg, &dir, &nb);
        i++;
    }
    dir[nb].d_name[0] = '\0';
    return (dir);
}
