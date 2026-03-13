/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/13 14:54:07 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/13 14:56:53 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[j] && j < len)
	{
		i = 0;
		while (big[j + i] == little[i] && (j + i) < len)
		{
			i++;
			if (little[i] == '\0')
				return ((char *)&big[j]);
		}
		j++;
	}
	return (0);
}
