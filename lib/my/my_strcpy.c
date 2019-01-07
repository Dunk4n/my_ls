/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** copie a string into another
*/

char    *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!dest || !src)
        return (0);
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
