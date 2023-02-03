/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:57:17 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/03 23:04:40 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	initialmlx(void)
{
	t_mlx	mlx;

	mlx.height = 64;
	mlx.width = 64;
	mlx.mlx = NULL;
	mlx.mlx_win = NULL;
	mlx.img = NULL;
	return (mlx);
}

void	ft_ber(char *str)
{
	char	*ptr;
	int		x;
	int		y;

	ptr = ".ber";
	x = ft_strlenn(str);
	y = ft_strlenn(ptr);
	while (y >= 0)
	{
		if (str[x] != ptr[y])
		{
			ft_putendl_fd("Error : hold my .ber", 2);
			exit(-1);
		}
		x--;
		y--;
	}
}

void	floodfill(int x, int y, t_for *check)
{
	if (check->dupp[y][x] == 'E')
	{
		check->dupp[y][x] = 'X';
		check->exit += 1;
	}
	if (check->dupp[y][x] == 'V' || check->dupp[y][x] == '1'
		|| check->dupp[y][x] == 'X')
		return ;
	if (check->dupp[y][x] == 'C')
		check->collect += 1;
	if (check->dupp[y][x] == 'P' || check->dupp[y][x] == '0'
		|| check->dupp[y][x] == 'C')
		check->dupp[y][x] = 'V';
	floodfill(x + 1, y, check);
	floodfill(x - 1, y, check);
	floodfill(x, y + 1, check);
	floodfill(x, y - 1, check);
}

void	ft_freed(char **dupp)
{
	int	i;

	i = 0;
	while (dupp[i])
	{
		free(dupp[i]);
		i++;
	}
	free(dupp);
}

int	exitx(void)
{
	exit(0);
}
