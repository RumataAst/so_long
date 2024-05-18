/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:59:26 by akretov           #+#    #+#             */
/*   Updated: 2024/05/06 19:18:20 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

long	ft_size(int n)
{
	long	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*number;
	long	size;
	long	num;

	num = n;
	size = ft_size(n);
	number = (char *)malloc(size + 1);
	if (!number)
		return (0);
	if (n < 0)
	{
		num *= -1;
		number[0] = '-';
	}
	number[size--] = '\0';
	while (num > 0)
	{
		number[size--] = num % 10 + '0';
		num /= 10;
	}
	if (n == 0)
		number[size] = '0';
	return (number);
}
