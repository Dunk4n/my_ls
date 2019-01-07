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

void            display_dir(struct dirent *dir, char *path, char *fg);
void            get_all_dir(char *fg, char *name, char *path, int nb);
void            display_file(struct dirent *dir, char *fg, int fold);
int             dir_cmpt(struct dirent *d1, struct dirent *d2);
int             dir_cmp(struct dirent *d1, struct dirent *d2);
void            sort_dir(struct dirent *dir, char *fg);
struct dirent   *tab_file(int ac, char **av, int *fold);
int             nb_folder_nofile(int ac, char **av);
char            *get_path(char *name, char *path);
char            *option(int ac, char **av);
int             my_ls(int ac, char **av);
struct dirent   *tab_dir(char *str);
void            flag_l(char *path);
int             if_fg(char *str);

#endif
