/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:38:03 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/14 15:06:35 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx/mlx.h"

void	ft_init_var(t_variable *t_var)
{
	t_var->nb_line = 0;
	t_var->nb_caracter = 0;
	t_var->nb_spawn = 0;
	t_var->nb_item = 0;
	t_var->nb_exit = 0;
	t_var->pos_x = 0;
	t_var->pos_y = 0;
	t_var->value = 0;
	t_var->nb_player = 0;
	t_var->nb_collect = 0;
}

void	init_str(t_render *t_rend, t_variable *t_var, t_img *img, t_stru *stru)
{
	stru->v = t_var;
	stru->r = t_rend;
	stru->i = img;
}

void	init_asset(t_render *t_rend, t_img *img)
{
	int	img_width;
	int	img_height;

	img->img_collect = mlx_xpm_file_to_image(t_rend->mlx_ptr,
			COLLECT, &img_width, &img_height);
	img->img_end = mlx_xpm_file_to_image(t_rend->mlx_ptr,
			END, &img_width, &img_height);
	img->img_wall = mlx_xpm_file_to_image(t_rend->mlx_ptr,
			WALL, &img_width, &img_height);
	img->img_floor = mlx_xpm_file_to_image(t_rend->mlx_ptr,
			FLOOR, &img_width, &img_height);
	img->img_dogu = mlx_xpm_file_to_image(t_rend->mlx_ptr,
			DOGU, &img_width, &img_height);
	img->img_dogd = mlx_xpm_file_to_image(t_rend->mlx_ptr,
			DOGD, &img_width, &img_height);
	img->img_dogl = mlx_xpm_file_to_image(t_rend->mlx_ptr,
			DOGL, &img_width, &img_height);
	img->img_dogr = mlx_xpm_file_to_image(t_rend->mlx_ptr,
			DOGR, &img_width, &img_height);
}
