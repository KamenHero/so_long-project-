/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:17:17 by oryadi            #+#    #+#             */
/*   Updated: 2023/01/31 16:56:07 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_all	all;
	t_for	check;

	(void)argc;
	if (argc != 2)
		(ft_putendl_fd("error", 2), exit(WRONG_ARGUMETNS));
	ft_ber(argv[1]);
	all.component = initialstruct();
	check.collect = 0;
	check.exit = 0;
	all.steps = 1;
	all.component.map = reading(argv[1]);
	all.component.county = ft_pointerlen(all.component.map);
	all.component.countx = ft_strlenn(all.component.map[0]);
	all.component = checking(all.component);
	all.component = checkwalls(all.component);
	checkingothers(all.component);
	check.dupp = mapdup(all.component);
	floodfill(all.component.player.x, all.component.player.y, &check);
	ft_exit2(all.component, check);
	all.mlx = initialmlx();
	showing(&all);
	mlx_loop_hook(all.mlx.mlx, anime_loop, &all);
	mlx_loop(all.mlx.mlx);
	return (0);
}
