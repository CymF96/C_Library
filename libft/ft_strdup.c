/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strdup.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cofische <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/04/18 16:14:42 by cofische		   #+#	  #+#			  */
/*	 Updated: 2024/04/18 16:16:57 by cofische		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	size;

	if (str == NULL)
		return (NULL);
	size = ft_strlen(str) + 1;
	ptr = (char *)malloc((size) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, str, size);
	ptr[size - 1] = '\0';
	return (ptr);
}
