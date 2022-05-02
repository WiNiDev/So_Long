/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:37:52 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/20 15:11:03 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	movements(int keyy, t_stru *stru)
{
	if (keyy == 13)
		return (move_up(stru));
	if (keyy == 1)
		return (move_down(stru));
	if (keyy == 0)
		return (move_left(stru));
	if (keyy == 2)
		return (move_right(stru));
	return (0);
}

void	ft_trips(t_stru *stru)
{
	stru->v->value++;
	ft_putstr_fd("Number of trips : ", 1);
	ft_putnbr_fd(stru->v->value, 1);
	write(1, "\n", 1);
}

int	keypress(int keyy, t_stru *stru)
{
	if (keyy == 53)
	{
		mlx_close(stru);
	}
	else if (movements(keyy, stru) == 1)
	{
		ft_trips(stru);
	}
	return (0);
}
