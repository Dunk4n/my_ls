/*
** EPITECH PROJECT, 2018
** cmp
** File description:
** try not to segfault, good luck :)
*/

#include <sys/stat.h>
#include "my.h"
#include "ls.h"

int     dir_cmpt(struct dirent *d1, struct dirent *d2)
{
    struct stat attrib1;
    struct stat attrib2;

    stat(d1->d_name, &attrib1);
    stat(d2->d_name, &attrib2);
    if (attrib1.st_ctime - attrib2.st_ctime < 0)
        return (1);
    if (attrib1.st_ctime - attrib2.st_ctime == 0)
        return (0);
    return (-1);
}

int     my_strcmp_c(char const *s1, char const *s2)
{
    int i = 0;
    char *tmp1 = my_strlowcase(my_strdup(s1));
    char *tmp2 = my_strlowcase(my_strdup(s2));

    if (!tmp1 || !tmp2)
        return (0);
    while (tmp1[i] != '\0' || tmp2[i] != '\0') {
        if (tmp1[i] != tmp2[i])
            return (tmp1[i] - tmp2[i]);
        i++;
    }
    i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (s2[i] - s1[i]);
        i++;
    }
    free(tmp1);
    free(tmp2);
    return (0);
}

int     dir_cmp(struct dirent *d1, struct dirent *d2)
{
    return (my_strcmp_c(d1->d_name, d2->d_name));
}
