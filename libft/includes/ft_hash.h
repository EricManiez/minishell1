/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:31:53 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/23 10:20:40 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_H
# define FT_HASH_H

# define TABLE_SIZE 10000

# include "libft.h"

size_t	ft_hash_char_cumul(char *key, size_t table_size);

size_t	ft_hash_char_cumul31(char *key, size_t table_size);

void	ft_hash_free(t_lst **hash_t);

#endif
