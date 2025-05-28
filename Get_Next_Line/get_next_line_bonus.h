/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:21:00 by cofische          #+#    #+#             */
/*   Updated: 2024/05/21 15:18:38 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			buf[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	combined_lines(t_list *node_line, char *str);
size_t	line_strlen(t_list *node_line);
//void	add_to_line_group(char *buffer, t_list **group_line, int fd);
t_list	*lst_node(t_list *node_line);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		return_line_found(t_list *node_line);
void	next_group_line(t_list **group_line);
void	clean_nodes(t_list **group_line);
char	*copy_line(t_list *node_line);
void	create_group_line(int fd, t_list **group_line);

#endif
