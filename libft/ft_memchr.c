/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:39:34 by akretov           #+#    #+#             */
/*   Updated: 2024/05/06 19:18:36 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memchr(const void *memblock, int searchedchar, size_t size)
{
	char		searchme;
	const char	*position;

	position = memblock;
	searchme = (char)searchedchar;
	while (size > 0)
	{
		if (*position == searchme)
			return ((char *)position);
		position++;
		size--;
	}
	return (NULL);
}
