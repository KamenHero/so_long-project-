/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:33:41 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/03 22:15:17 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	rivals(t_all *all, t_enemy	*tmp)
{
	while (tmp)
	{
		if (tmp->direct && all->component.map[tmp->y][tmp->x + 1] != '1'
			&& all->component.map[tmp->y][tmp->x + 1] != 'C'
			&& all->component.map[tmp->y][tmp->x + 1] != 'E')
			papyrusright(all, tmp);
		else if (!tmp->direct && all->component.map[tmp->y][tmp->x - 1] != '1'
			&& all->component.map[tmp->y][tmp->x - 1] != 'C'
			&& all->component.map[tmp->y][tmp->x - 1] != 'E')
		{
			all->component.map[tmp->y][tmp->x] = '0';
			draw_tile(all, tmp->x, tmp->y, "./textures/ice_map/floor2.xpm");
			tmp->x--;
			if (all->component.player.x == tmp->x
				&& all->component.player.y == tmp->y)
				(ft_putendl_fd("JOKES ON YOU", 2), exit(0));
			draw_tile(all, tmp->x, tmp->y,
				"./bonus/textures_bonus/papyrusleft.xpm");
		}
		else
			tmp->direct = !tmp->direct;
		tmp = tmp->next;
	}
}

void	papyrusright(t_all *all, t_enemy *tmp)
{
	all->component.map[tmp->y][tmp->x] = '0';
	draw_tile(all, tmp->x, tmp->y, "./textures/ice_map/floor2.xpm");
	tmp->x++;
	if (all->component.player.x == tmp->x
		&& all->component.player.y == tmp->y)
		(ft_putendl_fd("JOKES ON YOU", 2), exit(0));
	draw_tile(all, tmp->x, tmp->y, "./bonus/textures_bonus/papyrusright.xpm");
}

int	anime_loop(t_all *all)
{
	static int	img;
	static int	count;
	t_enemy		*tmp;

	tmp = all->component.enemy;
	if (count++ < 2000)
		return (1);
	rivals(all, tmp);
	if (img == 1)
		draw_tile(all, all->component.player.x,
			all->component.player.y, "bonus/textures_bonus/anim1.xpm");
	else if (img == 2)
		draw_tile(all, all->component.player.x,
			all->component.player.y, "bonus/textures_bonus/anim3.xpm");
	else if (img == 3)
		draw_tile(all, all->component.player.x,
			all->component.player.y, "bonus/textures_bonus/anim4.xpm");
	if (img >= 4)
		img = 0;
	img++;
	count = 0;
	return (0);
}
