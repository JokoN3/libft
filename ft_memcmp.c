/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/13 14:46:08 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/13 14:53:47 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*p1 > *p2)
			return (1);
		else if (*p2 > *p1)
			return (-1);
		p1++;
		p2++;
	}
	return (0);
}
