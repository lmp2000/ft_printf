/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:54:09 by lude-jes          #+#    #+#             */
/*   Updated: 2025/11/04 15:11:46 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = dst;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (*(src + i) && i < size - 1)
	{
		*ptr = src[i];
		ptr++;
		i++;
	}
	*ptr = '\0';
	return (ft_strlen(src));
}
