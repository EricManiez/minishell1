/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_toppop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 14:32:23 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 14:38:24 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_node	*ft_lst_toppop(t_lst *list)
{
	t_node	*tr;

	tr = list->head;
	list->head = tr->next;
	list->head->prev = 0;
	return (tr);
}
