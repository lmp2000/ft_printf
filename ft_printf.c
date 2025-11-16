/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:02:28 by lude-jes          #+#    #+#             */
/*   Updated: 2025/11/16 17:57:15 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	data_type(char c, va_list args)
{
	if (c == 'c')
		return (handle_char((char)va_arg(args, int)));
	else if (c == 's')
		return (handle_string(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (handle_int(va_arg(args, int)));
	else if (c == 'u')
		return (handle_unsigned(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += data_type(format[i], args);
		}
		else
		{
			write (1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}