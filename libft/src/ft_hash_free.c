/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hash_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 09:23:20 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/23 10:44:54 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hash.h>

void	ft_hash_free(t_lst **hash_t)
{
	int	i;

	i = -1;
	while (++i < TABLE_SIZE)
	{
		if (hash_t[i])
			ft_lst_free(hash_t[i]);
	}
}
