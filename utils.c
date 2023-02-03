/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:29:19 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/31 16:37:19 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	initialstruct(void)
{
	t_data	component;

	component.collect = 0;
	component.exit = 0;
	component.map = 0;
	component.player_count = 0;
	component.rectangular = 0;
	component.space = 0;
	component.wall = 0;
	component.countexitx = 0;
	component.countexity = 0;
	return (component);
}

size_t	ft_pointerlen(char **ptr)
{
	size_t	count;

	count = 0;
	while (ptr[count])
		count++;
	return (count);
}

void	ft_exit(t_data component)
{
	if (component.player_count != 1 || component.exit != 1)
	{
		if (component.player_count != 1)
			ft_putendl_fd("Error : Here comes a new challenger.", 2);
		else if (component.exit != 1)
			ft_putendl_fd("Error : It will be a hard choice.", 2);
		exit(-1);
	}
	if (component.collect < 1)
	{
		ft_putendl_fd("Error : nothing to collect.", 2);
		exit(-1);
	}
	if (component.rectangular != 0)
	{
		ft_putendl_fd("Error : I'm a flat earth believer.", 2);
		exit(-1);
	}
	if (component.wall != 0)
	{
		ft_putendl_fd("Error : we need to build a wall.", 2);
		exit(-1);
	}
}

char	**mapdup(t_data component)
{
	size_t	y;
	char	**dupp;

	y = 0;
	dupp = ft_calloc(component.county + 1, sizeof(char *));
	while (y < component.county + 1)
	{
		if (y == component.county)
		{
			dupp[y] = NULL;
			break ;
		}
		dupp[y] = ft_strdupp(component.map[y]);
		y++;
	}
	dupp[y] = NULL;
	return (dupp);
}

void	ft_exit2(t_data component, t_for check)
{
	ft_freed (check.dupp);
	if (component.collect != check.collect || component.exit != check.exit)
	{
		ft_putendl_fd("Error : Show me the way.", 2);
		exit(-1);
	}
}
