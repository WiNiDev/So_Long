/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:36:29 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/12 13:44:04 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "limits.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(const char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, s + i, 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	if (n < 0 && n != INT_MIN)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	if (n > 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
}

int	map_to_tab(char *map, t_variable *t_var)
{
	int	i;
	int	fd;

	if (!map)
		exit (FAILURE);
	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Invalid file descriptor\n", 2);
		exit (FAILURE);
	}
	t_var->tab = malloc(sizeof(char *) * (t_var->nb_line + 1));
	if (!t_var->tab)
		exit (FAILURE);
	while (i < t_var->nb_line)
	{
		t_var->tab[i] = get_next_line(fd);
		if (t_var->tab[i] == NULL)
			exit (FAILURE);
		i++;
	}
	close (fd);
	t_var->tab[i] = NULL;
	return (SUCCESS);
}
