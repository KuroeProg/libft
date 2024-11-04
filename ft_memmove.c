/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:33:08 by cfiachet          #+#    #+#             */
/*   Updated: 2024/10/15 14:40:55 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t						i;
	const unsigned char			*s;
	unsigned char				*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
