/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:16:08 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/06 14:55:51 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char sep)
{
	return (c == sep);
}

static char	*ft_mallocworld(const char *str, char c)
{
	size_t	i;
	char	*strf;

	i = 0;
	while (str[i] && !ft_check(str[i], c))
		i++;
	strf = (char *)malloc(sizeof(char) * (i + 1));
	if (!strf)
		return (NULL);
	i = 0;
	while (str[i] && !ft_check(str[i], c))
	{
		strf[i] = str[i];
		i++;
	}
	strf[i] = '\0';
	return (strf);
}

static void	free_tab(char **tab, size_t i)
{
	while (i > 0)
	{
		free(tab[i - 1]);
		i--;
	}
	free(tab);
}

static size_t	ft_countword(char const *s, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_check(s[i], sep))
			i++;
		if (s[i] && !ft_check(s[i], sep))
		{
			count++;
			while (s[i] && !ft_check(s[i], sep))
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char		**tab;

	i = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s && (ft_check(*s, c)))
			s++;
		if (*s && !ft_check(*s, c))
		{
			tab[i] = ft_mallocworld(s, c);
			if (!tab[i])
				return (free_tab(tab, i), NULL);
			i++;
			while (*s && !ft_check(*s, c))
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
