/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:43:15 by lude-jes          #+#    #+#             */
/*   Updated: 2025/11/16 23:36:02 by lude-jes         ###   ########.fr       */
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
	int	count;

	if (!s)
		return (handle_string("(null)"));
	count = ft_strlen(s);
	write (1, s, count);
	return (count);
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

int	handle_hex(unsigned int n, int uppercase)
{
	char	*base;
	int		count;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += handle_hex(n / 16, uppercase);
	count += handle_char(base[n % 16]);
	return (count);
}

int	handle_hexlong(unsigned long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += handle_hexlong(n / 16);
	count += handle_char(base[n % 16]);
	return (count);
}

int	handle_ptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (handle_string("(nil)"));
	count = 0;
	address = (unsigned long)ptr;
	count += handle_string("0x");
	count += handle_hexlong(address);
	return (count);
}