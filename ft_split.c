/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/15 15:42:59 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/15 15:51:51 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**splitjr(const char *s, char c, char **res, int wordcount);
static char	**freesplit(char **str, int i);
static int	countwords(const char *str, char c);

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		wordcount;

	if (!s)
		return (NULL);
	wordcount = countwords(s, c);
	res = malloc((sizeof(char *)) * (wordcount + 1));
	if (!res)
		return (NULL);
	res = splitjr(s, c, res, wordcount);
	return (res);
}

static char	**splitjr(const char *s, char c, char **res, int wordcount)
{
	int	i;
	int	word;
	int	wordlen;

	i = 0;
	word = 0;
	wordlen = 0;
	while (word < wordcount)
	{
		wordlen = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			wordlen++;
		}
		res[word] = ft_substr(s, i - wordlen, wordlen);
		if (!res[word])
			return (freesplit(res, word));
		word++;
	}
	res[word] = NULL;
	return (res);
}

static char	**freesplit(char **arr, int i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static int	countwords(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (words);
}
