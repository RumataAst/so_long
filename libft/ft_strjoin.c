/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:02:12 by akretov           #+#    #+#             */
/*   Updated: 2024/05/06 19:19:26 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result != 0)
	{
		while (s1[i])
		{
			result[i] = (char)s1[i];
			i++;
		}
		while (s2[j])
		{
			result[i] = (char)s2[j];
			i++;
			j++;
		}
		result[i] = '\0';
	}
	return (result);
}
