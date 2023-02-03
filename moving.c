/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:11:37 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/31 17:38:44 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkcollect0(t_all *all)
{
	if (all->component.collect == 0)
	{
		all->mlx.img = mlx_xpm_file_to_image(all->mlx.mlx,
				"./textures/exit_xpm/exit2.xpm", &all->mlx.width,
				&all->mlx.height);
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.mlx_win, all->mlx.img,
			(all->component.countexitx) * 64, (all->component.countexity)
			* 64);
	}
}

void	movingall(t_all *all, int keycode)
{
	exiting(all, keycode);
	if ((all->component.map[all->component.player.y
				- 1][all->component.player.x] == '0'
		|| all->component.map[all->component.player.y
			- 1][all->component.player.x] == 'C') && (keycode == 13
		|| keycode == 126))
		(movingup(all), checkcollect0(all));
	else if ((all->component.map[all->component.player.y]
			[all->component.player.x + 1] == '0'
			|| all->component.map[all->component.player.y]
			[all->component.player.x + 1] == 'C') && (keycode == 2
			|| keycode == 124))
		(movingright(all), checkcollect0(all));
	else if ((all->component.map[all->component.player.y
				+ 1][all->component.player.x] == '0'
		|| all->component.map[all->component.player.y
			+ 1][all->component.player.x] == 'C') && (keycode == 1
				|| keycode == 125))
		(movingdown(all), checkcollect0(all));
	else if ((all->component.map[all->component.player.y]
			[all->component.player.x - 1] == '0'
			|| all->component.map[all->component.player.y]
			[all->component.player.x - 1] == 'C') && (keycode == 0
			|| keycode == 123))
		(movingleft(all), checkcollect0(all));
}

int	key_pressed(int keycode, t_all *all)
{
	movingall(all, keycode);
	return (0);
}

void	exiting(t_all *all, int keycode)
{
	if (keycode == 53)
		exit(0);
	if (all->component.collect == 0)
	{
		if (all->component.map[all->component.player.y
				- 1][all->component.player.x] == 'E' && (keycode == 13
				|| keycode == 126))
			(ft_putendl_fd("You Win", 2), exit(1));
		else if (all->component.map[all->component.player.y]
			[all->component.player.x + 1] == 'E'
			&& (keycode == 2 || keycode == 124))
			(ft_putendl_fd("You Win", 2), exit(1));
		else if (all->component.map[all->component.player.y
				+ 1][all->component.player.x] == 'E' && (keycode == 1
					|| keycode == 125))
			(ft_putendl_fd("You Win", 2), exit(1));
		else if (all->component.map[all->component.player.y]
			[all->component.player.x - 1] == 'E' && (keycode == 0
				|| keycode == 123))
			(ft_putendl_fd("You Win", 2), exit(1));
	}
}

void	xpmerror(void *mlximg)
{
	if (!mlximg)
	{
		ft_putendl_fd("Error : xpm emergency", 2);
		exit(1);
	}
}
