/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:39:07 by cfiachet          #+#    #+#             */
/*   Updated: 2024/10/21 22:03:24 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy(char const *s1, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_checkn(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	len = 0;
	end = 0;
	while (s1[start] && ft_checkn(s1[start], set) == 1)
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end > start && ft_checkn(s1[end - 1], set))
		end--;
	len = end - start;
	return (ft_copy(&s1[start], len));
}
