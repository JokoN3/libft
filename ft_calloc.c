/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/15 15:09:06 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/15 15:25:35 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	ts;
	void	*p;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (size <= SIZE_MAX / nmemb)
		ts = nmemb * size;
	else
		return (NULL);
	p = malloc(ts);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, ts);
	return (p);
}
