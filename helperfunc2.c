/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:29:29 by lude-jes          #+#    #+#             */
/*   Updated: 2025/11/20 15:36:57 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

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
