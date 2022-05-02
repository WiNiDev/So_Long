/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_asset_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:13:56 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/14 15:04:57 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx/mlx.h"

void	print_floor(t_render *t_rend, t_variable *t_var, t_img *img)
{
	mlx_put_image_to_window(t_rend->mlx_ptr, t_rend->win_ptr,
		img->img_floor, 64 * t_var->pos_j, 64 * t_var->pos_i);
}

void	print_wall(t_render *t_rend, t_variable *t_var, t_img *img)
{
	mlx_put_image_to_window(t_rend->mlx_ptr, t_rend->win_ptr,
		img->img_wall, 64 * t_var->pos_j, 64 * t_var->pos_i);
}

void	print_dogr(t_render *t_rend, t_variable *t_var, t_img *img)
{
	mlx_put_image_to_window(t_rend->mlx_ptr, t_rend->win_ptr,
		img->img_dogr, 64 * t_var->pos_j, 64 * t_var->pos_i);
}

void	print_dogu(t_render *t_rend, t_variable *t_var, t_img *img)
{
	mlx_put_image_to_window(t_rend->mlx_ptr, t_rend->win_ptr,
		img->img_dogu, 64 * t_var->pos_j, 64 * t_var->pos_i);
}

void	print_dogd(t_render *t_rend, t_variable *t_var, t_img *img)
{
	mlx_put_image_to_window(t_rend->mlx_ptr, t_rend->win_ptr,
		img->img_dogd, 64 * t_var->pos_j, 64 * t_var->pos_i);
}
