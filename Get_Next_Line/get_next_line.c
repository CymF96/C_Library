/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:20:26 by cofische          #+#    #+#             */
/*   Updated: 2024/05/21 14:13:07 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_group_line(int fd, t_list **group_line)
{
	char	*buffer;
	int		char_read;

	if (group_line == NULL)
		return ;
	while (return_line_found(*group_line) == 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		add_to_line_group(buffer, group_line);
	}
}

void	clean_nodes(t_list **group_line, char *buffer)
{
	t_list	*temp_node;
	t_list	*first_node;

	first_node = malloc(sizeof(t_list));
	if (group_line == NULL || first_node == NULL)
		return ;
	while (*group_line != NULL)
	{
		temp_node = (*group_line)->next;
		free((*group_line)->buf);
		free(*group_line);
		*group_line = temp_node;
	}
	*group_line = NULL;
	first_node->buf = buffer;
	first_node->next = NULL;
	if (first_node->buf[0] == '\0')
	{
		free(first_node->buf);
		free(first_node);
		return ;
	}
	*group_line = first_node;
}

void	next_group_line(t_list **group_line)
{
	t_list	*last_node;
	int		i;
	int		k;
	char	*buffer;

	if (group_line == NULL)
		return ;
	last_node = lst_node(*group_line);
	if (last_node == NULL)
		return ;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return ;
	i = 0;
	k = 0;
	while (last_node->buf[i] != '\0' && last_node->buf[i] != '\n')
		i++;
	if (last_node->buf[i] == '\n')
		i++;
	while (last_node->buf[i] != '\0')
		buffer[k++] = last_node->buf[i++];
	buffer[k] = '\0';
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
	static t_list	*group_line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_group_line(fd, &group_line);
	if (group_line == NULL)
		return (NULL);
	line_to_read = copy_line(group_line);
	next_group_line(&group_line);
	return (line_to_read);
}
