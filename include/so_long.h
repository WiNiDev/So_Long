/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <mberthoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:40:48 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/14 15:05:58 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "stdio.h"

# define FAILURE 1
# define SUCCESS 0

# define FLOOR "./assets/floor.xpm"
# define WALL "./assets/wall.xpm"
# define COLLECT "./assets/collectible.xpm"
# define END "./assets/end.xpm"
# define DOGR "./assets/dogright.xpm"
# define DOGL "./assets/dogleft.xpm"
# define DOGU "./assets/dogup.xpm"
# define DOGD "./assets/dogdown.xpm"

# define IMG_SIZE 64

typedef struct s_variable
{
	int		nb_line;
	int		nb_caracter;
	int		nb_item;
	int		nb_exit;
	int		nb_spawn;
	int		nb_collect;
	int		nb_player;
	int		pos_i;
	int		pos_j;
	int		value;
	int		pos_x;
	int		pos_y;
	char	**tab;
}	t_variable;

typedef struct s_img
{
	void	*img_floor;
	void	*img_collect;
	void	*img_wall;
	void	*img_dogr;
	void	*img_dogd;
	void	*img_dogl;
	void	*img_dogu;
	void	*img_end;
}	t_img;

typedef struct s_render
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_render;

typedef struct s_stru
{
	t_variable	*v;
	t_render	*r;
	t_img		*i;
}	t_stru;

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(const char *s, int fd);
int		mlx_close(t_stru *stru);
int		print_map(t_render *t_rend, t_variable *t_var, t_img *img);
int		ft_check_error(char *arg, t_variable *t_var);
int		ft_character_error(char *arg, t_variable *t_var);
void	ft_init_var(t_variable *t_var);
int		ft_nb_line(char *map, t_variable *t_var);
int		ft_check_size_map(char *arg, t_variable *t_var);
int		ft_check_character_map(t_variable *t_var);
int		map_to_tab(char *map, t_variable *t_var);
void	print_floor(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_end(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_wall(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_dogu(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_dogd(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_dogl(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_dogr(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_collect(t_render *t_rend, t_variable *t_var, t_img *img);
void	init_str(t_render *t_rend, t_variable *t_var, t_img *img, t_stru *stru);
void	ft_init_var(t_variable *t_var);
void	init_asset(t_render *t_rend, t_img *img);
int		print_map(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_floor(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_wall(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_dogr(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_dogu(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_dogd(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_dogl(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_collect(t_render *t_rend, t_variable *t_var, t_img *img);
void	print_end(t_render *t_rend, t_variable *t_var, t_img *img);
int		mlx_close(t_stru *stru);
int		keypress(int keyy, t_stru *stru);
int		movements(int keyy, t_stru *stru);
int		move_up(t_stru *stru);
int		move_down(t_stru *stru);
int		move_left(t_stru *stru);
int		move_right(t_stru *stru);
void	ft_trips(t_stru *stru);

#endif
