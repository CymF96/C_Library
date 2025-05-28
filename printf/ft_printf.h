/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:54:24 by cofische          #+#    #+#             */
/*   Updated: 2024/05/06 09:19:28 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *string, ...);
int	printf_format(int c, va_list *ap);
int	printf_char(int c);
int	printf_string(char *str);
int	printf_digit(int ap, int base);
int	printf_hex(int ap, int base);
int	printf_pointer(void *ap);

#endif
