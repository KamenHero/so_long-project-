/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:08:08 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/04 21:56:35 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_all *all, size_t x, size_t y, char *filename)
{
	if (all->component.map[y][x] == 'P')
		all->component.map[y][x] = '0';
	all->mlx.img = mlx_xpm_file_to_image(all->mlx.mlx,
			filename,
			&all->mlx.width, &all->mlx.height);
	xpmerror(all->mlx.img);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.mlx_win,
		all->mlx.img, x * 64, y * 64);
	mlx_destroy_image(all->mlx.mlx, all->mlx.img);
}

void	showingall(t_all *all, size_t x, size_t y)
{
	if (all->component.map[y][x] == 'E')
		draw_tile(all, x, y, "./textures/exit_xpm/exit1.xpm");
	else if (all->component.map[y][x] == '1'
			&& (y != all->component.county - 1
				&& x == all->component.countx - 1))
		draw_tile(all, x, y, "./textures/ice_map/water.xpm");
	else if (all->component.map[y][x] == '1' && y == 0
			&& y != all->component.countx)
		draw_tile(all, x, y, "./textures/ice_map/wall.xpm");
	else if (all->component.map[y][x] == '1'
		&& (y == all->component.county - 1
		&& x != all->component.countx - 1))
		draw_tile(all, x, y, "./textures/ice_map/water2.xpm");
	else if (all->component.map[y][x] == '1'
			&& x == all->component.countx - 1
			&& y == all->component.county - 1)
		draw_tile(all, x, y, "./textures/ice_map/water3.xpm");
	else if (all->component.map[y][x] == '1'
		|| (all->component.map[y][x] == '1' && x == 0))
		draw_tile(all, x, y, "./textures/ice_map/trees2.xpm");
	else if (all->component.map[y][x] == 'P')
		draw_tile(all, x, y, "./textures/sans_xpm/sans_middle.xpm");
	else if (all->component.map[y][x] == 'C')
		draw_tile(all, x, y, "./textures/hearts_xpm/blue_heart.xpm");
}

void	showing(t_all *all)
{
	size_t	x;
	size_t	y;

	y = 0;
	all->mlx.mlx = mlx_init();
	if (all->component.countx > 5120 / 64 || all->component.county > 2880 / 64)
		(ft_putendl_fd("Error : show me your resolution.", 2), exit (-1));
	all->mlx.mlx_win = mlx_new_window(all->mlx.mlx, 64 * all->component.countx,
			64 * all->component.county, "so_long");
	while (all->component.map[y])
	{
		x = 0;
		while (all->component.map[y][x])
		{
			if (all->component.map[y][x] == '0')
				draw_tile(all, x, y, "./textures/ice_map/floor2.xpm");
			showingall(all, x, y);
			x++;
		}
		y++;
	}
	mlx_hook(all->mlx.mlx_win, 2, 0, key_pressed, all);
	mlx_hook(all->mlx.mlx_win, 17, 0, exitx, all);
}
