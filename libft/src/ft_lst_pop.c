/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 14:27:00 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 14:42:12 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_node	*ft_lst_pop(t_lst *list)
{
	t_node	*tr;

	tr = list->tail;
	list->tail = tr->prev;
	list->tail->next = 0;
	return (tr);
}
