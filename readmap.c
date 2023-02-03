/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:46:59 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/31 16:33:42 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**reading(char *str)
{
	int		fd;
	char	*tmp;
	char	*allm;
	char	**map;

	allm = NULL;
	fd = open(str, O_RDONLY);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
		{
			readcondit(allm);
			break ;
		}
		readcondit2(tmp);
		allm = ft_strjoinn(allm, tmp);
		free(tmp);
	}
	map = ft_split(allm, '\n');
	free (allm);
	return (map);
}

void	readcondit(char *allm)
{
	int	len;

	if (allm == NULL)
	{
		ft_putendl_fd("Error 404", 2);
		exit(-1);
	}
	len = ft_strlenn(allm);
	if (allm[len - 1] == '\n')
	{
		ft_putendl_fd("Error : End of route.", 2);
		exit(-1);
	}
}

void	readcondit2(char *tmp)
{
	if (tmp[0] == '\n')
	{
		ft_putendl_fd("Error : Seems like Mihawk was here.", 2);
		exit(-1);
	}
}
