/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:07:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/01/20 17:49:19 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	wdcount(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

static int	wdlen(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		counter++;
		i++;
	}
	return (counter);
}

static char	*tstr(size_t size)
{
	char	*t;
	size_t	i;

	i = 0;
	t = malloc(sizeof(*t) * (size + 1));
	if (!t)
		return (NULL);
	else
	{
		while (i <= size)
		{
			t[i] = '\0';
			i++;
		}
	}
	return (t);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	split = (char **)malloc(sizeof(*split) * (wdcount(s, c) + 1));
	if (!s || !split)
		return (0);
	i = -1;
	j = 0;
	while (++i < wdcount(s, c))
	{
		k = 0;
		split[i] = tstr(wdlen(&s[j], c));
		if (!split[i])
			split[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			split[i][k++] = s[j++];
		split[i][k] = '\0';
	}
	split[i] = 0;
	return (split);
}
