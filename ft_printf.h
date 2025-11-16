/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:32:07 by lude-jes          #+#    #+#             */
/*   Updated: 2025/11/16 23:30:04 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);

int	handle_char(char c);
int	handle_string(char *s);
int	handle_int(int c);
int	handle_unsigned(unsigned int c);
int	handle_hex(unsigned int n, int uppercase);
int	handle_hexlong(unsigned long n);
int	handle_ptr(void *ptr);

#endif