/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_asset_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:06:39 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/12 14:13:38 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx/mlx.h"

void	print_dogl(t_render *t_rend, t_variable *t_var, t_img *img)
{
	mlx_put_image_to_window(t_rend->mlx_ptr, t_rend->win_ptr,
		img->img_dogl, 64 * t_var->pos_j, 64 * t_var->pos_i);
}

void	print_collect(t_render *t_rend, t_variable *t_var, t_img *img)
{
	mlx_put_image_to_window(t_rend->mlx_ptr, t_rend->win_ptr,
		img->img_collect, 64 * t_var->pos_j, 64 * t_var->pos_i);
}

void	print_end(t_render *t_rend, t_variable *t_var, t_img *img)
{
	mlx_put_image_to_window(t_rend->mlx_ptr, t_rend->win_ptr,
		img->img_end, 64 * t_var->pos_j, 64 * t_var->pos_i);
}
