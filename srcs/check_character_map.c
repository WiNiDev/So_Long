/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_character_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:19:15 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/12 14:29:24 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_caracter_map_three(t_variable *t_var)
{
	int	i;
	int	j;

	i = -1;
	while (++i < t_var->nb_line)
	{
		j = 0;
		while (j < t_var->nb_caracter)
		{
			if (t_var->tab[i][j] != '1' && t_var->tab[i][j] != '0'
				&& t_var->tab[i][j] != 'P' && t_var->tab[i][j] != 'C'
				&& t_var->tab[i][j] != 'E')
				return (FAILURE);
			if (t_var->tab[i][j] == 'P')
				t_var->nb_spawn = 1;
			if (t_var->tab[i][j] == 'E')
				t_var->nb_exit = 1;
			if (t_var->tab[i][j] == 'C')
				t_var->nb_item = 1;
			j++;
		}
	}
	if (t_var->nb_spawn != 1 || t_var->nb_item != 1 || t_var->nb_exit != 1)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_check_caracter_map_two(t_variable *t_var)
{
	int	i;

	i = 0;
	while (i < t_var->nb_line)
	{
		if (t_var->tab[i][0] != '1')
			return (FAILURE);
		i++;
	}
	i = 0;
	while (i < t_var->nb_line)
	{
		if (t_var->tab[i][t_var->nb_caracter - 1] != '1')
			return (FAILURE);
		i++;
	}
	if (ft_check_caracter_map_three(t_var) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_check_character_map(t_variable *t_var)
{
	int	i;

	i = 0;
	while (i < t_var->nb_caracter)
		if (t_var->tab[0][i++] != '1')
			return (FAILURE);
	i = 0;
	while (i < t_var->nb_caracter)
	{
		if (t_var->tab[t_var->nb_line - 1][i] != '1')
			return (FAILURE);
		i++;
	}
	if (ft_check_caracter_map_two(t_var) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
