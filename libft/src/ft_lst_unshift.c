/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_unshift.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 15:55:47 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/16 18:55:49 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lst_unshift(t_lst *lst, void *content, size_t cntnt_size, char *key)
{
	t_node	*new;

	if (!lst->head)
		lst = ft_lst_init(content, cntnt_size, key);
	else
	{
		new = ft_lst_create_node(content, cntnt_size, key);
		ft_lst_link(new, lst->head);
		lst->head = new;
	}
	return (ft_lst_len(lst));
}
