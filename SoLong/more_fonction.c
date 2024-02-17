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

