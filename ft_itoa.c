/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/15 15:52:44 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/15 15:59:12 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoajr(char *s, long nb, int sign);
static int	calcnumlen(long nb);
static char	*revstr(char *str);

char	*ft_itoa(int n)
{
	long	nb;
	int		sign;
	char	*res;

	sign = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		sign = 1;
	}
	res = malloc(calcnumlen(nb) + sign + 1);
	if (res == NULL)
		return (NULL);
	return (itoajr(res, nb, sign));
}

static int	calcnumlen(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*itoajr(char *s, long nb, int sign)
{
	char	*start;

	start = s;
	if (nb == 0)
		*s++ = '0';
	else
	{
		while (nb > 0)
		{
			*s++ = (nb % 10) + '0';
			nb = nb / 10;
		}
	}
	if (sign == 1)
		*s++ = '-';
	*s = '\0';
	revstr(start);
	return (start);
}

static char	*revstr(char *str)
{
	int		len;
	int		i;
	char	ph;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < len / 2)
	{
		ph = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = ph;
		i++;
	}
	return (str);
}
