/*
** EPITECH PROJECT, 2018
** display_folder
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include "my.h"
#include "ls.h"

int     nb_folder_nofile(int ac, char **av)
{
    DIR             *fddir;
    struct dirent   *dir;
    int             i = 1;
    int             nb = 0;

    while (i < ac) {
        if ((fddir = opendir(av[i])) && (dir = readdir(fddir)) &&
dir->d_type == 4)
            nb++;
        (fddir) ? closedir(fddir) : 0;
        i++;
    }
    return (nb);
}

void    display_file(struct dirent *dir, char *fg, int fold)
{
    int i = 0;

    while (dir[i].d_name[0]) {
        (fg[0] == 'l') ? flag_l(dir[i].d_name) : 0;
        my_printf("%s\n", dir[i].d_name);
        i++;
    }
    if (fold > 0 && i > 0)
        my_putchar('\n');
}

void    get_all_dir(char *fg, char *name, char *path, int nb)
{
    struct dirent   *dir;
    char            *newpath;
    int             i = 0;

    if (!fg || !name || !(newpath = get_path(name, path)) ||
!(dir = tab_dir(newpath)))
        return ;
    (nb > 1 || fg[1] == 'R') ? my_printf("%s:\n", newpath) : 0;
    sort_dir(dir, fg);
    display_dir(dir, newpath, fg);
    while (fg[1] == 'R' && dir[i].d_name[0]) {
        if ((dir[i].d_name[0] != '.' || dir[i].d_name[1] == '/') &&
dir[i].d_type == 4) {
            my_putchar('\n');
            get_all_dir(fg, dir[i].d_name, newpath, nb);
        }
        i++;
    }
    free(newpath);
}
