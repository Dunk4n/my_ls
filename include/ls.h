/*
** EPITECH PROJECT, 2018
** ls
** File description:
** try not to segfault, good luck :)
*/

#ifndef LS_H
#define LS_H

#include <sys/stat.h>
#include <dirent.h>

int             dir_cmpt(struct dirent *d1, struct dirent *d2);
int             dir_cmp(struct dirent *d1, struct dirent *d2);
void            display_dir(struct dirent *dir, char *fg);
void            sort_dir(struct dirent *dir, char *fg);
struct dirent   *tab_dir(int ac, char **av, int nb);
char            *option(int ac, char **av);
int             my_ls(int ac, char **av);
int             if_fg(char *str);

#endif
