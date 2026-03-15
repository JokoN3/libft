/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/15 15:27:57 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/15 15:37:18 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*r;
	char	*start;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	r = malloc(len + 1);
	if (!r)
		return (NULL);
	start = r;
	while (*s)
	{
		*r = *s;
		r++;
		s++;
	}
	*r = '\0';
	return (start);
}
