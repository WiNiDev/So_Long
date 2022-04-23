/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthoi <mberthoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:30:15 by marvin            #+#    #+#             */
/*   Updated: 2022/04/20 15:39:19 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*substract(char *str, char result[BUFFER_SIZE])
{
	int	e;
	int	i;

	e = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[e] != '\n' && str[e])
		e++;
	if (str[e] == '\n' && str[e])
		e++;
	while (str[e])
	{
		result[i] = str[e];
		i++;
		e++;
	}
	result[i] = '\0';
	return (str);
}

char	*fill_tab(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	if (str)
		free(str);
	return (res);
}

int	read_line(char *res)
{
	int	i;

	i = 0;
	while (res && res[i] != '\n' && res[i])
		i++;
	if (res && res[i] == '\n')
		return (1);
	return (0);
}

char	*gnl_main(int fd, char *buffer)
{
	int			call;
	char		*tempo;
	static char	result[BUFFER_SIZE];

	tempo = ft_strjoin_free(NULL, result);
	call = 0;
	if (!read_line(tempo))
	{
		call = read(fd, buffer, BUFFER_SIZE);
		if (call > -1)
			buffer[call] = '\0';
		while (call > 0)
		{
			tempo = ft_strjoin_free(tempo, buffer);
			if (read_line(tempo) == 1)
				break ;
			call = read(fd, buffer, BUFFER_SIZE);
			buffer[call] = '\0';
		}
	}
	if (call >= 0)
		tempo = fill_tab(substract(tempo, result));
	return (tempo);
}

char	*get_next_line(int fd)
{
	char	*str;
	char	buffer[BUFFER_SIZE + 1];

	str = NULL;
	if (fd < 0 || (BUFFER_SIZE <= 0))
		return (NULL);
	str = gnl_main(fd, buffer);
	if (str && !*str)
	{
		free(str);
		str = NULL;
	}
	return (str);
}
