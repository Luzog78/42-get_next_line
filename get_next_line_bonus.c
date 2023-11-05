/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 06:59:39 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/05 01:46:07 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*global_buffers;
	char			*buff_line;
	size_t			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff_line)
		return (NULL);
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		buff_line[i] = '\0';
		i++;
	}
	if (!ft_read_line(fd, &global_buffers, &buff_line)
		|| !ft_get_buff(fd, &global_buffers)->str)
	{
		ft_free_buff(fd, &global_buffers);
		return (NULL);
	}
	return (ft_get_final_line(fd, &global_buffers));
}

int	ft_read_line(int fd, t_list **global_buffer, char **buff_line)
{
	int		result;
	t_list	*buff;

	result = 1;
	buff = ft_get_buff(fd, global_buffer);
	while (!ft_str_contains(buff->str, '\n'))
	{
		result = read(fd, *buff_line, BUFFER_SIZE);
		if (result < 0)
		{
			free(*buff_line);
			ft_free_buff(fd, global_buffer);
			return (0);
		}
		if (result == 0)
			break ;
		(*buff_line)[result] = '\0';
		buff->str = ft_realloc_join(buff->str, *buff_line);
	}
	free(*buff_line);
	return (1);
}

char	*ft_get_final_line(int fd, t_list **global_buffers)
{
	char	*final_line;
	t_list	*buff;
	size_t	i;
	size_t	j;

	buff = ft_get_buff(fd, global_buffers);
	i = 0;
	while (buff->str[i] && buff->str[i] != '\n')
		i++;
	if (buff->str[i] == '\n')
		i++;
	final_line = malloc(sizeof(char) * (i + 1));
	if (!final_line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		final_line[j] = buff->str[j];
		j++;
	}
	final_line[j] = '\0';
	buff->str = ft_realloc_skip(buff->str, i);
	if (!buff->str)
		ft_free_buff(fd, global_buffers);
	return (final_line);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}
