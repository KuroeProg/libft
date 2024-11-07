/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:49:01 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/06 17:15:09 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	destsize;
	size_t	srcsize;

	i = 0;
	srcsize = ft_strlen((char *)src);
	destsize = ft_strlen(dst);
	if (dsize <= destsize)
		return (srcsize + dsize);
	while (src[i] && i < dsize - destsize - 1)
	{
		dst[destsize + i] = src[i];
		i++;
	}
	dst[destsize + i] = '\0';
	return (destsize + srcsize);
}
