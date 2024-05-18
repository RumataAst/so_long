/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:19:01 by akretov           #+#    #+#             */
/*   Updated: 2023/11/12 14:28:27 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		count;

	node = lst;
	count = 0;
	while (node != NULL)
	{
		count++;
		node = node -> next;
	}
	return (count);
}
