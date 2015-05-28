/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 18:25:21 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 18:49:56 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		count_words(char *s)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	if (!ft_isspace(s[i]))
		wc++;
	while (s[++i])
	{
		if (s[i] && !ft_isspace(s[i]) && ft_isspace(s[i - 1]))
			wc++;
	}
	return (wc);
}

int		word_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	return (i);
}

char	**ft_spaces_split(char *s)
{
	char	**ret;
	int		wc;
	int		i;
	int		j;

	wc = count_words(s);
	ret = (char**)malloc(sizeof(char*) * (wc + 1));
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
		{
			ret[j] = ft_strsub(s, i, word_len(s + i));
			j++;
			i += word_len(s + i);
		}
		else
			i++;
	}
	ret[j] = 0;
	return (ret);
}
