/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:43:15 by lude-jes          #+#    #+#             */
/*   Updated: 2025/11/16 17:55:10 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	handle_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	handle_string(char *s)
{
	int	len;

	if (!s)
		return (handle_string("(null)"));
	len = ft_strlen(s);
	write (1, s, len);
	return (len);
}

int	handle_int(int c)
{
	char	*p;
	int		count;

	p = ft_itoa(c);
	if (!p)
		return (0);
	count = handle_string(p);
	free(p);
	return (count);
}

int	handle_unsigned(unsigned int c)
{
	int	count;

	count = 0;
	if (c >= 10)
		count += handle_unsigned(c / 10);
	count += handle_char((c % 10) + '0');
	return (count);
}