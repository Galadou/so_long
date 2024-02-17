#include "header.h"

static char    find_apropriate_tiles(char **tab, int y, int x)
{
    //si tout est ouvert, grande salle X
    if (tab[y -1][x] != '1' && tab[y][x - 1] != '1' && tab[y + 1][x] != '1' && tab[y][x + 1] != '1')
        return ('X');

    //si c'est ouvert en haut en bas, couloir H
    if (tab[y -1][x] != '1' && tab[y][x - 1] == '1' && tab[y + 1][x] != '1' && tab[y][x + 1] == '1')
        return ('H');

    //si inverse, couloir Z
    if (tab[y -1][x] == '1' && tab[y][x - 1] != '1' && tab[y + 1][x] == '1' && tab[y][x + 1] != '1')
        return ('Z');

    //si tourne a gauche a partir d'en bas, >
    if (tab[y -1][x] == '1' && tab[y][x - 1] != '1' && tab[y + 1][x] != '1' && tab[y][x + 1] == '1')
        return ('a');

    //si inverse, <
    if (tab[y -1][x] == '1' && tab[y][x - 1] == '1' && tab[y + 1][x] != '1' && tab[y][x + 1] != '1')
        return ('b');

    // si d'en haut tourne a gauche, l
    if (tab[y -1][x] != '1' && tab[y][x - 1] != '1' && tab[y + 1][x] == '1' && tab[y][x + 1] == '1')
        return ('l');

    //si inverse, L
    if (tab[y -1][x] != '1' && tab[y][x - 1] == '1' && tab[y + 1][x] == '1' && tab[y][x + 1] != '1')
        return ('L');

    //si t a l'enver, _
   if (tab[y -1][x] != '1' && tab[y][x - 1] != '1' && tab[y + 1][x] == '1' && tab[y][x + 1] != '1')
        return ('_');

    //si t ouvert a droite, 7
    if (tab[y -1][x] != '1' && tab[y][x - 1] != '1' && tab[y + 1][x] != '1' && tab[y][x + 1] == '1')
        return ('7');

    // si t ouvert a gauche, K
    if (tab[y -1][x] != '1' && tab[y][x - 1] == '1' && tab[y + 1][x] != '1' && tab[y][x + 1] != '1')
        return ('K');

    //si t, T
    if (tab[y -1][x] == '1' && tab[y][x - 1] != '1' && tab[y + 1][x] != '1' && tab[y][x + 1] != '1')
        return ('T');

    //si U
    if (tab[y -1][x] != '1' && tab[y][x - 1] == '1' && tab[y + 1][x] == '1' && tab[y][x + 1] == '1')
        return ('U');

    //si u ouvert a gauche, ]
    if (tab[y -1][x] == '1' && tab[y][x - 1] != '1' && tab[y + 1][x] == '1' && tab[y][x + 1] == '1')
        return (']');

    //si n
    if (tab[y -1][x] == '1' && tab[y][x - 1] == '1' && tab[y + 1][x] != '1' && tab[y][x + 1] == '1')
        return ('n');

    // si u ouvert a droite, c
    if (tab[y -1][x] == '1' && tab[y][x - 1] == '1' && tab[y + 1][x] == '1' && tab[y][x + 1] != '1')
        return ('c');
    return (0);
}


void    tab_transform_for_tiles(char **tab)
{
    int y;
    int x;

    y = 1;
    while (tab[y])
    {
        x = 0;
        while (tab[y][x])
        {
            if (tab[y][x] != '1')
                tab[y][x] = find_apropriate_tiles(tab, y, x);
            x++;
        }
        y++;
    }
}

static char    find_apropriate_exit(char **tab, int y, int x)
{
    if (tab[y - 1][x] == '1')
        return ('t');
    if (tab[y][x - 1] == '1')
        return('l');
    if (tab[y][x + 1] == '1')
        return ('r');
    return ('m');
}
void    tab_transform_for_exit(char **tab)
{
    int y;
    int x;

    y = 1;
    while (tab[y])
    {
        x = 0;
        while (tab[y][x])
        {
            if (tab[y][x] == 'E')
                tab[y][x] = find_apropriate_exit(tab, y, x);
            x++;
        }
        y++;
    }
}
