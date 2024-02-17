#include "header.h"

static void verif_player_can_exit_recursive(char **tab, int y, int x, t_loot_exit *loot_exit)
{

    if (tab[y][x] == 'E')
        loot_exit->e++;
    if (tab[y][x] == 'C')
        loot_exit->c = loot_exit->c + 1;
    tab[y][x] = '1';
    if (tab[y - 1][x] != '1')
        verif_player_can_exit_recursive(tab, y - 1, x, loot_exit);
    if (tab[y][x - 1] != '1')
        verif_player_can_exit_recursive(tab, y, x - 1, loot_exit);
    if (tab[y + 1][x] != '1')
        verif_player_can_exit_recursive(tab,y + 1, x, loot_exit);
    if (tab[y][x + 1] != '1')
        verif_player_can_exit_recursive(tab, y, x + 1, loot_exit);
}

int verif_player_can_exit(char **tab, int C)
{
    int y;
    int x;
   t_loot_exit loot_exit;

    y = 0;
    loot_exit.c = 0;
    loot_exit.e = 0;
    while (tab[y])
    {
        x = 0;
        while (tab[y][x])
        {
            if (tab[y][x] == 'P')
                break;
            x++;
        }
        if ((size_t)x != ft_strlen(tab[0]))
            break;
        y++;
    }
    verif_player_can_exit_recursive(tab, y, x, &loot_exit);
    if (loot_exit.e == 1 && loot_exit.c == C )
        return (1);
    return (0);
}
