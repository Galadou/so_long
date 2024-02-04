#include "header.h"

int verif_rectangle(char *map_ber, size_t *l, size_t *c)
{
    int     fd;
    char    *line;

    fd = open(map_ber, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
        return (2);
    *c = ft_strlen(line);
    if (line)
        *l = 1;
    while (line)
    {
        free(line);
        line = get_next_line(fd);
        if (!line)
            break;
        if (*c != ft_strlen(line))
            return (0);
        *l += 1;
    }
    close(fd);
    if (*l < 2)
        return (0);
    return(1);
}