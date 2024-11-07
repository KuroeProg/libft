/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:48:41 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/07 13:51:35 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*tab;
	size_t	total;

	total = num * size;
	if (num != 0 && total / num != size)
		return (NULL);
	tab = malloc(num * size);
	if (tab == NULL)
		return (tab);
	ft_bzero(tab, num * size);
	return (tab);
}
