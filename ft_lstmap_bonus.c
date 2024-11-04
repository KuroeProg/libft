/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:01:56 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/04 19:46:58 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new;
	t_list	*new_elem;

	if (!f || !lst || !del)
		return (NULL);
	current = ft_lstnew(f(lst->content));
	if (!current)
		return (NULL);
	new = current;
	lst = lst->next;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&current, del);
			return (NULL);
		}
		new->next = new_elem;
		new = new->next;
		lst = lst->next;
	}
	return (current);
}
