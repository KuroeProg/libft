/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:33:16 by cfiachet          #+#    #+#             */
/*   Updated: 2024/10/21 19:51:39 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*strf;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	strf = (char *)malloc(sizeof(char) * (len + 1));
	if (!strf)
		return (NULL);
	while (i < len)
	{
		strf[i] = s[start + i];
		i++;
	}
	strf[len] = '\0';
	return (strf);
}
