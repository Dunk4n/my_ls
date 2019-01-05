/*
** EPITECH PROJECT, 2018
** display
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"
#include "ls.h"

void    pars_time(char *str)
{
    int  i = 0;
    char **tab = my_str_to_word_array(str, ' ');

    if (!tab)
        return ;
    tab[3][5] = '\0';
    my_printf("%s %s %s ", tab[2], tab[1], tab[3]);
    while (tab[i])
        free(tab[i++]);
    free(tab);
}

void    flag_l(struct dirent dir, char *fg)
{
    struct stat filestat;

    if (stat(dir.d_name, &filestat) < 0)
        return ;
    my_putstr((S_ISDIR(filestat.st_mode)) ? "d" : "-");
    my_putstr((filestat.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((filestat.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((filestat.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((filestat.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((filestat.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((filestat.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((filestat.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((filestat.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr((filestat.st_mode & S_IXOTH) ? "x" : "-");
    my_printf(". %d %s %s %d  ", filestat.st_nlink,
(getpwuid(filestat.st_uid))->pw_name, (getgrgid(filestat.st_gid))->gr_name,
filestat.st_size);
    pars_time(ctime(&filestat.st_mtime));
}

int     total(struct dirent *dir)
{
    struct stat filestat;
    int         nb = 0;
    int         i = 0;

    while (dir[i].d_name[0]) {
        if (dir[i].d_name[0] != '.') {
            stat(dir[i].d_name, &filestat);
            nb += filestat.st_size;
        }
        i++;
    }
    return ((nb + 4096) / 1000);
}

void    display_dir(struct dirent *dir, char *fg)
{
    int i = 0;

    if (!dir || !fg)
        return ;
    if (fg[0] == 'l')
        my_printf("total %d\n", total(dir));
    while (dir[i].d_name[0]) {
        if (dir[i].d_name[0] != '.') {
            (fg[0] == 'l') ? flag_l(dir[i], fg) : 0;
            my_printf("%s\n", dir[i].d_name);
        }
        i++;
    }
}
