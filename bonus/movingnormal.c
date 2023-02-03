/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movingnormal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:54:01 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/31 17:40:44 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	movingup(t_all *all)
{
	char	*printer;

	draw_tile(all, 0, 0, "./textures/ice_map/wall.xpm");
	printer = ft_itoa(all->steps);
	mlx_string_put(all->mlx.mlx, all->mlx.mlx_win, 10, 10, 0x000000FF, printer);
	free (printer);
	if (all->component.map[all->component.player.y
			- 1][all->component.player.x] == 'C')
	{
		all->component.map[all->component.player.y
			- 1][all->component.player.x] = '0';
		all->component.collect--;
	}
	draw_tile(all, all->component.player.x, all->component.player.y - 1,
		"./textures/sans_xpm/sans_up_left.xpm");
	draw_tile(all, all->component.player.x, all->component.player.y,
		"./textures/ice_map/floor2.xpm");
	all->component.player.y--;
	all->steps++;
}

void	movingright(t_all *all)
{
	char	*printer;

	draw_tile(all, 0, 0, "./textures/ice_map/wall.xpm");
	printer = ft_itoa(all->steps);
	mlx_string_put(all->mlx.mlx, all->mlx.mlx_win, 10, 10, 0x000000FF, printer);
	free (printer);
	if (all->component.map[all->component.player.y][all->component.player.x
		+ 1] == 'C')
	{
		all->component.map[all->component.player.y][all->component.player.x
			+ 1] = '0';
		all->component.collect--;
	}
	draw_tile(all, all->component.player.x + 1, all->component.player.y,
		"./textures/sans_xpm/sans_right_left.xpm");
	draw_tile(all, all->component.player.x, all->component.player.y,
		"./textures/ice_map/floor2.xpm");
	all->component.player.x++;
	all->steps++;
}

void	movingdown(t_all *all)
{
	char	*printer;

	draw_tile(all, 0, 0, "./textures/ice_map/wall.xpm");
	printer = ft_itoa(all->steps);
	mlx_string_put(all->mlx.mlx, all->mlx.mlx_win, 10, 10, 0x000000FF, printer);
	free (printer);
	if (all->component.map[all->component.player.y
			+ 1][all->component.player.x] == 'C')
	{
		all->component.map[all->component.player.y
			+ 1][all->component.player.x] = '0';
		all->component.collect--;
	}
	draw_tile(all, all->component.player.x, all->component.player.y + 1,
		"./textures/sans_xpm/sans_middle.xpm");
	draw_tile(all, all->component.player.x, all->component.player.y,
		"./textures/ice_map/floor2.xpm");
	all->component.player.y++;
	all->steps++;
}

void	movingleft(t_all *all)
{
	char	*printer;

	draw_tile(all, 0, 0, "./textures/ice_map/wall.xpm");
	printer = ft_itoa(all->steps);
	mlx_string_put(all->mlx.mlx, all->mlx.mlx_win, 10, 10, 0x000000FF, printer);
	free (printer);
	if (all->component.map[all->component.player.y][all->component.player.x
		- 1] == 'C')
	{
		all->component.map[all->component.player.y][all->component.player.x
			- 1] = '0';
		all->component.collect--;
	}
	draw_tile(all, all->component.player.x - 1, all->component.player.y,
		"./textures/sans_xpm/sans_left_left.xpm");
	draw_tile(all, all->component.player.x, all->component.player.y,
		"./textures/ice_map/floor2.xpm");
	all->component.player.x--;
	all->steps++;
}
