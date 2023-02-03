/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movingdirecbonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:36:08 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/31 17:47:09 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy	*ft_lstnewenemy(int x, int y)
{
	t_enemy	*node;

	node = malloc(sizeof(t_enemy));
	if (!node)
		return (NULL);
	node->x = x;
	node->y = y;
	node->direct = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstaddenenmy(t_enemy **enemy, t_enemy *new)
{
	new->next = *enemy;
	*enemy = new;
}

void	exiting2(t_all *all, int keycode)
{
	t_enemy	*tmp;

	tmp = all->component.enemy;
	while (tmp)
	{
		if (all->component.player.x == tmp->x
			&& all->component.player.y - 1 == tmp->y
			&& (keycode == 13 || keycode == 126))
			(ft_putendl_fd("JOKES ON YOU", 2), exit(1));
		else if (all->component.player.x + 1 == tmp->x
			&& all->component.player.y == tmp->y
			&& (keycode == 2 || keycode == 124))
			(ft_putendl_fd("JOKES ON YOU", 2), exit(1));
		else if (all->component.player.x == tmp->x
			&& all->component.player.y + 1 == tmp->y
			&& (keycode == 1 || keycode == 125))
			(ft_putendl_fd("JOKES ON YOU", 2), exit(1));
		else if (all->component.player.x - 1 == tmp->x
			&& all->component.player.y == tmp->y
			&& (keycode == 0 || keycode == 123))
			(ft_putendl_fd("JOKES ON YOU", 2), exit(1));
		tmp = tmp->next;
	}
}
