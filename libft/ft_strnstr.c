/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-jes <lude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:49:24 by lude-jes          #+#    #+#             */
/*   Updated: 2025/11/04 15:40:04 by lude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	pos;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		pos = i + j;
		while (needle[j] && haystack[pos] && pos < len
			&& haystack[pos] == needle[j])
		{
			j++;
			pos = i + j;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
