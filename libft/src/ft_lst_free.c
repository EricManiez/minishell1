/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 09:27:02 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/23 10:20:47 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lst_free(t_lst *lst)
{
	t_node	*node;

	node = lst->head;
	while (node)
	{
		ft_lst_free_node(node);
		node = node->next;
	}
}
