/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:01:56 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/06 15:02:31 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new_elem;
	void	*temp;

	if (!f || !lst || !del)
		return (NULL);
	current = NULL;
	while (lst)
	{
		temp = f(lst->content);
		if (!temp)
		{
			ft_lstclear(&current, del);
			return (NULL);
		}
		new_elem = ft_lstnew(temp);
		if (!new_elem)
			return (del(temp), ft_lstclear(&current, del), NULL);
		ft_lstadd_back(&current, new_elem);
		lst = lst->next;
	}
	return (current);
}
