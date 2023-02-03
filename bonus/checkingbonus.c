/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingbonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:48:36 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/29 21:26:33 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	checkingloop(t_data *component, int y, int x)
{
	if (component->map[y][x] == 'P')
	{
		component->player_count += 1;
		component->player.x = x;
		component->player.y = y;
	}
	else if (component->map[y][x] == 'C')
		component->collect += 1;
	else if (component->map[y][x] == 'E')
	{
		component->countexitx = x;
		component->countexity = y;
		component->exit += 1;
	}
	else if (component->map[y][x] == 'R')
	{
		ft_lstaddenenmy(&component->enemy, ft_lstnewenemy(x, y));
	}
}

t_data	checking(t_data component)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	component.enemy = NULL;
	while (component.map[y])
	{
		x = 0;
		if (component.map[y + 1]
			&& ft_strlen(component.map[y]) != ft_strlen(component.map[y + 1]))
			component.rectangular += 1;
		while (component.map[y][x])
		{
			checkingloop(&component, y, x);
			x++;
		}
		y++;
	}
	ft_exit(component);
	return (component);
}

t_data	checkwalls(t_data component)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < component.county)
	{
		x = 0;
		while (x < ft_strlenn(component.map[y]))
		{
			component = conditcheck(component, x, y);
			x++;
		}
		y++;
	}
	ft_exit(component);
	return (component);
}

t_data	conditcheck(t_data component, size_t x, size_t y)
{
	if (y == 0 && component.map[y][x] != '1')
		component.wall += 1;
	if (y == component.county - 1 && component.map[y][x] != '1')
		component.wall += 1;
	if (y != 0 && y != component.county - 1 && x == 0
		&& component.map[y][x] != '1')
		component.wall += 1;
	if (y != 0 && y != component.county - 1 && x == ft_strlenn(component.map[y])
		- 1 && component.map[y][x] != '1')
		component.wall += 1;
	return (component);
}

void	checkingothers(t_data component)
{
	int	x;
	int	y;

	y = 0;
	while (component.map[y])
	{
		x = 0;
		while (component.map[y][x])
		{
			if (component.map[y][x] != 'P' && component.map[y][x] != 'C'
				&& component.map[y][x] != 'E' && component.map[y][x] != '0'
				&& component.map[y][x] != '1' && component.map[y][x] != 'R')
			{
				ft_putendl_fd("Error : Wait a minute.. who are you ?", 2);
				exit(-1);
			}
			x++;
		}
		y++;
	}
}
