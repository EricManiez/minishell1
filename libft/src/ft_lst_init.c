/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 15:42:27 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/16 15:03:12 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lst_init(void *content, size_t content_size, char *key)
{
	t_lst	*lst;

	lst = ft_lst_create();
	lst->head = ft_lst_create_node(content, content_size, key);
	lst->tail = lst->head;
	return (lst);
}
