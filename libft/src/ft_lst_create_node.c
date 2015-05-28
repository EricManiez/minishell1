/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_create_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 14:01:12 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/16 14:58:47 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lst_create_node(void *content, size_t content_size, char *key)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->content = content;
	node->content_size = content_size;
	if (key)
		node->key = ft_strdup(key);
	else
		node->key = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
