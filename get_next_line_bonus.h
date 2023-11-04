/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 06:59:36 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 11:08:12 by ysabik           ###   ########.fr       */
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

typedef struct s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
int		ft_str_contains(char *str, char c);
char	*ft_realloc_join(char *s1, char *s2);
char	*ft_realloc_skip(char *str, size_t n);

t_list	*ft_get_buff(int fd, t_list **buffers);
void	ft_free_buff(int fd, t_list **buffers);

#endif