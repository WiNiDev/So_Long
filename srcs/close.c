/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:16:21 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/12 14:16:51 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx/mlx.h"

int	free_tab(t_stru *stru)
{
	int	i;

	i = 0;
	if (stru->v->tab == NULL)
		return (FAILURE);
	while (stru->v->tab[i])
	{
		free(stru->v->tab[i]);
		i++;
	}
	free(stru->v->tab[i]);
	return (SUCCESS);
}

int	mlx_close(t_stru *stru)
{
	mlx_destroy_image(stru->r->mlx_ptr, stru->i->img_floor);
	mlx_destroy_image(stru->r->mlx_ptr, stru->i->img_collect);
	mlx_destroy_image(stru->r->mlx_ptr, stru->i->img_wall);
	mlx_destroy_image(stru->r->mlx_ptr, stru->i->img_end);
	mlx_destroy_image(stru->r->mlx_ptr, stru->i->img_dogr);
	mlx_destroy_image(stru->r->mlx_ptr, stru->i->img_dogl);
	mlx_destroy_image(stru->r->mlx_ptr, stru->i->img_dogu);
	mlx_destroy_image(stru->r->mlx_ptr, stru->i->img_dogd);
	mlx_destroy_window(stru->r->mlx_ptr, stru->r->win_ptr);
	free_tab(stru);
	exit (SUCCESS);
}
