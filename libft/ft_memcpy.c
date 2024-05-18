/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:45:28 by akretov           #+#    #+#             */
/*   Updated: 2024/05/06 19:19:03 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		count;
	const char	*src_1;
	char		*dest_1;

	count = 0;
	dest_1 = dest;
	src_1 = src;
	if (!dest && !src)
		return (NULL);
	while (count < n)
	{
		dest_1[count] = src_1[count];
		count++;
	}
	return (dest);
}
