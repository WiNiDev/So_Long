/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <mberthoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:44:30 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/20 15:12:30 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_up(t_stru *stru)
{
	if (stru->v->tab[stru->v->pos_i - 1][stru->v->pos_j] != '1')
	{
		if (stru->v->tab[stru->v->pos_i - 1][stru->v->pos_j] == 'C')
			stru->v->nb_collect--;
		else if (stru->v->tab[stru->v->pos_i - 1][stru->v->pos_j] == 'E'
				&& stru->v->nb_collect != 0)
			return (0);
		else if (stru->v->tab[stru->v->pos_i - 1][stru->v->pos_j] == 'E'
				&& stru->v->nb_collect == 0)
		{
			ft_trips(stru);
			mlx_close(stru);
		}
		stru->v->tab[stru->v->pos_i][stru->v->pos_j] = '0';
		stru->v->tab[stru->v->pos_i - 1][stru->v->pos_j] = 'P';
		print_floor(stru->r, stru->v, stru->i);
		stru->v->pos_i--;
		print_dogu(stru->r, stru->v, stru->i);
		return (1);
	}
	return (0);
}

int	move_down(t_stru *stru)
{
	if (stru->v->tab[stru->v->pos_i + 1][stru->v->pos_j] != '1')
	{
		if (stru->v->tab[stru->v->pos_i + 1][stru->v->pos_j] == 'C')
		stru->v->nb_collect--;
		else if (stru->v->tab[stru->v->pos_i + 1][stru->v->pos_j] == 'E'
				&& stru->v->nb_collect != 0)
			return (0);
		else if (stru->v->tab[stru->v->pos_i + 1][stru->v->pos_j] == 'E'
				&& stru->v->nb_collect == 0)
		{
			ft_trips(stru);
			mlx_close(stru);
		}
		stru->v->tab[stru->v->pos_i][stru->v->pos_j] = '0';
		stru->v->tab[stru->v->pos_i + 1][stru->v->pos_j] = 'P';
		print_floor(stru->r, stru->v, stru->i);
		stru->v->pos_i++;
		print_dogd(stru->r, stru->v, stru->i);
		return (1);
	}
	return (0);
}

int	move_left(t_stru *stru)
{
	if (stru->v->tab[stru->v->pos_i][stru->v->pos_j - 1] != '1')
	{
		if (stru->v->tab[stru->v->pos_i][stru->v->pos_j - 1] == 'C')
			stru->v->nb_collect--;
		else if (stru->v->tab[stru->v->pos_i][stru->v->pos_j - 1] == 'E'
				&& stru->v->nb_collect != 0)
			return (0);
		else if (stru->v->tab[stru->v->pos_i][stru->v->pos_j - 1] == 'E'
				&& stru->v->nb_collect == 0)
		{
			ft_trips(stru);
			mlx_close(stru);
		}
		stru->v->tab[stru->v->pos_i][stru->v->pos_j] = '0';
		stru->v->tab[stru->v->pos_i][stru->v->pos_j - 1] = 'P';
		print_floor(stru->r, stru->v, stru->i);
		stru->v->pos_j--;
		print_dogl(stru->r, stru->v, stru->i);
		return (1);
	}
	return (0);
}

int	move_right(t_stru *stru)
{
	if (stru->v->tab[stru->v->pos_i][stru->v->pos_j + 1] != '1')
	{
		if (stru->v->tab[stru->v->pos_i][stru->v->pos_j + 1] == 'C')
			stru->v->nb_collect--;
		else if (stru->v->tab[stru->v->pos_i][stru->v->pos_j + 1] == 'E'
				&& stru->v->nb_collect != 0)
			return (0);
		else if (stru->v->tab[stru->v->pos_i][stru->v->pos_j + 1] == 'E'
				&& stru->v->nb_collect == 0)
		{
			ft_trips(stru);
			mlx_close(stru);
		}
		stru->v->tab[stru->v->pos_i][stru->v->pos_j] = '0';
		stru->v->tab[stru->v->pos_i][stru->v->pos_j + 1] = 'P';
		print_floor(stru->r, stru->v, stru->i);
		stru->v->pos_j++;
		print_dogr(stru->r, stru->v, stru->i);
		return (1);
	}
	return (0);
}
