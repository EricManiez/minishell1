/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 09:28:56 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/23 10:14:04 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lst_free_node(t_node *node)
{
	if (node->content)
		free(node->content);
	if ((node->key)[0])
		ft_strdel(&(node->key));
}
