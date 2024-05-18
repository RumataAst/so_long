/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:01:19 by akretov           #+#    #+#             */
/*   Updated: 2024/05/06 19:19:20 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*copy_str;

	i = ft_strlen(s);
	copy_str = (char *)malloc(sizeof (char) * i + 1);
	if (copy_str == NULL)
		return (0);
	ft_memcpy(copy_str, s, i);
	copy_str[i] = '\0';
	return (copy_str);
}
