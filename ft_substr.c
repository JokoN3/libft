/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/15 15:30:49 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/15 15:33:08 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (len-- > 0 && s[i + start])
		i++;
	s += start;
	res = malloc(i + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s, i + 1);
	return (res);
}
