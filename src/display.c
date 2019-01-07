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

void    flag_l(char *path)
{
    struct stat filestat;

    if (!path || stat(path, &filestat) < 0)
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

char    *get_path(char *name, char *path)
{
    char *repath;

    if (!name)
        return (NULL);
    if (!path || !path[0]) {
        if (!(repath = malloc(sizeof(char) * (my_strlen(name) + 1))))
            return (NULL);
        my_strcpy(repath, name);
        return (repath);
    }
    if (name[0] == '/' || path[my_strlen(path) - 1] == '/')
        return (my_strdupcat(path, name));
    if (!(repath = malloc(sizeof(char) * (my_strlen(path) + 2))))
        return (NULL);
    my_strcpy(repath, path);
    repath[my_strlen(path)] = '/';
    repath[my_strlen(path) + 1] = '\0';
    return (my_strdupcat(repath, name));
}

int     total(struct dirent *dir, char *path)
{
    struct stat filestat;
    char        *newpath;
    int         nb = 0;
    int         i = 0;

    if (!dir)
        return -1;
    while (dir[i].d_name[0]) {
        if (dir[i].d_name[0] != '.') {
            newpath = get_path(dir[i].d_name, path);
            stat(newpath, &filestat);
            nb += filestat.st_size;
            free(newpath);
        }
        i++;
    }
    return ((nb + 4096) / 1000);
}

void    display_dir(struct dirent *dir, char *path, char *fg)
{
    char *newpath;
    int i = 0;

    if (!dir || !fg)
        return ;
    if (fg[0] == 'l')
        my_printf("total %d\n", total(dir, path));
    while (dir[i].d_name[0]) {
        if (dir[i].d_name[0] != '.') {
            newpath = get_path(dir[i].d_name, path);
            (fg[0] == 'l') ? flag_l(newpath) : 0;
            my_printf("%s\n", dir[i].d_name);
            free(newpath);
        }
        i++;
    }
}
