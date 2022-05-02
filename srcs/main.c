/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <mberthoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:39:54 by mberthoi          #+#    #+#             */
/*   Updated: 2022/04/20 16:20:24 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx/mlx.h"

int	main(int ac, char **av)
{
	t_render	t_rend;
	t_variable	t_var;
	t_img		img;
	t_stru		stru;

	if (ac != 2)
	{
		ft_putstr_fd("Invalid arguments\n", 2);
		return (FAILURE);
	}
	ft_init_var(&t_var);
	ft_check_error(av[1], &t_var);
	ft_character_error(av[1], &t_var);
	t_rend.mlx_ptr = mlx_init();
	t_rend.win_ptr = mlx_new_window(t_rend.mlx_ptr, 64 * t_var.nb_caracter,
			64 * t_var.nb_line, "The Adventures of Sarco");
	init_asset(&t_rend, &img);
	print_map(&t_rend, &t_var, &img);
	init_str(&t_rend, &t_var, &img, &stru);
	mlx_key_hook(t_rend.win_ptr, keypress, &stru);
	mlx_hook(t_rend.win_ptr, 17, 0, mlx_close, &stru);
	mlx_loop(t_rend.mlx_ptr);
	return (SUCCESS);
}
