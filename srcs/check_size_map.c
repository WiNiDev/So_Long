/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:17:17 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/12 14:28:56 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_nb_line(char *map, t_variable *t_var)
{
	char	*str;
	int		fd;
	int		stop;

	stop = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Invalid file descriptor\n", 2);
		exit (FAILURE);
	}
	str = get_next_line(fd);
	t_var->nb_caracter = ft_strlen(str) - 1;
	while (str)
	{
		if (t_var->nb_caracter != ft_strlen(str) - 1)
			stop = 1;
		t_var->nb_line++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	if (t_var->nb_line < 3 || stop == 1 || t_var->nb_caracter < 3)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_check_size_map(char *arg, t_variable *t_var)
{
	if (ft_nb_line(arg, t_var))
		return (FAILURE);
	return (SUCCESS);
}
