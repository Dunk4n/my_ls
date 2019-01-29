/*
** EPITECH PROJECT, 2018
** none_file
** File description:
** try not to segfault, good luck :)
*/

#include <unistd.h>
#include "my.h"
#include "ls.h"

void    file_de(int ac, char **av)
{
    int i = 0;
    struct stat filestat;

    while (i < ac) {
        if (!stat(av[i], &filestat) && !(filestat.st_mode & S_IROTH)) {
            write(2, "ls: cannot open directory \'", 27);
            write(2, av[i], my_strlen(av[i]));
            write(2, "\': Permission denied\n", 21);
        }
        i++;
    }
}

int     error_de(char *str)
{
    struct stat filestat;

    if (!stat(str, &filestat) && !(filestat.st_mode & S_IROTH)) {
        write(2, "ls: cannot open directory \'", 27);
        write(2, str, my_strlen(str));
        write(2, "\': Permission denied\n", 21);
        return (1);
    }
    return (0);
}

void    file_no(int ac, char **av)
{
    int i = 0;
    struct stat filestat;

    while (i < ac) {
        if (stat(av[i], &filestat) != 0 && !if_fg(av[i])) {
            write(2, "ls: cannot access \'", 19);
            write(2, av[i], my_strlen(av[i]));
            write(2, "\': No such file or directory\n", 29);
        }
        i++;
    }
}

int     none_file(char *str)
{
    struct stat filestat;

    if (!str)
        return (0);
    if (stat(str, &filestat) != 0)
        return (1);
    if (!(filestat.st_mode & S_IROTH))
        return (1);
    return (0);
}

void    cond_tab(char *av, char *fg, struct dirent **dir, int *nb)
{
    DIR             *fddir;

    if ((!(fddir = opendir(av)) || fg[2] == 'd') && !if_fg(av) &&
!none_file(av)) {
        my_strcpy((*dir)[*nb].d_name, av);
        (*nb)++;
    }
    (fddir) ? closedir(fddir) : 0;
}
