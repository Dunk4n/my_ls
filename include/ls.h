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

int             dir_cmpt(struct dirent *d1, struct dirent *d2, char *path);
void            cond_tab(char *av, char *fg, struct dirent **dir, int *nb);
int             dir_cmp(struct dirent *d1, struct dirent *d2, char *path);
void            display_dir(struct dirent *dir, char *path, char *fg);
void            get_all_dir(char *fg, char *name, char *path, int nb);
void            display_file(struct dirent *dir, char *fg, int fold);
void            sort_dir(struct dirent *dir, char *fg, char *path);
struct dirent   *tab_file(int ac, char **av, int *fold, int *ret);
int             nb_folder_nofile(int ac, char **av);
char            *get_path(char *name, char *path);
void            sort_str(char **tab, char *fg);
void            permission(struct stat filestat);
char            *option(int ac, char **av);
void            file_no(int ac, char **av);
int             my_ls(int ac, char **av);
int             none_file(char *str);
struct dirent   *tab_dir(char *str);
int             error_de(char *str);
void            flag_l(char *path);
int             if_fg(char *str);

#endif
