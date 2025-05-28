/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:06:52 by cofische          #+#    #+#             */
/*   Updated: 2024/05/24 14:43:31 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	return_line_found(t_list *node_line)
{
	int		i;

	if (node_line == NULL)
		return (0);
	while (node_line != NULL)
	{
		i = 0;
		while (node_line->buf[i] != '\0' && i < BUFFER_SIZE)
		{
			if (node_line->buf[i] == '\n')
				return (1);
			i++;
		}
		node_line = node_line->next;
	}
	return (0);
}

t_list	*lst_node(t_list *node_line)
{
	if (node_line == NULL)
		return (NULL);
	while (node_line != NULL && node_line->next != NULL)
		node_line = node_line->next;
	return (node_line);
}

void	add_to_line_group(char *buffer, t_list **group_line)
{
	t_list	*last_node;
	t_list	*new_node;

	last_node = lst_node(*group_line);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->buf = buffer;
	new_node->next = NULL;
	if (last_node == NULL)
		*group_line = new_node;
	else
		last_node->next = new_node;
}

size_t	line_strlen(t_list *node_line)
{
	int	i;
	int	k;

	if (node_line == NULL)
		return (0);
	k = 0;
	while (node_line != NULL)
	{
		i = 0;
		while (node_line->buf[i] != '\0')
		{
			if (node_line->buf[i] == '\n')
				return (k + 1);
			i++;
			k++;
		}
		node_line = node_line->next;
	}
	return (k);
}

void	combined_lines(t_list *node_line, char *str)
{
	int		i;
	int		k;

	k = 0;
	while (node_line != NULL)
	{
		i = 0;
		while (node_line->buf[i] != '\0')
		{
			str[k] = node_line->buf[i];
			if (node_line->buf[i] == '\n')
			{
				str[k + 1] = '\0';
				return ;
			}
			i++;
			k++;
		}
		node_line = node_line->next;
	}
	str[k] = '\0';
}
