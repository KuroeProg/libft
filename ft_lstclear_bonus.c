/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:19:48 by cfiachet          #+#    #+#             */
/*   Updated: 2024/10/21 18:36:26 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (*lst == NULL)
		return ;
	while (*lst != NULL)
	{
		current = (*lst)->next;
		del((*lst)->content);
		free (*lst);
		*lst = current;
	}
}
