/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 10:51:18 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 18:24:16 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count_words(const char *s, char c)
{
	int		count;
	int		insub;

	insub = 0;
	count = 0;
	while (*s != '\0')
	{
		if (insub == 1 && *s == c)
			insub = 0;
		else if (insub == 0 && *s != c)
		{
			insub = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		ft_wordlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	word_count = ft_count_words(s, c);
	t = (char **)malloc(sizeof(char*) * (word_count + 1));
	if (t == NULL)
		return (NULL);
	while (word_count--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[i] = ft_strsub(s, 0, ft_wordlen(s, c));
		if (t[i] == NULL)
			return (NULL);
		s += ft_strlen(t[i]);
		i++;
	}
	t[i] = NULL;
	return (t);
}
