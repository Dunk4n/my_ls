/*
** EPITECH PROJECT, 2018
** none_file
** File description:
** try not to segfault, good luck :)
*/

#include <unistd.h>
#include "my.h"
#include "ls.h"

int     none_file(char *str, int nb)
{
    struct stat filestat;

    if (!str)
        return (0);
    if (stat(str, &filestat) != 0) {
        if (nb == 1) {
            write(2, "ls: cannot access \'", 19);
            write(2, str, my_strlen(str));
            write(2, "\': No such file or directory\n", 29);
        }
        return (1);
    }
    return (0);
}
