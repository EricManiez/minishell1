/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_char_cumul.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:05:40 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/16 10:37:37 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hash.h>

size_t	ft_hash_char_cumul31(char *key, size_t table_size)
{
	size_t	hash;
	int		i;

	hash = 0;
	i = -1;
	while (key[++i])
		hash = (hash << 5) + key[i] - hash;
	return (hash % table_size);
}
