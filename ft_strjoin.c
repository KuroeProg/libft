/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:16:35 by cfiachet          #+#    #+#             */
/*   Updated: 2024/10/15 20:16:40 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*strf;
	size_t	i;
	size_t	y;

	y = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	strf = (char *)malloc(size + 1);
	if (!strf)
		return (NULL);
	while (s1[i])
	{
		strf[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		strf[i + y] = s2[y];
		y++;
	}
	strf[i + y] = '\0';
	return (strf);
}
