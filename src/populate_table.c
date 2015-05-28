/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 14:46:30 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/16 19:00:31 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	populate_table(char *dir, char *key, t_lst **table)
{
	size_t	hash;
	char	*path;

	path = ft_retprintf("%s/%s", dir, key);
	hash = ft_hash_char_cumul31(key, TABLE_SIZE);
	if (!table[hash])
		table[hash] = ft_lst_init(path, ft_strlen(dir) + ft_strlen(key), key);
	else
		ft_lst_unshift(table[hash], path, ft_strlen(dir) + ft_strlen(key), key);
}
