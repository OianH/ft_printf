/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiahidal <oiahidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:55:08 by oiahidal          #+#    #+#             */
/*   Updated: 2024/05/30 17:04:41 by oiahidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_unnlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_unitoa(unsigned int n)
{
	int		i;
	char	*result;

	i = ft_unnlen(n);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	result[i--] = '\0';
	while (n)
	{
		result[i--] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
