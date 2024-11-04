/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:07:26 by cfiachet          #+#    #+#             */
/*   Updated: 2024/10/13 15:39:07 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (s2[y] == '\0')
		return (((char *)s1));
	while (s1[i])
	{
		y = 0;
		while ((s1[i + y] == s2[y] && s2[y] && i + y < len))
		{
			y++;
			if (s2[y] == '\0')
				return (((char *)s1) + i);
		}
		i++;
	}
	return (NULL);
}
