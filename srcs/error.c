/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:05:05 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/12 14:08:19 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_extension(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	if (arg[i - 4] == '.' && arg[i - 3] == 'b'
		&& arg[i - 2] == 'e' && arg[i - 1] == 'r' && arg[i] == '\0')
		return (SUCCESS);
	ft_putstr_fd("Error\nInvalid map extension\n", 2);
	exit (FAILURE);
}

int	ft_check_error(char *arg, t_variable *t_var)
{
	ft_check_extension(arg);
	if (ft_check_size_map(arg, t_var) == FAILURE)
	{
		ft_putstr_fd("Error\nInvalid size map\n", 2);
		exit (FAILURE);
	}
	return (SUCCESS);
}

int	ft_character_error(char *arg, t_variable *t_var)
{
	map_to_tab(arg, t_var);
	if (ft_check_character_map(t_var) == FAILURE)
	{
		ft_putstr_fd("Error\nInvalid caracter map\n", 2);
		exit (FAILURE);
	}
	return (SUCCESS);
}
