/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** concat tow string
*/

int     my_strlen(char *str);

char    *my_strcat(char *dest, char const *src)
{
    int len = 0;
    int i = 0;

    if (!dest || !src)
        return (0);
    len = my_strlen(dest);
    while (src[i] && dest[len + i]) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
