/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movingdirec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:24:50 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/31 17:39:19 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movingup(t_all *all)
{
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
	ft_putnbr_fd(all->steps, 1);
	write(1, "\n", 1);
	all->steps++;
}

void	movingright(t_all *all)
{
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
	ft_putnbr_fd(all->steps, 1);
	write(1, "\n", 1);
	all->steps++;
}

void	movingdown(t_all *all)
{
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
	ft_putnbr_fd(all->steps, 1);
	write(1, "\n", 1);
	all->steps++;
}

void	movingleft(t_all *all)
{
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
	ft_putnbr_fd(all->steps, 1);
	write(1, "\n", 1);
	all->steps++;
}
