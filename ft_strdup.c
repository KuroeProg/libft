/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:04:58 by cfiachet          #+#    #+#             */
/*   Updated: 2024/10/13 16:05:07 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s);
	dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (dest);
	else
	{
		while (s[i])
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
