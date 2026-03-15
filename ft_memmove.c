/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   !!!!!ft_memmove.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 16:35:22 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/15 15:05:28 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	p = (char *)dest;
	s = (const char *)src;
	if (s > p)
	{
		while (n-- > 0)
			*p++ = *s++;
	}
	else
	{
		p = p + n;
		s = s + n;
		while (n-- > 0)
			*(--p) = *(--s);
	}
	return (dest);
}
