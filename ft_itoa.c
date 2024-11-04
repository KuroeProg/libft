/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:38:19 by cfiachet          #+#    #+#             */
/*   Updated: 2024/10/21 22:01:54 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_recursive(int nb, char *str)
{
	if (nb >= 10)
		str = ft_recursive(nb / 10, str);
	*str = (nb % 10) + '0';
	return (str + 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_len(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		ft_recursive(-n, str + 1);
	}
	else if (n == 0)
		str[0] = '0';
	else
		ft_recursive(n, str);
	str[size] = '\0';
	return (str);
}
