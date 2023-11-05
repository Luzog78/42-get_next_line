/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 06:59:36 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/05 02:51:19 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);

int		ft_read_line(int fd, char **global_buffer, char **buff_line);
char	*ft_get_final_line(char **buffer);

size_t	ft_strlen(char *str);
int		ft_str_contains(char *str, char c);
char	*ft_realloc_join(char *s1, char *s2);
char	*ft_realloc_skip(char *str, size_t n);

#endif