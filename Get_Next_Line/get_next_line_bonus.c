/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:20:26 by cofische          #+#    #+#             */
/*   Updated: 2024/05/24 14:44:07 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	create_group_line(int fd, t_list **group_line)
{
	//char	*buffer;
	int		char_read;
	t_list	*last_node;
	t_list	*new_node;

	if (group_line == NULL)
		return ;
	while (return_line_found(*group_line) == 0)
	{
		last_node = lst_node(group_line[fd]);
		new_node = malloc(sizeof(t_list));
		if (new_node == NULL)
			return ;
		char_read = read(fd, new_node->buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(new_node->buf);
			free(new_node);
			return ;
		}
		new_node->buf[char_read] = '\0';
		new_node->next = NULL;
		if (last_node == NULL)
			group_line[fd] = new_node;
		else
			last_node->next = new_node;
	}
}

void	clean_nodes(t_list **group_line)
{
	t_list	*last_node;
	char	*buffer;
	int 	i;

//	first_node = malloc(sizeof(t_list));
	if (group_line == NULL)// || first_node == NULL)
		return ;
	while (*group_line != NULL && (*group_line)->next != NULL)
	{
		last_node = (*group_line)->next;
		free((*group_line)->buf);
		free(*group_line);
		*group_line = last_node;
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL && last_node->buf[0] == '\0')
	{
		free(last_node->buf);
		free(last_node);
		return ;
	}
	i = 0;
	while (last_node->buf[i] != '\0' && last_node->buf[i] != '\n')
		i++;
	if (last_node->buf[i] == '\n')
		i++;
	ft_memmove(last_node->buf, last_node->buf[i], BUFFER_SIZE + 1 - i);
}

void	next_group_line(t_list **group_line)
{
	t_list	*last_node;
	int		i;
	int		k;
	char	*buffer;

	if (*group_line == NULL)
		return ;
	last_node = lst_node(*group_line);
	if (last_node == NULL)
		return ;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return ;

	clean_nodes(group_line, buffer);
}

char	*copy_line(t_list *node_line)
{
	int		line_len;
	char	*str;

	if (node_line == NULL)
		return (NULL);
	line_len = line_strlen(node_line);
	str = malloc(line_len + 1);
	if (str == NULL)
		return (NULL);
	combined_lines(node_line, str);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line_to_read;
	static t_list	*group_line[4096];

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	create_group_line(fd, group_line);
	if (group_line[fd] == NULL)
		return (NULL);
	line_to_read = copy_line(group_line[fd]);
	next_group_line(&group_line[fd]);
	return (line_to_read);
}
