/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:56:34 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/14 15:15:33 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	load_map(t_render *t_rend, t_variable *t_var, t_img *img)
{
	if (t_var->tab[t_var->pos_i][t_var->pos_j] == 'C')
	{
		print_collect(t_rend, t_var, img);
		t_var->nb_collect++;
	}
	else if (t_var->tab[t_var->pos_i][t_var->pos_j] == 'P')
	{
		if (t_var->nb_player == 0)
		{
			print_dogr(t_rend, t_var, img);
			t_var->pos_x = t_var->pos_j;
			t_var->pos_y = t_var->pos_i;
			t_var->nb_player = 1;
		}
		else
			print_floor(t_rend, t_var, img);
	}
	else if (t_var->tab[t_var->pos_i][t_var->pos_j] == '1')
		print_wall(t_rend, t_var, img);
	else if (t_var->tab[t_var->pos_i][t_var->pos_j] == '0')
		print_floor(t_rend, t_var, img);
	else if (t_var->tab[t_var->pos_i][t_var->pos_j] == 'E')
		print_end(t_rend, t_var, img);
	return (0);
}

int	print_map(t_render *t_rend, t_variable *t_var, t_img *img)
{
	t_var->pos_i = 0;
	t_var->pos_j = 0;
	while (t_var->tab[t_var->pos_i])
	{
		while (t_var->tab[t_var->pos_i][t_var->pos_j])
		{
			load_map(t_rend, t_var, img);
			t_var->pos_j++;
		}
		t_var->pos_j = 0;
		t_var->pos_i++;
	}
	t_var->pos_j = t_var->pos_x;
	t_var->pos_i = t_var->pos_y;
	return (0);
}
