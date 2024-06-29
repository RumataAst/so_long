/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:01:22 by akretov           #+#    #+#             */
/*   Updated: 2024/06/05 18:45:22 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

// static size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	while ((char)c != *s)
// 	{
// 		if (!*s)
// 			return (NULL);
// 		s++;
// 	}
// 	return ((char *)s);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*temp;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (s1 == 0 || s2 == 0)
// 		return (NULL);
// 	temp = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (temp != 0)
// 	{
// 		while (s1[i])
// 		{
// 			temp[i] = (char)s1[i];
// 			i++;
// 		}
// 		while (s2[j])
// 		{
// 			temp[i] = (char)s2[j];
// 			i++;
// 			j++;
// 		}
// 		temp[i] = '\0';
// 	}
// 	return (temp);
// }

// static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	if (size != 0)
// 	{
// 		while (src [i] && i < (size - 1))
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (ft_strlen(src));
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*temp;
// 	size_t	s_len;
// 	size_t	finish;

// 	if (!s)
// 		return (0);
// 	s_len = ft_strlen(s);
// 	finish = 0;
// 	if (start < s_len)
// 		finish = s_len - start;
// 	if (finish > len)
// 		finish = len;
// 	temp = (char *)malloc(sizeof(char) * (finish + 1));
// 	if (!temp)
// 		return (0);
// 	ft_strlcpy(temp, s + start, finish + 1);
// 	return (temp);
// }
