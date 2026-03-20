/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/15 18:10:28 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/20 17:27:38 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node;
	void	*content;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		if (f)
			content = f(lst->content);
		else
			content = lst->content;
		node = ft_lstnew(content);
		if (!node)
		{
			if (f)
				del(content);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, node);
		lst = lst->next;
	}
	return (res);
}
