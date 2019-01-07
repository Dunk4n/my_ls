/*
** EPITECH PROJECT, 2018
** sort
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "my.h"
#include "ls.h"

void    swap_sort(struct dirent *d1, struct dirent *d2, int *swap,
int(*dmp)(struct dirent *d1, struct dirent *d2))
{
    struct dirent tmp;

    if (dmp(d1, d2) > 0) {
        *swap = 1;
        tmp = *d1;
        *d1 = *d2;
        *d2 = tmp;
    }
}

void    buble_sort(struct dirent *dir, int(*dmp)(struct dirent *d1,
struct dirent *d2))
{
    int i = 0;
    int swap = 1;

    while (swap) {
        i = 1;
        swap = 0;
        while (dir[i].d_name[0]) {
            swap_sort(&(dir[i - 1]), &(dir[i]), &swap, dmp);
            i++;
        }
    }
}

void    dir_rev(struct dirent **dir)
{
    struct dirent   tmp;
    int             nb = 0;
    int             i = 0;

    if (!dir || !(*dir))
        return ;
    while ((*dir)[nb++].d_name[0]);
    nb -= 2;
    while (i < nb / 2) {
        tmp = (*dir)[i];
        (*dir)[i] = (*dir)[nb - i];
        (*dir)[nb - i] = tmp;
        i++;
    }
}

void    sort_dir(struct dirent *dir, char *fg)
{

    if (!fg || !dir || !dir[0].d_name[0] || !dir[1].d_name[0])
        return ;
    if (fg[4] != 't')
        buble_sort(dir, &dir_cmp);
    else
        buble_sort(dir, &dir_cmpt);
    if (fg[3] == 'r')
        dir_rev(&dir);
}
