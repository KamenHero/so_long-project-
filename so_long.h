/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <oryadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:41:28 by oryadi            #+#    #+#             */
/*   Updated: 2023/02/03 23:04:50 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./gnl/get_next_line.h"
# include <fcntl.h>
# include <libft.h>
# include <mlx.h>

# define WRONG_ARGUMETNS 1

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_data
{
	t_player	player;
	int			space;
	int			wall;
	int			collect;
	int			exit;
	int			player_count;
	int			rectangular;
	size_t		county;
	size_t		countx;
	int			countexitx;
	int			countexity;
	char		**map;
}				t_data;

typedef struct s_check
{
	int			collect;
	int			exit;
	char		**dupp;
}				t_for;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	int			height;
	int			width;
	void		*img;
}				t_mlx;

typedef struct s_all
{
	t_data		component;
	t_mlx		mlx;
	int			steps;
}				t_all;

char			**reading(char *str);
void			ft_exit(t_data component);
t_data			checking(t_data component);
t_data			initialstruct(void);
t_data			checkwalls(t_data component);
size_t			ft_pointerlen(char **ptr);
void			checkingothers(t_data component);
t_data			conditcheck(t_data component, size_t x, size_t y);
char			**mapdup(t_data component);
void			floodfill(int x, int y, t_for *check);
void			ft_exit2(t_data component, t_for check);
void			ft_collcterror(t_data component);
void			readcondit(char *allm);
void			readcondit2(char *tmp);
void			showing(t_all *all);
t_mlx			initialmlx(void);
void			exiting(t_all *all, int keycode);
int				key_pressed(int keycode, t_all *all);
void			ft_ber(char *str);
void			xpmerror(void *mlximg);
void			movingup(t_all *all);
void			movingleft(t_all *all);
void			movingdown(t_all *all);
void			movingright(t_all *all);
void			draw_tile(t_all *all, size_t x, size_t y, char *filename);
void			ft_freed(char **dupp);
int				exitx(void);

#endif
