#include "header.h"

int	abs(int nb)
{
	if (nb < 0)
		nb = nb * (-1);
	return(nb);
}


void tab_reset(char **dest, char **src)
{
	int x;
	int y;

	y = 0;
	while (dest[y])
	{
		x = 0;
		while (dest[y][x])
		{
			dest[y][x] = src[y][x];
			x++;
		}
		y++;
	}
}

static char	*put_char_to_string (char c, t_coordinates *coordinates)
{
	int		i;
	char	*buf_string;

	buf_string = ft_calloc(sizeof(char *), ft_strlen(coordinates->string_count_moove) + 1);
	i = 0;
	while (coordinates->string_count_moove[i])
	{
		buf_string[i] = coordinates->string_count_moove[i];
		i++;
	}
	buf_string[i] = c;
	return (buf_string);
}

void number_to_string(int n, t_coordinates *coordinates)
{
	int	nb;
	int				c;
	char			*buf_string;

	nb = n;
	if (nb > 9)
		number_to_string((nb / 10), coordinates);
	nb = nb % 10;
	c = nb + '0';
	buf_string = put_char_to_string(c, coordinates);
	coordinates->string_count_moove = ft_strdup( buf_string);
	//ft_printf("%s\n", coordinates->string_count_moove);
	free(buf_string);
}

