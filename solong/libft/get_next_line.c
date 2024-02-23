/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:46:54 by gmersch           #+#    #+#             */
/*   Updated: 2023/12/18 15:46:57 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	str_check_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*verif_line(char **str)
{
	int		j;
	char	*line;
	char	*tmp;

	j = 0;
	if (!(*str) || str[0][0] == '\0')
		return (NULL);
	while (str[0][j] != '\0')
	{
		if (str[0][j] == '\n')
		{
			line = ft_substr_gnl(str[0], 0, j + 1);
			if (ft_strlen_gnl(str[0]) != (j + 1))
				tmp = ft_substr_gnl(str[0], j + 1, ft_strlen_gnl(str[0]) - (j));
			else
				tmp = NULL;
			free(str[0]);
			str[0] = tmp;
			return (line);
		}
		j++;
	}
	line = ft_substr_gnl(str[0], 0, j);
	return (line);
}

static int	str_creator_gnl(int fd, char **str, int *len)
{
	char	*buffer;
	char	*temp;

	*len = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (*len == BUFFER_SIZE)
	{
		*len = read(fd, buffer, BUFFER_SIZE);
		if (*len < 0)
		{
			free(buffer);
			return (0);
		}
		if (*len == 0)
			break ;
		buffer[*len] = '\0';
		temp = ft_strjoin_gnl(str[0], buffer);
		str[0] = temp;
		if (str_check_gnl(buffer) == 1)
			break ;
	}
	free(buffer);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str = NULL;
	int			len;
	int			verif;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 0;
	verif = 0;
	if (!str || str_check_gnl(str) == 0)
		verif = str_creator_gnl(fd, &str, &len);
	if (str == NULL || verif == -1)
		return (NULL);
	line = verif_line(&str);
	if ((len < BUFFER_SIZE && str && (ft_strcmp_gnl(str, line) == 0
				&& verif == 1)) || BUFFER_SIZE == 1)
	{
		free(str);
		str = NULL;
	}
	if (line)
		return (line);
	return (NULL);
}
